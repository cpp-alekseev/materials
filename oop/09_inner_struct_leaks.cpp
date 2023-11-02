#include <iostream>

class C {
private:
	struct Inner {
    	int x = 1;
	};

public:
	Inner f() {
    	return Inner();
	}
};

int main() {    
	C c;
	auto inner = c.f();
	std::cout << c.f().x << '\n'; // CE or 1?
}
