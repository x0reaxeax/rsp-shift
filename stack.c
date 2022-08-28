const char txt[] = "supa hax c sp shift test\n";                // 0x0000000000402010

__attribute__((naked)) void function(void) {                    // 0x401100
    __asm__ volatile (
        ".byte 0x18, 0x11, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00;" // 0x0000000000401100:  => 0x401118
        "movl $1,  %edi;"                                       // 0x0000000000401118:  bf 01 00 00 00      mov edi, 0x1
        "movl $1,  %eax;"                                       // 0x000000000040111d:  b8 01 00 00 00      mov eax,0x1
        "movl $25, %edx;"                                       // 0x0000000000401122:  ba 19 00 00 00      mov edx,0x19
        "movl $0x402010, %esi;"                                 // 0x0000000000401127:  be 19 20 40 00      mov esi,0x402010
        "syscall;"                                              // 0x000000000040112c:  0f 05               syscall
        "movl $0x3c, %eax;"                                     // 0x000000000040112e:  b8 3c 00 00 00      mov eax,0x3c
        "syscall;"                                              // 0x0000000000401133:  0f 05               syscall
    );
}

void main(void) {
    unsigned char x[0x7FFFFFBFCF30];    // 48 b8 30 ce bf ff ff 7f 00 00    movabs  rax,0x0x7fffffbfceb0
                                        // 48 29 c4                         sub     rsp,rax
                                        // 0x7fffffffdfc8 - 0x7fffffbfceb0  =>      0x401118    <function + 0x8>
    asm("ret");                         // c3                               ret
}
