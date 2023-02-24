#include <iostream>
#include <iterator>

class Array {
public:
    template<bool IsConst>
    class CommonIterator {
    public:
        using value_type = int;
        using reference = std::conditional_t<IsConst, int&, const int&>;
        using pointer = std::conditional_t<IsConst, int*, const int*>;

        CommonIterator() = default;

        CommonIterator(const CommonIterator &) = default;

        CommonIterator &operator=(const CommonIterator &other) = default;

        auto operator<=>(const CommonIterator &) const = default;

        reference operator*() {
            return *ptr;
        }

        pointer operator->() const {
            return ptr;
        }

        int& operator[](ptrdiff_t x) const {
            return *(ptr + x);
        }

        ptrdiff_t operator-(const CommonIterator &other) const {
            return other.ptr - ptr;
        }

        CommonIterator &operator+=(ptrdiff_t x) {
            ptr += x;
            return *this;
        }

        CommonIterator &operator-=(ptrdiff_t x) {
            return operator+=(-1 * x);
        }

        CommonIterator &operator++() {
            return operator+=(1);
        }

        CommonIterator &operator--() {
            return operator-=(1);
        }

        CommonIterator operator++(int) & {
            auto copy = *this;
            operator+=(1);
            return copy;
        }

        CommonIterator operator--(int) & {
            auto copy = *this;
            operator-=(1);
            return copy;
        }

    private:
        explicit CommonIterator(pointer ptr_) : ptr(ptr_) {}

        friend Array;

        pointer ptr;
    };

    using iterator = CommonIterator<false>;
    using const_iterator = CommonIterator<true>;

    explicit Array(int n_) : n(n_) {
        data = new int[n];
    }

    Array(const Array &) = delete;

    ~Array() {
        delete[] data;
    }

    iterator begin() {
        return iterator(data);
    }

    iterator end() {
        return iterator(data + n);
    }

    const_iterator cbegin() const {
        return const_iterator(data);
    }

    const_iterator cend() const {
        return const_iterator(data + n);
    }

    int &operator[](int i) {
        return data[i];
    }

private:

    int *data;
    int n;
};

template<bool IsConst>
Array::CommonIterator<IsConst> operator+(ptrdiff_t lhs, Array::CommonIterator<IsConst> rhs) {
    rhs += lhs;
    return rhs;
}

template<bool IsConst>
Array::CommonIterator<IsConst> operator+(Array::CommonIterator<IsConst> lhs, ptrdiff_t rhs) {
    lhs += rhs;
    return lhs;
}

template<bool IsConst>
Array::CommonIterator<IsConst> operator-(Array::CommonIterator<IsConst> lhs, ptrdiff_t rhs) {
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
            >::value, "Unexpected CommonIterator tag"
    );

    static_assert(
            std::is_same<
                    std::iterator_traits<Array::const_iterator>::iterator_category,
                    std::random_access_iterator_tag
            >::value, "Unexpected CommonIterator tag"
    );

    for (auto it = a.begin(); it != a.end(); it++) {
        std::cout << *it << ' ';
    }
    return 0;
}
