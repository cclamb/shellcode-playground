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
CC=clang
ASM=exit.asm
OBJ=printer.o engine.o
SDK_HOME=SDKs
SDK=$(SDK_HOME)/iPhoneOS9.3.sdk
# SDK=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS10.0.sdk                                        
NO_ASLR_FLAGS=-Wl,-no_pie
DEBUG_FLAGS=-g

# can we use -target arm64-apple-ios? arm64-apple-darwin does work
# # Valid architectures seem to be arm64, armv7, and armv7s.
# #
# # Valid triples include:
# # arm64-apple-darwin
# # armv7-apple-darwin
# # armv7s-apple-darwin
# # arm64-apple-ios
# # armv7-apple-ios
# # armv7s-apple-ios
# #
# #       IMPORTANT: using arm64 as the target architecture will prohibit
# # the linker from creating a non-ASLR executable!
# #
# # the arm64 target is equivalent to armv8 aarch64, while the arm7* target
# # produces 32-bit code, but we can use with ASLR off.
# IOS_TARGET=-target armv7s-apple-ios -isysroot $(SDK)
# MACOS_TARGET=
#
# NOTE: We current set -D_FORTIFY_SOURCE=0 as it is enabled by default
# and will implement stack protection.
ARGS=$(IOS_TARGET) $(DEBUG_FLAGS)
IOS_TARGET=-D_FORTIFY_SOURCE=0 -fno-stack-protector -target armv7s-apple-ios -isysroot $(SDK)
MACOS_TARGET=

ARGS=$(IOS_TARGET) $(DEBUG_FLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(ARGS)

#asm: $(ASM)
#	$(CC) -o $@ -S $< $(ARGS)

main: $(OBJ)
	$(CC) -o printer printer.o $(ARGS) $(NO_ASLR_FLAGS)
	$(CC) -o engine engine.o $(ARGS) $(NO_ASLR_FLAGS)

clean:
	rm *.o printer engine 
	rm -rf *.dSYM
