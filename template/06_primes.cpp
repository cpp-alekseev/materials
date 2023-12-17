#include <iostream>

template <int N, int D>
struct IsPrimeHelper {
	static constexpr bool value = N % D == 0 ? false : IsPrimeHelper<N, D-1>::value;
};

template <int N>
struct IsPrimeHelper<N, 1> {
	static constexpr bool value = true;
};

template <int N>
struct IsPrime {
	static constexpr bool value = IsPrimeHelper<N, N-1>::value;
};

template <>
struct IsPrime<1> {
	static constexpr bool value = false;
};

template<int N>
const bool is_prime = IsPrime<N>::value;

int main() {
	std::cout << is_prime<17> << '\n';
	std::cout << is_prime<100> << '\n';
}
