/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/ke/cpu.h: Polonium Kernel definitions of CPU operations

Authors:
    unsignedinteger16
*/

#ifndef KE_CPU_H
#define KE_CPU_H 1

#include <podef.h>

/*
    These function should work on any architecure, but have architecture specific implementation
*/

NORETURN void KeHaltCpu();

#endif