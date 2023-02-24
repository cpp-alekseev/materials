#include <iostream>
#include <type_traits>
#include <list>

class Array {
public:
    using value_type = int;
    using iterator = int *;
    using const_iterator = const int *;

    explicit Array(int n_) : n(n_) {
        data = new int[n];
    }

    Array(const Array &) = delete;

    ~Array() {
        delete[] data;
    }

    iterator begin() {
        return data;
    }

    iterator end() {
        return data + n;
    }

    const_iterator cbegin() {
        return data;
    }

    const_iterator cend() {
        return data + n;
    }

    int &operator[](int i) {
        return data[i];
    }

private:
    int *data;
    int n;
};

int main() {
    Array a(5);
    for (int i = 0; i < 5; ++i) {
        a[i] = i;
    }

    for (auto it = a.begin(); it != a.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // Here we can use auto, but in generic code we may need to deduce types
    std::iterator_traits<Array::iterator>::difference_type ptr_diff = a.end() - a.begin();
    std::ignore = ptr_diff;
    std::iterator_traits<Array::iterator>::value_type value = *a.begin();
    std::ignore = value;
    static_assert(
            std::is_same_v<
                    std::iterator_traits<Array::iterator>::iterator_category,
                    std::random_access_iterator_tag
            >, "Unexpected common_iterator tag"
    );
    return 0;
}
