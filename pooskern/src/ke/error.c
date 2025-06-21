/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/src/ke/error.c: Polonium Kernel implementation of error handling

Authors:
    unsignedinteger16
*/

#include <ke/cpu.h>
#include <ke/error.h>
#include <rtl/printf.h>

PTERMINAL KepErrorTerminal = NULL;

void KeSetErrorTerminal(PTERMINAL Terminal) {
    KepErrorTerminal = Terminal;
}

NORETURN void KeFailure(STR FailureReason, UDWORD Number1, UDWORD Number2, UDWORD Number3, UDWORD Number4) {
    if(KepErrorTerminal != NULL) 
        RtlPrintfToTerminal(KepErrorTerminal, "\033[38;2;255;0;0mERROR:\033[0m %s (0x%x, 0x%x, 0x%x, 0x%x)\n", FailureReason, Number1, Number2, Number3, Number4);
    KeHaltCpu();
}