#if defined(x86_64)
    #define JUMP_TO_MAIN asm volatile( "mov rdi, rsp\n" "call main\n" );
    #define NUM_REG asm("rax")
    #define  A1_REG asm("rdi")
    #define  A2_REG asm("rsi")
    #define  A3_REG asm("rdx")
    #define  A4_REG asm("r10")
    #define  A5_REG asm("r8")
    #define  A6_REG asm("r9")
    #define RET_REG asm("rax")
    #define SYSCALL asm volatile("syscall");
#elif defined(aarch64)
    #define JUMP_TO_MAIN asm volatile( "mov x0, sp\n" "bl main\n" );
    #define NUM_REG asm("x8")
    #define  A1_REG asm("x0")
    #define  A2_REG asm("x1")
    #define  A3_REG asm("x2")
    #define  A4_REG asm("x3")
    #define  A5_REG asm("x4")
    #define  A6_REG asm("x5")
    #define RET_REG asm("x0")
    #define SYSCALL asm volatile("svc #0");
#endif