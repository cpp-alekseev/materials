#include <iostream>

// POD
struct T {
    int x;
} t;

struct S {
	const T& store;
	S(const T& tx) : store(tx) {
	} 
};

int main() {
	T tx{100};
	S s(tx);
}
