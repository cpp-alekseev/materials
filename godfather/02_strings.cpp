#include <string>
#include <iostream>

int main() {
    std::string s;
    std::cin >> s;

    std::cout << s.size() << std::endl;
    std::cout << s << std::endl;

    std::string t = s;

    std::string x = "equal\n";

    if (s == t) {
        std::cout << "equal\n";
    } else {
        std::cout << "not equal\n";
    }

    // and many more things
    //

    return 0;
}