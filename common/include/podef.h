/*
    Polonium Operating System
    Licensed under BSD Clause 3

File:
    common/include/podef.h: Polonium basic definitions like ASM or NORETURN

Authors:
    unsignedinteger16
*/

#ifndef PODEF_H
#define PODEF_H 1

#include <stddef.h>
#include <stdint.h>

#define UNUSED __attribute__((unused))
#define NORETURN __attribute__((noreturn))
#define ASM __asm__ __volatile__

typedef void VOID, *PVOID;

typedef int8_t SBYTE, *PSBYTE;
typedef uint8_t BYTE, *PBYTE;

typedef int16_t WORD, *PWORD;
typedef uint16_t UWORD, *PUWORD;

typedef int32_t DWORD, *PDWORD;
typedef uint32_t UDWORD, *PUDWORD;

typedef int64_t QWORD, *PQWORD;
typedef uint64_t UQWORD, *PUQWORD;

typedef size_t SIZE, *PSIZE;

typedef int INTEGER, *PINTEGER;
typedef unsigned int UNSIGNEDINTEGER, UINTEGER, *PUNSIGNEDINTEGER, *PUINTEGER;

typedef char CHAR, *PCHAR;
typedef PCHAR STR, *PSTR;

typedef PDWORD WCHAR, *PWCHAR;
typedef PWCHAR WSTR, *PWSTR;

#endif