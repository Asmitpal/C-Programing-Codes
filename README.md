# C Programming Codes

This workspace contains a set of C practice programs covering queues, linked lists, binary representation, and sparse matrix operations.

## Programs Included

| File | Description |
|------|-------------|
| `Circulae_Queue.c` | Circular queue implementation with enqueue, dequeue, peek, display, and menu-driven operations. |
| `linear_Queue.c` | Linear queue implementation using a simple array-based queue with enqueue, dequeue, and display. |
| `Program_2.c` | Reads an integer and prints its 32-bit binary form, along with each byte's decimal and binary representation. |
| `Program_3.c` | Creates a singly linked list from user input and displays the list. |
| `Program_4.c` | Menu-driven singly linked list that supports insertion at the beginning, end, or a specified position. |
| `Program_5.c` | Linked list program that allows insertion and deletion operations at the beginning or at a given position. |
| `Doubled_linked_list.c` | Menu-driven doubly linked list with insertion and deletion at the beginning, end, or a specified position, plus forward and backward display. |
| `Extra_class_problem.c` | Sparse matrix program that checks whether a matrix is sparse, displays it, and computes transpose using both a 2D matrix and a compact sparse structure. |

## Requirements

- GCC compiler (MinGW on Windows or any standard C compiler on Linux/macOS)
- VS Code C/C++ extension if using the editor build task

## Building and Running

Each file is a standalone C program. Compile them individually as follows:

```bash
gcc Circulae_Queue.c -o circular_queue
./circular_queue
```

```bash
gcc linear_Queue.c -o linear_queue
./linear_queue
```

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
gcc Program_5.c -o program5
./program5
```

```bash
gcc Doubled_linked_list.c -o doubled_linked_list
./doubled_linked_list
```

```bash
gcc Extra_class_problem.c -o extra_class_problem
./extra_class_problem
```

On Windows with MinGW, the same commands use `.exe` output files:

```powershell
gcc Program_4.c -o Program_4.exe
.\Program_4.exe
```

In VS Code, open any source file and use the configured build task: `C/C++: gcc.exe build active file`.

## Notes

- These are academic C programming exercises designed for practice and learning.
- Each source file is independent and can be compiled and run separately.
- The workspace may also contain compiled `.exe` files generated during testing; they are not required for the source code to work.

