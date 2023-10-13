#include <cstdio>
#include <cstring>
#include <climits>

int main() {
    int a[4] = {1, 2, 3, 4};
    int b[4];

    printf("memcpy\n");
    printf("sizeof(a): %d\n", sizeof(a));
    memcpy(b, a, 4 * sizeof(int));
    for (int i = 0; i < 4; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // Memove works correctly when ranges are overlapped
    printf("memmove\n");
    memmove(b + 1, b, 3*sizeof(int)); // &b[1] == b + 1
    for (int i = 0; i < 4; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    memset(b, 0, 4 * sizeof(int));
    // how to make it -1
    printf("memset\n");
    for (int i = 0; i < 4; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    b[0] = 10;

    int* middle = b + 2;
    for (int i = -2; i < 2; ++i) {
        printf("%d ", middle[i]); // *(middle + i)
    }
    printf("\n");

    int (*(*ptr)[5])[10];
    ptr[0][0];

    return 0;
}
