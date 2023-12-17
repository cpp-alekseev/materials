template<typename T, typename U>
struct S {
	template<int N>
	static void foo(int) {}
};

struct S<U, double> {
	static const int foo = 1;
};

template<typename T>
void bar(int x, int y) {
	 S<T>::foo<5>(x + y); // 
}

int main() {
	bar<double>(0, 0);
}
