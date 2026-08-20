# C Programming Codes

A collection of C programming exercises and practice problems covering arrays, structures, bit manipulation, and linked lists.

## Contents

| File | Description |
|------|--------------|
| `Extra_class_problem.c` | Sparse matrix operations: reads an `m x n` matrix, checks whether it qualifies as a sparse matrix, and computes its transpose two ways — using a standard 2D array and using a compact `(row, col, value)` structure representation. |
| `Program_2.c` | Reads an integer and prints its 32-bit binary representation, then breaks it down byte-by-byte showing each byte's decimal and binary value. |
| `Program_3.c` | Implements a singly linked list: builds a list from user-input values (`create`) and prints its contents (`display`). |
| `Program_4.c` | Provides a menu-driven singly linked list with insertion at the beginning, at the end, or at a selected 1-based position, plus list display and memory cleanup. |

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
gcc Program_4.c -o program4
./program4
```

```bash
gcc Extra_class_problem.c -o extra_class_problem
./extra_class_problem
```

On Windows with MinGW, use `gcc file.c -o file.exe` and run the resulting executable, for example:

```powershell
gcc Program_4.c -o Program_4.exe
.\Program_4.exe
```

In VS Code, open the C file you want to run and use the configured **C/C++: gcc.exe build active file** task.

## Notes

- These programs were written as academic practice exercises in C.
- Compiled binaries may be present in the workspace, but they are not required. Compile the source files yourself when needed, as described above.

