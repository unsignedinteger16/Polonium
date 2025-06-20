/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/src/rtl/printf.c: Polonium implementation of printf functions

Authors:
    unsignedinteger16
*/

#include <ke/terminal.h>
#include <rtl/string.h>
#include <rtl/printf.h>
#include <stdarg.h>

STR RtlUnsignedToStringA(STR Buffer, SIZE Cap, UQWORD Integer, BYTE Base) {
    static char Characters[] = "0123456789ABCDEF";

    if(Base > sizeof(Characters)) {
        // For now not supported
        return;
    }    

    SIZE i = Cap - 2;
    Buffer[Cap-1] = '\0';

    for(; Integer && i; --i, Integer /= Base)
        Buffer[i] = Characters[Integer % Base];
    return &Buffer[i + 1];
}

void RtlPrintfToTerminal(PTERMINAL Terminal, STR Formatter, ...) {
    SIZE Readed = 0;
    SIZE NewStringOffset = 0;
    char IntegerBuffer[1024];

    va_list Arguments;
    va_start(Arguments, Formatter);
    
    while (Formatter[NewStringOffset + Readed]) {
        if(Formatter[NewStringOffset + Readed] == '%') {
            KeWriteToTerminalCappedA(Terminal, Formatter + NewStringOffset, Readed - 1);
            switch (Formatter[NewStringOffset + Readed + 1]) {
            case '%':
                KeWriteToTerminalA(Terminal, "%");
                break;
            case 's':
                KeWriteToTerminalA(Terminal, va_arg(Arguments, STR));
                break;
            case 'u':
                KeWriteToTerminalA(Terminal, RtlUnsignedToStringA(IntegerBuffer, 1024, va_arg(Arguments, UQWORD), 10));
                break;
            default:
                break;
            }
            NewStringOffset = NewStringOffset + Readed + 2;
            Readed = 0;
            continue;
        }

        Readed++;
    }
    
    KeWriteToTerminalCappedA(Terminal, Formatter + NewStringOffset, Readed);
    va_end(Arguments);
}