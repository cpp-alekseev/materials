#include <cstdio>
#include <cstdlib>

int main() {
    int *x = (int*)malloc(sizeof(int)); // void* malloc(size_t)
    *x = 5;
    free(x);

    int size = 4;
    int *arr = (int *) malloc(size * sizeof(int));
    printf("arr: %lx\n", arr);
    for (int i = 0; i < size; ++i) {
        arr[i] = i * i; // *(arr + i) = i * i
    }

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = (int *) realloc(arr, 2*size*sizeof(int));
    printf("arr: %lx\n", arr);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Now new 4 items can be used too

    free(arr);

    return 0;
}
