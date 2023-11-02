#include<iostream>

int& f() {
	int p = 5;
	return *p;
}

int main() {
	int& x = f();
	std::cout << x;
}
