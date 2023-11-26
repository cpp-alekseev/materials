// https://en.cppreference.com/w/cpp/language/ebo

struct Base {
    void foo() {

    }
}; // empty class
 
struct Derived1 : Base
{
};
 
int main()
{
    // the size of any object of empty class type is at least 1
    static_assert(sizeof(Base) >= 1);
 
    // empty base optimization applies
    static_assert(sizeof(Derived1) >= 1);
}
