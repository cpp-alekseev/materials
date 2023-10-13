#include <iostream>

int main() {
    int *x = new int; // malloc(sizeof(int))
    *x = 5;
    delete x;

    int size = 4;
    int *arr = new int[size];  // malloc(sizeof(int) * size)
    std::cout << std::hex << arr << std::endl;
    for (int i = 0; i < size; ++i) {
        arr[i] = i * i;
    }


    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // No realloc, use containers instead!
    delete[] arr;
}
