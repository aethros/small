#include <asm/unistd_64.h>
#include "syscall.h"
#include "asm.h"

int main(int argc, char* argv[], char* envp[]);

/**
 * _start with "asm volatile" macro is necesarry to prevent the stack
 * from becoming clobbered by the compiler. Jump directly to main.
 */
void _start(void) {
    INIT_AND_JUMP(_cstart_main);
}

void _cstart_main(register long* sp) {
    long argc = sp[0];
    char** argv = (char**)&(sp[1]);
    char** envp = &(argv[argc + 1]);
    int r = main((int)argc, argv, envp);
    syscall1(__NR_exit, (r & 0xff));
}

long syscall0(long num) {
    register long n NUM_REG  =  num;
    SYSCALL;
    register long r RET_REG;        
    return r;
}

long syscall1(long num, long arg) {
    register long n NUM_REG  =  num;
    register long a  A1_REG  =  arg;
    SYSCALL;
    register long r RET_REG;        
    return r;
}

long syscall2(long num, long arg1, long arg2) {
    register long n NUM_REG =  num;
    register long a1 A1_REG = arg1;
    register long a2 A2_REG = arg2;
    SYSCALL;
    register long r RET_REG;       
    return r;
}

long syscall3(long num, long arg1, long arg2, long arg3) {
    register long n NUM_REG =  num;
    register long a1 A1_REG = arg1;
    register long a2 A2_REG = arg2;
    register long a3 A3_REG = arg3;
    SYSCALL;
    register long r RET_REG;       
    return r;
}

long syscall4(long num, long arg1, long arg2, long arg3, long arg4) {
    register long n NUM_REG =  num;
    register long a1 A1_REG = arg1;
    register long a2 A2_REG = arg2;
    register long a3 A3_REG = arg3;
    register long a4 A4_REG = arg4;
    SYSCALL;
    register long r RET_REG;       
    return r;
}

long syscall5(long num, long arg1, long arg2, long arg3, long arg4, long arg5) {
    register long n NUM_REG =  num;
    register long a1 A1_REG = arg1;
    register long a2 A2_REG = arg2;
    register long a3 A3_REG = arg3;
    register long a4 A4_REG = arg4;
    register long a5 A5_REG = arg5;
    SYSCALL;
    register long r RET_REG;       
    return r;
}

long syscall6(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6) {
    register long n NUM_REG =  num;
    register long a1 A1_REG = arg1;
    register long a2 A2_REG = arg2;
    register long a3 A3_REG = arg3;
    register long a4 A4_REG = arg4;
    register long a5 A5_REG = arg5;
    register long a6 A6_REG = arg6;
    SYSCALL;
    register long r RET_REG;       
    return r;
}
