struct Abstract
{
    int a;
    int b;
    virtual void f() = 0;  // pure virtual
}; // "Abstract" is abstract

struct Concrete : Abstract
{
    void f() final {}   // non-pure virtual
    virtual void g() {}  // non-pure virtual
}; // "Concrete" is non-abstract

struct Concrete2 : Concrete
{
    void g() override {

    }
}; 
 
int main()
{
    // Abstract a;   // Error: abstract class
    
    Concrete b;      // OK
    Abstract& a = b; // OK to reference abstract base
    
    a.f();           // virtual dispatch to Concrete::f()
}
