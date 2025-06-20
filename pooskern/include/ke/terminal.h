/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/ke/terminal.h: Polonium Kernel x86_64 definition of terminal

Authors:
    unsignedinteger16
*/

#ifndef KE_TERMINAL
#define KE_TERMINAL 1

#include <podef.h>
#include <ke/framebuffer.h>

typedef PVOID PTERMINAL;

PTERMINAL KeCreateTerminalFromFramebuffer(PFRAMEBUFFER Framebuffer);
void KeWriteToTerminalA(PTERMINAL Terminal, STR String);
void KeWriteToTerminalCappedA(PTERMINAL Terminal, STR String, SIZE Cap);

#endif