/**
 * This is a simple shellcode tester. This tester requires
 * you to insert your shellcode into the shellcode buffer
 * for later execution.
 **/
#include <stdio.h>

#define EXIT_OK 0

// This is the shellcode buffer. Insert shellcode into the
// code variable here, for execution later.
char shellcode[] = "\x55\x48\x89\xe5\x31\xc0\xc7\x45\xfc\x00\x00\x00\x00\xc7\x45\xf8\x05\x00\x00\x00\x5d\xc3";

int main(int argc, char *argv[]) {
  //exeshell is a function pointer
  int (*code_to_execute)();

  // Here, we set code_to_execute equal to our shellcode.
  // We will execute this shellcode shortyly.
  printf("assigning the shellcode...\n");
  code_to_execute = (int (*)()) shellcode;

  // Execute shellcode; we call the function pointer.
  printf("attempting to execute shellcode...\n");
  int retval = (int)(*code_to_execute)();
  printf("shellcode executed, returning.\n");
  return EXIT_OK;
}

