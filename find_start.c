#include <stdio.h>

unsigned long find_start(void) {
  __asm__("movl %esp, %eax");
}

int main() {
  printf("0x%lx\n", find_start());
}
