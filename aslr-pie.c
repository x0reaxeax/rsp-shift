#include <stdio.h>
#include <sys/mman.h>

#define PAGESZ  4096

typedef unsigned long long u64;

static const char txt[] = "supa hax c sp shift test\n";

__attribute__((naked)) void function(void) {
    __asm__ volatile (
        ".rept 0xf; nop; .endr;"                                // (function + 7) + 8 bytes for 64bit address
        "movl $1,  %edi;"
        "movl $1,  %eax;"
        "movl $25, %edx;"
        "movq $0x99999999ffffffff,  %rsi;"                      // <function + 0x20>
        "syscall;"
        "movl $0x3c, %eax;"
        "syscall;"
    );
}

static inline u64 setrax(u64 rsp) {
    return (rsp - (u64) &function) - 0x10;                      // <function + 7>
}

void shift(unsigned long long off) {
    unsigned char x[setrax((u64) &off)];
    asm("ret");
}

int main(int argc) {
    if (0 != mprotect(&function - ((u64) &function % PAGESZ), PAGESZ + 64, PROT_READ | PROT_WRITE | PROT_EXEC)) {
        fprintf(stderr, "fail\n");
        return 1;
    }

    *(u64 *) (function + 0x07)  = (u64) (function + 15);
    *(u64 *) (function + 0x20)  = (u64) txt;
    shift((u64) &argc);
    return 0;
}
