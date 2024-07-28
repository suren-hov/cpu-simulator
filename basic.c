#include "header.h"

void initializeCPU(CPU *cpu) {
    for(int i = 0; i < NUM_REGISTERS; i++) {
        cpu->registers[i] = 0;
    }
    for(int i = 0; i < MEMORY_SIZE; i++) {
        cpu->memory[i] = 0;
    }
    for(int i = 0; i < STACK_SIZE; i++) {
        cpu->stack[i] = 0;
    }
    for(int i = 0; i < HEAP_SIZE; i++) {
        cpu->heap[i] = 0;
    }
    cpu->WSR = 0;
    cpu->IP = 0;
    cpu->SP = STACK_SIZE - 1;  // Initialize stack pointer
}

void delay(int milliseconds) {
    usleep(milliseconds * 1000);
}

void start(CPU *cpu) {
    cpu->WSR = 1;
    cpu->IP++;
}

void exitCPU(CPU *cpu) {
    if(cpu->WSR == 1) {
        cpu->WSR = 0;
        cpu->IP++;
    } else {
        printf("Terminating CPU Simulator...\n");
        exit(0);
    }
}

void printCPUState(CPU *cpu) {
    printf(CYAN "CPU State:\n" RESET);
    for(int i = 0; i < NUM_REGISTERS; i++) {
        printf(GREEN "R%d: %d, " RESET, i, cpu->registers[i]);
    }
    printf(MAGENTA "WSR: %d, IP: %d, SP: %d\n" RESET, cpu->WSR, cpu->IP, cpu->SP);
    printf(YELLOW "Memory: " RESET);
    for(int i = 0; i < MEMORY_SIZE; i++) {
        if(i % 16 == 0) printf("\n");
        printf("%d ", cpu->memory[i]);
    }
    printf("\n" BLUE "Stack: " RESET);
    for(int i = STACK_SIZE - 1; i > cpu->SP; i--) {
        printf("%d ", cpu->stack[i]);
    }
    printf("\n" WHITE "Heap: " RESET);
    for(int i = 0; i < HEAP_SIZE; i++) {
        if(i % 16 == 0) printf("\n");
        printf("%d ", cpu->heap[i]);
    }
    printf("\n");
}
