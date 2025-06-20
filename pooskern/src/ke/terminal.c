/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/ke/terminal.h: Polonium Kernel x86_64 implementation of terminal

Authors:
    unsignedinteger16
*/

#include <ke/terminal.h>
#include <rtl/string.h>
#include <flanterm.h>
#include <flanterm_backends/fb.h>

typedef struct flanterm_context *PFLANTERM_TERMINAL;

PTERMINAL KeCreateTerminalFromFramebuffer(PFRAMEBUFFER Framebuffer) {
    static uint32_t DefaultForeground = 0xffffff;
    static uint32_t DefaultBackground = 0x00007f;
    
    PFLANTERM_TERMINAL terminal = flanterm_fb_init(
        NULL, NULL,
        Framebuffer->address, Framebuffer->width, Framebuffer->height,
        Framebuffer->pitch,
        Framebuffer->red_mask_size, Framebuffer->red_mask_shift,
        Framebuffer->green_mask_size, Framebuffer->green_mask_shift,
        Framebuffer->blue_mask_size, Framebuffer->blue_mask_shift,
        NULL, NULL, NULL,
        &DefaultBackground, &DefaultForeground,
        NULL, NULL,
        NULL,
        0, 0, 1, 0, 0, 0
    );  
    return terminal;
}

void KeWriteToTerminalA(PTERMINAL Terminal, STR String) {
    flanterm_write((PFLANTERM_TERMINAL)Terminal, String, strlen(String));
}

void KeWriteToTerminalCappedA(PTERMINAL Terminal, STR String, SIZE Cap) {
    SIZE StringLenght = strlen(String);
    flanterm_write((PFLANTERM_TERMINAL)Terminal, String, StringLenght < Cap ? StringLenght : Cap + 1);
}