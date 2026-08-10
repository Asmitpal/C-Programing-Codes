# C-Programing-Codes

A collection of C programming exercises and practice problems covering arrays, structures, bit manipulation, and linked lists.

## Contents

| File | Description |
|------|--------------|
| `Extra_class_problem.c` | Sparse matrix operations: reads an `m x n` matrix, checks whether it qualifies as a sparse matrix, and computes its transpose two ways — using a standard 2D array and using a compact `(row, col, value)` structure representation. |
| `Program_2.c` | Reads an integer and prints its 32-bit binary representation, then breaks it down byte-by-byte showing each byte's decimal and binary value. |
| `Program_3.c` | Implements a singly linked list: builds a list from user-input values (`create`) and prints its contents (`display`). |

## Requirements

- A C compiler such as GCC (MinGW on Windows, or `build-essential` on Linux)
- The `.vscode/` folder contains VS Code build/debug configuration for compiling and running these files directly from the editor

## Building & Running

Each file is a standalone program. Compile and run individually, for example:

```bash
gcc Program_2.c -o program2
./program2
```

```bash
gcc Program_3.c -o program3
./program3
```

```bash
gcc Extra_class_problem.c -o extra_class_problem
./extra_class_problem
```

On Windows with MinGW, use `gcc file.c -o file.exe` and run `file.exe`.

## Notes

- These programs were written as academic practice exercises in C.
- Compiled binaries (`.exe`) are included in the repo for convenience but are typically not required — see Building & Running above to compile from source.

