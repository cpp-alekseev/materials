#include<iostream>

struct Granny {
    void f() {
        std::cout << "1\n";
    }
};

struct Mom: Granny {
    void f()  {
        std::cout << "2\n";
    }
};

// [Granny][Mom][Son members]
struct Son: Mom {
    void f()  {
        std::cout << "3\n";
    }
};

int main() {
    Granny* g = new Son();
    auto x = static_cast<Mom*>(g);

    //reinterpret_cast<Son*>(g)->f(); // UB
    //static_cast<Son>(g)->f(); // CE
    // if (dynamic_cast<Son*>(g) != nullptr) {
    //     std::cout << "Fine\n";
    // }
}
