/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/src/ke/init.c: Polonium Kernel entry point

Authors:
    unsignedinteger16
*/

#include <limine.h>
#include <ke/cpu.h>

__attribute__((used, section(".limine_requests")))
static volatile LIMINE_BASE_REVISION(3);

__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request FramebufferRequest = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

__attribute__((used, section(".limine_requests_start")))
static volatile LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile LIMINE_REQUESTS_END_MARKER;

void KiSystemStartup() {
    KeHaltCpu();
}