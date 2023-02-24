#include <iostream>
#include <iterator>
#include <vector>

class Array {
public:
    template<bool IsConst>
    class common_iterator {
    public:
        using value_type = int;
        using pointer = std::conditional_t<IsConst, const int *, int *>;
        using reference = std::conditional_t<IsConst, const int &, int &>;

        common_iterator() = default;

        common_iterator(const common_iterator &) = default;

        common_iterator &operator=(const common_iterator &other) = default;

        auto operator<=>(const common_iterator &) const = default;

        reference operator*() const {
            return *ptr;
        }

        pointer operator->() const {
            return ptr;
        }

        reference operator[](ptrdiff_t x) const {
            return *(ptr + x);
        }

        ptrdiff_t operator-(const common_iterator &other) const {
            return other.ptr - ptr;
        }

        common_iterator &operator+=(ptrdiff_t x) {
            ptr += x;
            return *this;
        }

        common_iterator &operator-=(ptrdiff_t x) {
            return operator+=(-1 * x);
        }

        common_iterator &operator++() {
            return operator+=(1);
        }

        common_iterator &operator--() {
            return operator-=(1);
        }

        common_iterator operator++(int) {
            auto copy = *this;
            operator+=(1);
            return copy;
        }

        common_iterator operator--(int) {
            auto copy = *this;
            operator-=(1);
            return copy;
        }

    private:
        common_iterator(pointer ptr_) : ptr(ptr_) {}

        friend Array;

        pointer ptr;
    };

    using iterator = common_iterator<false>;
    using const_iterator = common_iterator<true>;

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

    const_iterator cbegin() const {
        return {data};
    }

    const_iterator cend() const {
        return {data + n};
    }

    int &operator[](int i) {
        return data[i];
    }

    void foo() {

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

template<std::random_access_iterator It>
void foo(It it) {

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
            >::value, "Unexpected common_iterator tag"
    );

    foo(a.begin());

    for (auto it = a.begin(); it != a.end(); it++) {
        std::cout << *it << ' ';
    }

    return 0;
}
