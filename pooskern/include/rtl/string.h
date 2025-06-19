/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/rtl/string.h: Polonium Kernel string functions

Authors:
    unsignedinteger16
*/

#ifndef RTL_STRING
#define RTL_STRING 1

#include <podef.h>

PVOID memcpy(restrict PVOID Destination, const restrict PVOID Source, SIZE Lenght);
PVOID memset(PVOID Destination, INTEGER Value, SIZE Lenght);
PVOID memmove(PVOID Destination, const PVOID Source, SIZE Lenght);
INTEGER memcmp(const PVOID Source1, const PVOID Source2, SIZE Lenght);

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
    memove(Destination, Source, Lenght);
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

#endif