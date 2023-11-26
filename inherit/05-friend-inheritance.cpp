#include <iostream>

class Granny {
protected:
    int x = 0;
    friend class Mom;
    friend class Son;
};

class Mom: protected Granny {
private:
    int y = 1;
    void f(Mom m) {
        Granny& g = m;
        std::cout << m.y << m.x << g.x;
    }
    friend class Son;
};

class Son: protected Mom {
    void f(Mom m) {
        Granny new_g;
        Granny& g = m;
        std::cout << m.y << m.x << g.x;
        std::cout << this->x << '\n';
    }
};

int x;

int main() {
    int x;
    x = 5;
    ::x = 7;
    std::cout << x << ' ' << ::x << '\n';
}
