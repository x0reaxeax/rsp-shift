# rsp-shift

Demonstration of willy nilly changing stack pointer with C.  
Mind that the `__asm__` block in `function()` doesn't play any significant part here and is only used to ease the demo.

### Few requirements:
 * ASLR needs to be off (`$ cat /proc/sys/kernel/randomize_va_space` outputs `0`)
 * Compiling and running `rsp-test.c` outputs `0x7fffffffdfc8`
 
### Compiling:
**Test:** `gcc -no-pie -O2 rsp-test.c -o test`  (works with gcc and clang)  
**Demo:** `clang -no-pie stack.c`               (clang only)

```
$ ./a.out
supa hax c sp shift test
```
