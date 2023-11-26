#include<iostream>

struct A {
    int x;
};

struct B {
    int y;
};

// С -> [A][B][members]
struct C : public A, public B {
    int z;
};

int main() {
    C c;
    B* b = static_cast<B*>(c);
    A* a = static_cast<A*>(c);
    std::cout << "absolute: " <<  &c << ' ' << a << ' ' << b << '\n';
}
