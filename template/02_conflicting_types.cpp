#include<vector>

template<typename T>
struct Outer {
    template<typename U>
    using inner = std::vector<U>;
};

template<typename T>
void go(typename Outer<T>::template inner<int> x) {  // (std::vector<int>)

}

template<typename T>
T t_is_return_type(int x) {
    return 0;
}

int main() {
    // std::vector<int> vec; // std::vector<int>::iterator,
    // go<int>(vec.begin()); // T = int?

    // t_is_return_type<double>(0);

    go<int>(std::vector<int>());
}
