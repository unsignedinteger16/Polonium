/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/src/ke/framebuffer.c: Polonium Kernel x86_64 implementation of framebuffer fetching

Authors:
    unsignedinteger16
*/

#include <ke/framebuffer.h>

FRAMEBUFFER_LIST KeFetchFramebuffers() {
    __attribute__((used, section(".limine_requests")))
    static volatile struct limine_framebuffer_request FramebufferRequest = {
        .id = LIMINE_FRAMEBUFFER_REQUEST,
        .revision = 0
    };

    return (FRAMEBUFFER_LIST){
        .Data = FramebufferRequest.response->framebuffers,
        .Count = FramebufferRequest.response->framebuffer_count,
    };
}