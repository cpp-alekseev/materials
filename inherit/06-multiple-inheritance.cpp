#include <iostream>

struct Granny {
    int x;
};

struct Mom: Granny {};
struct Son: Mom, Granny {
    void foo() {
        std::cout << Granny::x << '\n';
    }
};

int main() {

}