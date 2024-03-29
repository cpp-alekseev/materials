#include <iostream>
 
int main()
{
    int x = 10;
 
    // ref is a reference to x.
    int& ref = x;
 
    // Value of x/ref is now changed to 20
    ref = 20;
    std::cout << "x = " << x << '\n';
 
    // Value of x/ref is now changed to 30
    x = 30;
    std::cout << "ref = " << ref << '\n';
 
    return 0;
}
