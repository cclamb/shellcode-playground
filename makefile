#
# ASM build sequence with printer.c; this takes the C file, converts to 
# ASM, compiles ASM to object code, and links the object code for 
# execution. I'm not sure if this is optimal or if all the flags are 
# required, but this works.
# 
# Compile to ASM:
# 	clang -S -o printer.s printer.c -target armv7s-apple-ios -isysroot SDKs/iPhoneOS9.3.sdk
#
# Comple to object code:
# as -o printer.o -isysroot SDKs/iPhoneOS9.3.sdk -arch armv7s printer.s
#
# link into exe:
# ld -arch armv7s -L SDKs/iPhoneOS9.3.sdk -L SDKs/iPhoneOS9.3.sdk/usr/lib -lsystem -ios_version_min 9.3 -o printer printer.o
#
# After building, need to run ldld -S <exename> to codesign
#
# NOTE: execstack will allow execution from the stack, while -fno-stack-protector will disable canaries
#
# To turn off ASLR in a shell, execute: setarch `uname -m` -R /bin/bash
#
# To turn off ASLR system-wide: echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
#
# see: http://askubuntu.com/questions/318315/how-can-i-temporarily-disable-aslr-address-space-layout-randomization
# 	https://securityetalii.es/2013/02/03/how-effective-is-aslr-on-linux-systems/
# 	
CC=gcc
ASM=exit.asm
OBJ=heap-engine.o stack-engine.o
CC_FLAGS=-fno-stack-protector -z execstack -g

%.o: %.c
	$(CC) -c -o $@ $< $(CC_FLAGS)

#asm: $(ASM)
#	$(CC) -o $@ -S $< $(ARGS)

main: $(OBJ)
	$(CC) -o heap-engine heap-engine.o $(CC_FLAGS)
	$(CC) -o stack-engine stack-engine.o $(CC_FLAGS)

clean:
	rm *.o stack-engine heap-engine 
	rm -rf *.dSYM
	rm -rf a.out

