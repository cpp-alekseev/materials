#include <iostream>
#include <vector>
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

    static_assert(
            std::is_base_of_v<
                    std::bidirectional_iterator_tag,
                    std::list<int>::iterator::iterator_category
            >, "Unexpected common_iterator tag"
    );

    return 0;
}
