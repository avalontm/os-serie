// ------------------------------------------------------------------------------------------------
// intr/except.h
// ------------------------------------------------------------------------------------------------

#pragma once

#include "stdlib/types.h"

// ------------------------------------------------------------------------------------------------
typedef struct Registers
{
    u64 rdi, rsi, rbp, rbx, rdx, rcx, rax;
    u64 intNum, errCode;
    u64 rip, cs, eflags, rsp, ss;
} Registers;

// ------------------------------------------------------------------------------------------------
void ExceptionDump(Registers regs);