#include "tableAssembly.h"
#include <stdio.h>
#include <string.h>

int ptrA = 0;

void insertInstruction(struct Instruction element, struct Instruction * table) {
    table[ptrA++] = element;
}

void upDateJMFInstruction(struct Instruction * table) {
  for (int i = ptrA; i >= 0; i--) {
    if (strcmp(table[i].command, "JMF") == 0 && table[i].val2 == -1) {
      table[i].val2 = ptrA;
      break;
    }
  }
}

void upDateJMPInstruction(struct Instruction * table) {
  for (int i = ptrA; i >= 0; i--) {
    if (strcmp(table[i].command, "JMP") == 0) {
      table[i].val1 = ptrA;
    }
  }
}

void print_instructions(struct Instruction * table) {
  printf("Table of Assembly: \n");
  for (int i = 0;i<ptrA; i++) {
    printf("%s %d %d %d\n", table[i].command, table[i].val1, table[i].val2, table[i].val3);
  }
  printf("\n");
}