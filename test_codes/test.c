#include <stdio.h>
#include <stdint.h>

int a = 7, b = 10;

int sum(int numA, int numB) {
    return numA + numB;
}

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

uint8_t test_signNum(uint8_t n) {
    return n;
}

int main() {
    int val = sum(a, b);

    const char* s1 = "A", *s2 = "ABC", *s3 = "ABCDEF";
    int num1 = 100;

    printf("%-5s,  %-5s,  %-5s\n", s1, s2, s3);
    printf("%.5s,  %.5s,  %.5s\n", s1, s2, s3);
    printf("%#.5x\n", num1);

    printf("%lu\n", (long unsigned)sizeof(regs)/sizeof(char*));
    printf("%u\n", test_signNum(-1));
    return 0;
}