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

int main(int argc, char *argv[], char *envp[]) {
    if (argc > 1) {
        const char* cmd = argv[1];
        const char** args = (const char**)&(argv[1]);
        return (int)syscall3(__NR_execve, (long)cmd, (long)args, (long)envp);
    } else {
        const char usage[] = "Usage: small </path/to/command> [args...]\n";
        syscall3(__NR_write, STDOUT, (long)usage, (sizeof(usage) - 1));
        return 0;
    }
}
