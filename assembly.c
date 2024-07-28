
#include "header.h"

void mov(CPU *cpu, int reg, int value) {
    cpu->registers[reg] = value;
    cpu->IP++;
}

void add(CPU *cpu, int reg1, int reg2, int reg3) {
    cpu->registers[reg1] = cpu->registers[reg2] + cpu->registers[reg3];
    cpu->IP++;
}

void sub(CPU *cpu, int reg1, int reg2, int reg3) {
    cpu->registers[reg1] = cpu->registers[reg2] - cpu->registers[reg3];
    cpu->IP++;
}

void layo(CPU *cpu) {
    printCPUState(cpu);
}


void load(CPU *cpu, int reg, int address) {
    if(address < 0 || address >= MEMORY_SIZE) {
        printf("Invalid memory address: %d\n", address);
        return;
    }
    cpu->registers[reg] = cpu->memory[address];
    cpu->IP++;
}

void store(CPU *cpu, int reg, int address) {
    if(address < 0 || address >= MEMORY_SIZE) {
        printf("Invalid memory address: %d\n", address);
        return;
    }
    cpu->memory[address] = cpu->registers[reg];
    cpu->IP++;
}

void disc(CPU *cpu, int n) {
    cpu->IP -= n;
    if(cpu->IP < 0) cpu->IP = 0;
}

void push(CPU *cpu, int value) {
    if (cpu->SP >= 0) {
        cpu->stack[cpu->SP--] = value;
        cpu->IP++;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(CPU *cpu) {
    if (cpu->SP < STACK_SIZE - 1) {
        cpu->IP++;
        return cpu->stack[++cpu->SP];
    } else {
        printf("Stack Underflow\n");
        return -1;  // Indicating stack underflow
    }
}