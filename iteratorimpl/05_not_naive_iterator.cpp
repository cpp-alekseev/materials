#include <iostream>
#include <iterator>
#include <vector>

class Array {
public:
    class iterator {
    public:
        using value_type = int;
        using pointer = int*;
        using reference = int &;

        iterator() = default;

        iterator(const iterator &) = default;

        iterator &operator=(const iterator &other) = default;

        auto operator<=>(const iterator &) const = default;

        reference operator*() const {
            return *ptr;
        }

        pointer operator->() const {
            return ptr;
        }

        reference operator[](ptrdiff_t x) const {
            return *(ptr + x);
        }

        ptrdiff_t operator-(const iterator &other) const {
            return other.ptr - ptr;
        }

        iterator &operator+=(ptrdiff_t x) {
            ptr += x;
            return *this;
        }

        iterator &operator-=(ptrdiff_t x) {
            return operator+=(-1 * x);
        }

        iterator &operator++() {
            return operator+=(1);
        }

        iterator &operator--() {
            return operator-=(1);
        }

        iterator operator++(int) {
            auto copy = *this;
            operator+=(1);
            return copy;
        }

        iterator operator--(int) {
            auto copy = *this;
            operator-=(1);
            return copy;
        }

    private:
        iterator(pointer ptr_) : ptr(ptr_) {}

        friend Array;

        pointer ptr;
    };

    explicit Array(int n_) : n(n_) {
        data = new int[n];
    }

    Array(const Array &) = delete;

    ~Array() {
        delete[] data;
    }

    iterator begin() {
        return {data};
    }

    iterator end() {
        return {data + n};
    }

    int &operator[](int i) {
        return data[i];
    }

private:

    int *data;
    int n;
};

Array::iterator operator+(ptrdiff_t lhs, Array::iterator rhs) {
    rhs += lhs;
    return rhs;
}

Array::iterator operator+(Array::iterator lhs, ptrdiff_t rhs) {
    lhs += rhs;
    return lhs;
}

Array::iterator operator-(Array::iterator lhs, ptrdiff_t rhs) {
    lhs -= rhs;
    return lhs;
}

int main() {
    Array a(5);
    for (int i = 0; i < 5; ++i) {
        a[i] = i;
    }

    static_assert(
            std::is_same<
                    std::iterator_traits<Array::iterator>::iterator_category,
                    std::random_access_iterator_tag
            >::value, "Unexpected iterator tag"
    );

    foo(a.begin());

    for (auto it = a.begin(); it != a.end(); it++) {
        std::cout << *it << ' ';
    }

    return 0;
}
