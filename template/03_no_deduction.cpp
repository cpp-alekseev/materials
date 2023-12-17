#include<vector>
#include<string>

template <typename T>
class Debug { Debug() = delete; };

template<typename T>
void bar(T x) {
    Debug<T>();
} 

int main() {
    std::vector<int> x(100);
    bar(x);
}
