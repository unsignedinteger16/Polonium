/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/src/ke/init.c: Polonium Kernel entry point

Authors:
    unsignedinteger16
*/

#include <podef.h>
#include <limine.h>
#include <ke/cpu.h>
#include <ke/framebuffer.h>
#include <ke/terminal.h>
#include <rtl/printf.h>

__attribute__((used, section(".limine_requests")))
static volatile LIMINE_BASE_REVISION(3);

__attribute__((used, section(".limine_requests_start")))
static volatile LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile LIMINE_REQUESTS_END_MARKER;

NORETURN void KiSystemStartup() {
    FRAMEBUFFER_LIST FramebufferList = KeFetchFramebuffers();
    for(SIZE i = 0; i < FramebufferList.Count; i++) {
        PTERMINAL Terminal = KeCreateTerminalFromFramebuffer(FramebufferList.Data[i]);
        KeWriteToTerminalA(Terminal, "Polonium Operating System (BUILD: " GIT_BRANCH_NAME "-" GIT_COMMIT_SHORT ")\n");
        RtlPrintfToTerminal(Terminal, "Hello from \"kprintf\". %%s = %s, %%u = %u, nullptr = %s", "Hello", 24, NULL);
    }
    KeHaltCpu();
}