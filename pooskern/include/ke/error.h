/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/ke/error.h: Polonium Kernel definitions of error handling

Authors:
    unsignedinteger16
*/

#include <podef.h>
#include <ke/terminal.h>

void KeSetErrorTerminal(PTERMINAL Terminal);
NORETURN void KeFailure(STR FailureReason, UDWORD Number1, UDWORD Number2, UDWORD Number3, UDWORD Number4);