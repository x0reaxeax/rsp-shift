#include <stdio.h>

int main(void) {
    unsigned long long rsp = 0;     // sub rsp, 0x8
    __asm__ volatile (
        "mov %%rsp, %0;"
        : "=r" (rsp) ::
    );
    printf("0x%02llx\n", rsp + 8);
    return 0;
}
