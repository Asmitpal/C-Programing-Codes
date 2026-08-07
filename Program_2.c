#include <stdio.h>

int main() {
  int num, i, j, byte_val, bit;

  // Input integer from user
  printf("Enter an integer: ");
  scanf("%d", &num);

  // 1. Print the total 32-bit binary representation of the integer
  printf("Total Binary Value (32-bit):\n");
  for (i = 31; i >= 0; i--) {
    bit = (num >> i) & 1;
    printf("%d", bit);

    // Print a space every 8 bits (1 byte) for clarity
    if (i % 8 == 0) {
      printf(" ");
    }
  }
  printf("\n");

  // 2. Breakdown byte by byte
  printf("Individual Byte Blocks:\n");
  for (i = 0; i < sizeof(int); i++) {

    // Extract current 8-bit byte value
    byte_val = (num >> (i * 8)) & 255;

    printf("Byte %d --> Decimal: %3d [Binary: ", i + 1, byte_val);

    // Print binary for this individual byte
    for (j = 7; j >= 0; j--) {
      bit = (byte_val >> j) & 1;
      printf("%d", bit);
    
    }
    printf("]\n");
  }

  return 0;
}