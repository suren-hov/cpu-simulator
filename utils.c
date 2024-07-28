#include "header.h"

void printError(const char *errorMsg) {
    printf(RED "Error: %s\n" RESET, errorMsg);
}

void logError(const char *errorMsg) {
    FILE *errorFile = fopen("error_log.txt", "a");
    if (errorFile != NULL) {
        fprintf(errorFile, "Error: %s\n", errorMsg);
        fclose(errorFile);
    } else {
        printf("Error opening error log file!\n");
    }
}

void debugger(CPU *cpu) {
    char command[10];

    while (1) {
        printf("Debugger> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline character

        if (strcmp(command, "step") == 0) {
            printf("Stepping through the next instruction...\n");
            return;
        } else if (strcmp(command, "state") == 0) {
            printCPUState(cpu);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting debugger...\n");
            exit(0);
        } else {
            printf("Unknown debugger command: %s\n", command);
        }
    }
}