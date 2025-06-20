/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/src/ke/x86_64/cpu.c: Polonium Kernel x86_64 implementation of CPU operations

Authors:
    unsignedinteger16
*/

#include <ke/cpu.h>
#include <podef.h>

void KeHaltCpu() {
    for(;;) ASM("hlt");
}