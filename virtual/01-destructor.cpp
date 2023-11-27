// https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors

class Base 
{
public:
    // some virtual methods
    virtual ~Base() {}
};

class Derived : public Base {
    int x;
public:
    ~Derived() {

    }
};

int main() {
    // VPTR: Destructor -> 0x....
    Base *b = new Derived(); // b -> [VPTR (Derived)][B][Derived members]
    // use b
    delete b; // b -> Lookup destructor in VPTR -> 0x.... (~Derived())  -> free
}
