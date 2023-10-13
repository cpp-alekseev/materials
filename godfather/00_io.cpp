#include <iostream>

// Basic IO using C++ library
int main() {
    

    int a;
    unsigned int b;
    std::cin >> a >> b;

    std::cout << "Simple int: " << a << std::endl;
    std::cout << "unsigned: " << b << ", ";
    std::cout << "oct: " << std::oct << b << ", ";
    std::cout << "hex: " << std::hex << b << std::endl;

    // std::print(3.14);

    // std::format is coming
    // https://en.cppreference.com/w/cpp/utility/format/format
    return 0;
}
