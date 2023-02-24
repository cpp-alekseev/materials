#include <iostream>

template<bool B, typename T, typename F>
struct conditional {
    using type = T;
};

template<typename T, typename F>
struct conditional<false, T, F> {
    using type = F;
};

int main() {
    conditional<true, int, double>::type x = 0.5;
    conditional<false, int, double>::type y = 0.5;
    std::cout << x << ' ' << y << '\n';

    return 0;
}
