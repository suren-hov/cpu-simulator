# CPU Simulator

## Overview

This project is a terminal-based CPU simulator that executes a subset of assembly instructions. It helps visualize instruction execution and understand the interactions between different CPU components.

## Features

- **Basic CPU Components**: Implements components such as ALU, registers, and control unit.
- **Instruction Cycles**: Simulates instruction fetch, decode, and execute cycles.
- **Instruction Subset**: Executes a subset of assembly instructions:
  - `ADD`: Add two registers and store the result in the first register.
  - `SUB`: Subtract one register from another and store the result in the first register.
  - `MOV`: Move data from one register to another.
  - `LOAD`: Load data from memory into a register.
  - `STORE`: Store data from a register into memory.
  - `START`: Set the Working Status Register (WSR) to 1, initialize CPU, and reset memory.
  - `EXIT`: If WSR value is 1, set WSR to 0, initialize CPU, and reset memory; if WSR value is 0, terminate the general process.
  - `DISC`: Discard the effect of the previous N instructions (default is 1 if N is not specified).
  - `LAYO`: Display all register values and memory contents.
- **Registers and Memory**: Uses 8 registers, with a specific-purpose register called WSR, and includes an Instruction Pointer (IP) that counts executed instructions.
- **User Inputs**: Handles user inputs for custom assembly instructions.
- **State Saving**: Saves the CPU state after each instruction execution in a file.

## Project Structure

### `main.c`

Handles the main execution loop and instruction parsing.

### `basic.c`

Implements the core CPU functionalities, such as instruction execution, CPU state initialization, and state saving.

### `header.h`

Contains the definitions and function prototypes for the CPU components and instructions.

## Compilation and Execution

### Compilation

To compile the project, use the following command:

```sh
gcc -o cpu_simulator main.c basic.c assembly.c


Feel free to adjust the content to better suit your needs or to include additional details about your project.