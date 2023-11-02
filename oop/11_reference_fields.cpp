#include<iostream>

int x = 0;

struct S {
    int& r = x;
    S(int& y) {
        r = y; // x = y = r = 1
    }
};

int main() {
    int y = 1;
    S s(y);
    ++s.r; // ++x; x = 2, s.r = x = 2, y = 1
    std::cout << x << y << s.r << '\n';
} 

