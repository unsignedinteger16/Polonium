/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/rtl/printf.h: Polonium definition of printf functions

Authors:
    unsignedinteger16
*/

#ifndef RTL_PRINTF
#define RTL_PRINTF 1

#include <podef.h>

STR RtlUnsignedToStringA(STR Buffer, SIZE Cap, UQWORD Integer, BYTE Base);

void RtlPrintfToTerminal(PTERMINAL Terminal, STR Formatter, ...);

#endif
