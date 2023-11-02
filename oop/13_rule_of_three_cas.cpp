// Ref: https://en.cppreference.com/w/cpp/language/rule_of_three

#include <cstddef>
#include <cstring>
#include <iostream>
 
class rule_of_three
{
    char* cstring; // raw pointer used as a handle to a
                   // dynamically-allocated memory block
 
    rule_of_three(const char* s, std::size_t n) // to avoid counting twice
        : cstring(new char[n]) // allocate
    {
        std::memcpy(cstring, s, n); // populate
    }
 
public:
    explicit rule_of_three(const char* s = "")
        : rule_of_three(s, std::strlen(s) + 1) {}
 
    ~rule_of_three() // I. destructor
    {
        delete[] cstring; // deallocate
    }
 
    rule_of_three(const rule_of_three& other) // II. copy constructor
        : rule_of_three(other.cstring) {}
 
    rule_of_three& operator=(rule_of_three& other) { // III. copy assignment
        if (this != &other) {
            rule_of_three(other).swap(*this);
        }
 
        return *this;
    }

    void swap(rule_of_three& other) {
        std::swap(cstring, other.cstring);
    }

    friend std::ostream& operator<<(std::ostream& out, const rule_of_three& value) {
        out << value.cstring // operator<<(std::ostream&, char*)
        return out;
    }
};

int main()
{
    rule_of_three o1{"abc"};

    std::cout << o1 << '\n';
    std::cerr << o1 << '\n';

    rule_of_three o2 = o1; // II. uses copy constructor
    rule_of_three o2(o1); // II. uses copy constructor

    std::cout << o2 << ' ';
    rule_of_three o3("def");
    std::cout << o3 << ' ';
    o3 = o2; // III. uses copy assignment
    std::cout << o3 << '\n';

    o1 = (o2 = (o3 = "abc"));
}   // I. all destructors are called here
