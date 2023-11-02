#include <vector>

int main() {
	int x, y;
	std::vector<int&> a = {x, y}; // CE
}
