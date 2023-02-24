#include <iterator>
#include <iostream>
#include <vector>
#include <list>

template<class It>
typename std::iterator_traits<It>::difference_type my_distance(It first, It last) {
    if constexpr (std::is_same_v<typename std::iterator_traits<It>::iterator_category(), std::random_access_iterator_tag>) {
        return last - first;
    } else {
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
