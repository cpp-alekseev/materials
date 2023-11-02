
class SomeLargeStruct {
    int v[1000];
};

SomeLargeStruct foo() {
    SomeLargeStruct value;
    value.v[0] = 100;
    return value;
}

int main() {
    const SomeLargeStruct& s = foo();

    std::cout << s.v[0] << '\n';
}
