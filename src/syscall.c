#include "syscall.h"
#define SYSCALL asm volatile("svc #0"); // syscall

/**
 * _start with "asm volatile" is necesarry to prevent the stack
 * from becoming clobbered by the compiler. Jump directly to main.
 */
void _start(void) {
    asm volatile(
        "mov x0, sp\n" // mov rdi, rsp 
        "bl main\n"    // call main
    );
}

long syscall0(long num) {
    register long n asm("x8")  =  num; // rax
    SYSCALL;
    register long r asm("x0");         // rax
    return r;
}

long syscall1(long num, long arg) {
    register long n asm("x8")  =  num; // rax
    register long a asm("x0")  =  arg; // rdi
    SYSCALL;
    register long r asm("x0");         // rax
    return r;
}

long syscall2(long num, long arg1, long arg2) {
    register long n  asm("x8") =  num; // rax
    register long a1 asm("x0") = arg1; // rdi
    register long a2 asm("x1") = arg2; // rsi
    SYSCALL;
    register long r  asm("x0");        // rax
    return r;
}

long syscall3(long num, long arg1, long arg2, long arg3) {
    register long n  asm("x8") =  num; // rax
    register long a1 asm("x0") = arg1; // rdi
    register long a2 asm("x1") = arg2; // rsi
    register long a3 asm("x2") = arg3; // rdx
    SYSCALL;
    register long r  asm("x0");        // rax
    return r;
}

long syscall4(long num, long arg1, long arg2, long arg3, long arg4) {
    register long n  asm("x8") =  num; // rax
    register long a1 asm("x0") = arg1; // rdi
    register long a2 asm("x1") = arg2; // rsi
    register long a3 asm("x2") = arg3; // rdx
    register long a4 asm("x3") = arg4; // r10
    SYSCALL;
    register long r  asm("x0");        // rax
    return r;
}

long syscall5(long num, long arg1, long arg2, long arg3, long arg4, long arg5) {
    register long n  asm("x8") =  num; // rax
    register long a1 asm("x0") = arg1; // rdi
    register long a2 asm("x1") = arg2; // rsi
    register long a3 asm("x2") = arg3; // rdx
    register long a4 asm("x3") = arg4; // r10
    register long a5 asm("x4") = arg5; // r8
    SYSCALL;
    register long r  asm("x0");        // rax
    return r;
}

long syscall6(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6) {
    register long n  asm("x8") =  num; // rax
    register long a1 asm("x0") = arg1; // rdi
    register long a2 asm("x1") = arg2; // rsi
    register long a3 asm("x2") = arg3; // rdx
    register long a4 asm("x3") = arg4; // r10
    register long a5 asm("x4") = arg5; // r8
    register long a6 asm("x5") = arg6; // r9
    SYSCALL;
    register long r  asm("x0");        // rax
    return r;
}
