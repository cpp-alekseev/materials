#include <stdio.h>

int main() {
    int c[100] = {100, 200}; // 98 elements not initialized

    int* x = c; // &c[0] -- exactly the same
    int* y = c + 1;  // &c[1] -- exactly the same

    printf("`sizeof(int)`: %ld\n", sizeof(int));
    printf("`*x`: %d\n", *x);
    printf("`*y`: %d\n", *y);
    printf("`x`: %u\n", x);
    printf("`y`: %u\n", y);

    int z = 5;
    printf("`z`: %d\n", z);
    printf("`&z`: %u\n", &z);
}
