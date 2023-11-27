#include<iostream>

// B   B2
//  \ /
//   D

struct Base {
    virtual void f() { std::cout << 1; }
};

struct Base2 {
    void f() { std::cout << 2; }
};

struct Derived: Base, Base2 {
    void f() override { std::cout << 3; }
};

int main() {
    Derived d;
    Base& b = d;
    b.f();
}
