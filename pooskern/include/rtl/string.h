/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    pooskern/include/rtl/string.h: Polonium Kernel definition of string functions

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

SIZE strlen(const STR String);

VOID RtlCopyMemory(PVOID Destination, const PVOID Source, SIZE Length);
VOID RtlZeroMemory(PVOID Destination, SIZE Lenght);
VOID RtlFillMemory(PVOID Destination, SIZE Lenght, BYTE Value);
VOID RtlMoveMemory(PVOID Destination, const PVOID Source, SIZE Lenght);
SIZE RtlCompareMemory(const PVOID Source1, const PVOID Source2, SIZE Lenght);
#endif