/**
 * This is a minimalist c program demonstrating c language features,
 * such as types (`long`), functions, strings, comments, and macros,
 * and control flow.
 * 
 * This program can be built and ran without any external dependencies
 * (such as cstdlib) on linux. I also created an accompanying shell script
 * to break down how to build such a program.
 * 
 * This type of program is only possible on linux due to the stable syscall
 * ABI. MacOS and Windows programs rely on external dependencies like
 * `libSystem.dylib` or `kernel32.dll` in order to function properly across
 * Operating System versions.
 */

#include <asm/unistd_64.h>
#define STDOUT  1
                              //  asm("movq %%"  #reg ", %0" : "=r"(var))
#define REGISTER_TO_VAR(reg, var) asm("mov %0, " #reg        : "=r"(var)) 
#define SYSCALL asm("svc #0");  // syscall

void syscall3(long num, long arg1, long arg2, long arg3) {
    register long n  asm("x8") =  num; // rax
    register long a1 asm("x0") = arg1; // rdi
    register long a2 asm("x1") = arg2; // rsi
    register long a3 asm("x2") = arg3; // rdx
    SYSCALL;
}

void syscall1(long num, long arg) {
    register long n asm("x8")  =  num; // rax
    register long a asm("x0")  =  arg; // rdi
    SYSCALL;
}

void _start(void) {
    long *sp;
    REGISTER_TO_VAR(sp, sp); // rsp, sp
    long argc = sp[0];
    char **argv = (char **)&sp[1];
    char **envp = &argv[argc + 1];

    if (argc > 1) {
        const char *cmd = argv[1];
        const char **args = (const char **)&argv[1];
        syscall3(__NR_execve, (long)cmd, (long)args, (long)envp);
    } else {
        const char usage[] = "Usage: small </path/to/command> [args...]\n";
        syscall3(__NR_write, STDOUT, (long)usage, (sizeof(usage) - 1));
        syscall1(__NR_exit, 0);
    }
}
