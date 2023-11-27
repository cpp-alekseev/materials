// Based on ISO C++ 11.8, Example 10
// When virtual base classes are used, a hidden declaration can be reached along
// a path through the subobject lattice that does not pass through the hiding declaration.
// This is not an ambiguity. The identical use with non-virtual base classes is an ambiguity;
// in that case there is no unique instance of the name that hides all the others.


// A   A  
// |   |
// B   C  
//  \ /  
//   D 


// We like:

//   A  
//  / \  
// B   C  
//  \ /  
//   D 

struct Human {
    int f(); // hidden declaration
    int x; // hidden declaration
};

struct Mother : virtual Human {
    int f(); // hiding declaration
    int x; // hiding declaration
};

struct Father : virtual Human {};

struct Son : Mother, Father {
    void test() {
        ++x;
        f();
    }
};

int main() {

}
