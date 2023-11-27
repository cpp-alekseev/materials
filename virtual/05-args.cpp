#include<iostream>

struct Base {
    virtual void f(int x = 1) { std::cout << x*3; }
};

struct Derived: Base {
    void f(int x = 2) override { std::cout << x*5; }
};

int main() {
    Derived d;
    d.f();
    Base& b = d;
    b.f(); // 10 or 3 or CE?
}
