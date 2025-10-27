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
#include "syscall.h"
#define  STDOUT 1

void main(register long* sp) {
    long argc = sp[0];
    char** argv = (char**)&(sp[1]);
    char** envp = &(argv[argc + 1]);
    if (argc > 1) {
        const char* cmd = argv[1];
        const char** args = (const char**)&(argv[1]);
        long r = syscall3(__NR_execve, (long)cmd, (long)args, (long)envp);
        if (r < 0) {
            syscall1(__NR_exit, (-r & 0xff));
        }
    } else {
        const char usage[] = "Usage: small </path/to/command> [args...]\n";
        syscall3(__NR_write, STDOUT, (long)usage, (sizeof(usage) - 1));
        syscall1(__NR_exit, 0);
    }
}
