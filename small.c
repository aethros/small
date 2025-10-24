/**
 * This is a minimalist c program demonstrating c language features,
 * such as types (`long`), functions, strings, comments, and macros.
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

#define EXIT    93
#define WRITE   64
#define STDOUT  1
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
    const char msg[] = "Hello, world!\n";
    syscall3(WRITE, STDOUT, (long)msg, (sizeof(msg) - 1));
    syscall1(EXIT, 0);
}
