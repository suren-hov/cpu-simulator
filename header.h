#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define MEMORY_SIZE 256
#define NUM_REGISTERS 8
#define STACK_SIZE 64
#define HEAP_SIZE 128

typedef struct {
    int registers[NUM_REGISTERS];
    int memory[MEMORY_SIZE];
    int stack[STACK_SIZE];
    int heap[HEAP_SIZE];
    int WSR;  // Working Status Register
    int IP;   // Instruction Pointer
    int SP;   // Stack Pointer
} CPU;


void initializeCPU(CPU*);
void printCPUState(CPU*);
void start(CPU*);
void exitCPU(CPU*);
void mov(CPU*, int, int);
void add(CPU*, int, int, int);
void sub(CPU*, int, int, int);
void layo(CPU*);
void load(CPU*, int, int);
void store(CPU*, int, int);
void disc(CPU*, int);
void push(CPU*, int);
int pop(CPU*);
void delay(int);