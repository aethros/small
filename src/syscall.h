#ifndef SYSCALL_H
#define SYSCALL_H

void _start(void);

long syscall0(long num);
long syscall1(long num, long arg);
long syscall2(long num, long arg1, long arg2);
long syscall3(long num, long arg1, long arg2, long arg3);
long syscall4(long num, long arg1, long arg2, long arg3, long arg4);
long syscall5(long num, long arg1, long arg2, long arg3, long arg4, long arg5);
long syscall6(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#endif /* SYSCALL_H */
