// Ref: https://en.cppreference.com/w/cpp/language/rule_of_three

#include <cstddef>
#include <cstring>
#include <iostream>
 
class string
{
    char* cstring; // raw pointer used as a handle to a
                   // dynamically-allocated memory block
 
    string(const char* s, std::size_t n) // to avoid counting twice
        : cstring(new char[n]) // allocate
    {
        std::memcpy(cstring, s, n); // populate
    }
 
public:
    explicit string(const char* s = "")
        : string(s, std::strlen(s) + 1) {}
 
    ~string() // I. destructor
    {
        delete[] cstring; // deallocate
    }
 
    string(const string& other) // II. copy constructor
        : string(other.cstring) {}
 
    string& operator=(const string& other) // III. copy assignment
    {
        if (this != &other) {
            string(other).swap(*this);
        }
 
        return *this;
    }

    void swap(string& other) {
        std::swap(cstring, other.cstring);
    }
 
    const char& operator[](size_t pos) const { // why not simple char?
        return cstring[pos]; // *(cstring + pos)
    }

    char& operator[](size_t pos) { // s[0] = 'b';
        return cstring[pos];
    }
};
 
int main() {
    const string s("abc");
    std::cout << s[0] << '\n';
}
