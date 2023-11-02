#include <iostream>
#include <cstddef>

void inc(size_t& x) {
    ++x;
}

int main() {
    int x = 0;
    inc(x);
    std::cout << x;
}
