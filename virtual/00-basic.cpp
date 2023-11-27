#include<iostream>

struct Base {
    Base() {

    }
    virtual void f() const { std::cout << 1; }
};

struct Derived : Base {
    void f() const override { std::cout << 2; }
};

struct Derived2 : Base {
    void f() const override { std::cout << 3; }
};

void foo(Base* b) {
    b->f();
}

int main() {
    Derived d1;
    Derived2 d2;
    foo(&d1);
    foo(&d2);
}
