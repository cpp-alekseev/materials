#include <iterator>
#include <type_traits>
#include <vector>
#include <iostream>
#include <list>

template<typename It>
constexpr typename std::iterator_traits<It>::difference_type my_distance(It first, It last)
{
    using category = typename std::iterator_traits<It>::iterator_category;
    if constexpr (std::is_base_of_v<std::random_access_iterator_tag, category>) {
        std::cout << "[Fast distance evaluation] ";
        return last - first;
    } else {
        std::cout << "[Slow distance evaluation] ";
        typename std::iterator_traits<It>::difference_type result = 0;
        while (first != last) {
            ++first;
            ++result;
        }
        return result;
    }
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l{1, 2, 3, 4, 5};
    std::cout << "Distance in vector: " << my_distance(v.begin(), v.end()) << '\n';
    std::cout << "Distance in list: " << my_distance(l.begin(), l.end()) << '\n';
}
