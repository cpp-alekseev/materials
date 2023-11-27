#include <array>
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;

class A {
public:
    // Since RTTI is included in the virtual method table there should be at
    // least one virtual function.
    virtual ~A() = default;

    void MethodSpecificToA() {
        cout << "Method specific for A was invoked" << endl;
    }
};

class B: public A {
public:
    void MethodSpecificToB() {
        cout << "Method specific for B was invoked" << endl;
    }
};

void MyFunction(A* my_a) {
    // Cast will be successful only for B type objects.
    B* my_b = dynamic_cast<B*>(my_a);
    if (my_b == nullptr) {
        cerr << " Object is not of type B" << endl;
        return;
    }
    my_b->MethodSpecificToB();
}

int main() {
    array<A*, 3> array_of_a; // Array of pointers to base class A.
    array_of_a[0] = new B();   // Pointer to B object.
    array_of_a[1] = new B();   // Pointer to B object.
    array_of_a[2] = new A();   // Pointer to A object.

    for (int i = 0; i < 3; ++i)
        MyFunction(array_of_a[i]);
}
