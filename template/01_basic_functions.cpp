
template<typename T, typename U, size_t N>
const T& max(const T& a, const T& b) {
    if (a > b) {
        return a;
    }

    a.foo();

    return b;
}

int main() {
    max<int, double, 2>(1, 2);
    max<int, double, 1>('a', 'z');
}
