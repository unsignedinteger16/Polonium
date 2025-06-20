/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/src/rtl/string.c: Polonium Kernel implementation of string functions

Authors:
    unsignedinteger16
*/

#include <rtl/string.h>

PVOID memcpy(restrict PVOID Destination, const restrict PVOID Source, SIZE Lenght) {
    PBYTE* Destination2 = Destination;
    const PBYTE* Source2 = Source;

    for (SIZE i = 0; i < Lenght; ++i) Destination2[i] = Source2[i];

    return Destination;    
}

PVOID memset(PVOID Destination, INTEGER Value, SIZE Lenght) {
    PBYTE Destination2 = Destination;

    for (SIZE i = 0; i < Lenght; ++i) Destination2[i] = (BYTE)Value;
    
    return Destination;
}

PVOID memmove(PVOID Destination, const PVOID Source, SIZE Lenght) {
    PBYTE Destination2 = Destination;
    const PBYTE Source2 = Source;

    if(Source > Destination) {
        for (SIZE i = 0; i < Lenght; i++) Destination2[i] = Source2[i];        
    } else {
        for (SIZE i = Lenght; i > 0; i--) Destination2[i - 1] = Source2[i - 1];
    }
    return Destination;
}

INTEGER memcmp(const PVOID Source1, const PVOID Source2, SIZE Lenght) {
    PBYTE Source1BytePtr = Source1;
    PBYTE Source2BytePtr = Source2;

    for(SIZE i = 0; i < Lenght; i++) {
        if(Source1BytePtr[i] != Source2BytePtr[i]) return Source1BytePtr[i] < Source2BytePtr[i] ? -1 : 1;
    }

    return 0;
}

SIZE strlen(const STR String) {
    SIZE Lenght = 0;
    while (String[Lenght]) Lenght++;
    return Lenght;    
}

inline VOID RtlCopyMemory(PVOID Destination, const PVOID Source, SIZE Length) {
    memcpy(Destination, Source, Length);
}

inline VOID RtlZeroMemory(PVOID Destination, SIZE Lenght) {
    memset(Destination, 0, Lenght);
}


inline VOID RtlFillMemory(PVOID Destination, SIZE Lenght, BYTE Value) {
    memset(Destination, Value, Lenght);
}


inline VOID RtlMoveMemory(PVOID Destination, const PVOID Source, SIZE Lenght) {
    memmove(Destination, Source, Lenght);
}

// Only function that is implemented not using c standard substitude
inline SIZE RtlCompareMemory(const PVOID Source1, const PVOID Source2, SIZE Lenght) {
    const PBYTE Source1BytePtr = Source1;
    const PBYTE Source2BytePtr = Source2;
    for (SIZE i = 0; i < Lenght; ++i) {
        if(Source1BytePtr[i] != Source2BytePtr[i]) return i;
    }
    return Lenght;
}