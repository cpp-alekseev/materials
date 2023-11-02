#include <iostream>

int main() {
	int x = 1;
	/* const */ double& y = x;
	x = 2;
	std::cout << y; // 1
}
