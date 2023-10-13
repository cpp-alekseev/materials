#include <stdio.h>

// Basic IO using C library
int main() {
    printf("Hello World!\n");

    int a;
    unsigned int b;
    scanf("%d %u", &a, &b);

    int x = 5 / 0;

    printf("Simple int: %d\n", a);
    printf("unsigned: %u, oct: %o, hex: %x\n", b, b, b);

    return 0;
}
