template <typename T>
struct S {
	using A = int;
};

template <>
struct S<double> {
	static const int A = 5;
};

int x = 0;

template <typename T>
void f() {
	typename S<T>::A * x; // T=[int]: int *x; T=[double] 5 * 0;
}

int main() {
	f<int>();
	f<double>();
}