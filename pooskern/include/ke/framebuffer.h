/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/ke/framebuffer.h: Polonium Kernel x86_64 definition of framebuffer

Authors:
    unsignedinteger16
*/

#ifndef KE_FRAMEBUFFER
#define KE_FRAMEBUFFER 1

#include <podef.h>
#include <limine.h>

typedef struct limine_framebuffer FRAMEBUFFER, *PFRAMEBUFFER;
typedef struct {
    PFRAMEBUFFER* Data;
    SIZE Count;
} FRAMEBUFFER_LIST;

FRAMEBUFFER_LIST KeFetchFramebuffers();

#endif