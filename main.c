#include "header.h"

void saveState(CPU *cpu) {
    FILE *file = fopen("cpu_state.txt", "a");
    if (file == NULL) {
        printf("Error opening state file!\n");
        return;
    }

    fprintf(file, "CPU State:\n");
    for (int i = 0; i < NUM_REGISTERS; i++) {
        fprintf(file, "R%d: %d, ", i, cpu->registers[i]);
    }
    fprintf(file, "WSR: %d, IP: %d, SP: %d\n", cpu->WSR, cpu->IP, cpu->SP);
    
    fprintf(file, "Memory: ");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 16 == 0) fprintf(file, "\n");
        fprintf(file, "%d ", cpu->memory[i]);
    }
    fprintf(file, "\n");

    fprintf(file, "Stack: ");
    for (int i = STACK_SIZE - 1; i > cpu->SP; i--) {
        fprintf(file, "%d ", cpu->stack[i]);
    }
    fprintf(file, "\n");

    fprintf(file, "Heap: ");
    for (int i = 0; i < HEAP_SIZE; i++) {
        if (i % 16 == 0) fprintf(file, "\n");
        fprintf(file, "%d ", cpu->heap[i]);
    }
    fprintf(file, "\n\n");

    fclose(file);
}

void executeInstruction(CPU *cpu, char *instruction) {
    char command[10];
    int reg1, reg2, reg3, value, address, n;

    if (sscanf(instruction, "MOV R%d, %d", &reg1, &value) == 2) {
        if (reg1 >= 0 && reg1 < NUM_REGISTERS) {
            mov(cpu, reg1, value);
        } else {
            printf("Invalid register: R%d\n", reg1);
        }
    } else if (sscanf(instruction, "ADD R%d, R%d, R%d", &reg1, &reg2, &reg3) == 3) {
        if (reg1 >= 0 && reg1 < NUM_REGISTERS && reg2 >= 0 && reg2 < NUM_REGISTERS && reg3 >= 0 && reg3 < NUM_REGISTERS) {
            add(cpu, reg1, reg2, reg3);
        } else {
            printf("Invalid register(s) in ADD instruction\n");
        }
    } else if (sscanf(instruction, "SUB R%d, R%d, R%d", &reg1, &reg2, &reg3) == 3) {
        if (reg1 >= 0 && reg1 < NUM_REGISTERS && reg2 >= 0 && reg2 < NUM_REGISTERS && reg3 >= 0 && reg3 < NUM_REGISTERS) {
            sub(cpu, reg1, reg2, reg3);
        } else {
            printf("Invalid register(s) in SUB instruction\n");
        }
    } else if (sscanf(instruction, "LOAD R%d, %d", &reg1, &address) == 2) {
        if (reg1 >= 0 && reg1 < NUM_REGISTERS) {
            load(cpu, reg1, address);
        } else {
            printf("Invalid register: R%d\n", reg1);
        }
    } else if (sscanf(instruction, "STORE R%d, %d", &reg1, &address) == 2) {
        if (reg1 >= 0 && reg1 < NUM_REGISTERS) {
            store(cpu, reg1, address);
        } else {
            printf("Invalid register: R%d\n", reg1);
        }
    } else if (sscanf(instruction, "PUSH %d", &value) == 1) {
        push(cpu, value);
    } else if (sscanf(instruction, "POP R%d", &reg1) == 1) {
        if (reg1 >= 0 && reg1 < NUM_REGISTERS) {
            cpu->registers[reg1] = pop(cpu);
        } else {
            printf("Invalid register: R%d\n", reg1);
        }
    } else if (sscanf(instruction, "DISC %d", &n) == 1) {
        disc(cpu, n);
    } else if (strcmp(instruction, "START") == 0) {
        start(cpu);
    } else if (strcmp(instruction, "EXIT") == 0) {
        exitCPU(cpu);
    } else if (strcmp(instruction, "LAYO") == 0) {
        layo(cpu);
    } else {
        printf("Unknown instruction: %s\n", instruction);
    }

    saveState(cpu);                // Save state after executing each instruction
    delay(100);                    // Simulate instruction cycle time (100 ms)
}

int main() {
    CPU cpu;
    char instruction[100];

    initializeCPU(&cpu);

    printf("Enter assembly instructions (type EXIT to terminate):\n");
    printf("Supported instructions: START, EXIT, MOV, ADD, SUB, LOAD, STORE, DISC, LAYO\n");

    while(1) {
        printf("> ");
        fgets(instruction, sizeof(instruction), stdin);
        instruction[strcspn(instruction, "\n")] = 0;  // Remove newline character
        executeInstruction(&cpu, instruction);
    }

    return 0;
}

