// https://stackoverflow.com/questions/99552/where-do-pure-virtual-function-call-crashes-come-from

#include<iostream>

class Function
{
public:
    Base() { }
    void reallyDoIt() { doIt(); } // DON'T DO THIS
    virtual double getFX(double x) = 0;

    double integrate() {
        getFX((l + r) / 2);
    }
};

class Sin: public Function {
    double getFX(double x) override {
        return sin(x);
    }
}

class Derived : public Base
{
    int x;
    int y;
public:
    Derived() : x(0), y(doIt()) {
        doIt();
        std::cout << "y: " << y << '\n';
    }
    int doIt() {
        std::cout << "derived do it\n";
        return y;
    }
};

int main(void)
{
    Derived d;  // This will cause "pure virtual function call" error
}
