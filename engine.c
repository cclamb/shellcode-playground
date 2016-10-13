/**
 * This is a simple shellcode tester. This tester requires
 * you to insert your shellcode into the shellcode buffer
 * for later execution.
 **/

#define EXIT_OK 0

// This is the shellcode buffer. Insert shellcode into the
// code variable here, for execution later.
char shellcode[] = "Insert your shellcode here";

int main(int argc, char *argv[]) {
  //exeshell is a function pointer
  int (*code_to_execute)();

  // Here, we set code_to_execute equal to our shellcode.
  // We will execute this shellcode shortyly.
  code_to_execute = (int (*)()) shellcode;

  // Execute shellcode; we call the function pointer.
  int retval = (int)(*code_to_execute)();
  return EXIT_OK;
}

