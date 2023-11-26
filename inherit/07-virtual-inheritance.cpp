// https://www.youtube.com/watch?v=9WIPP5Bgii0&t=1006s

// We don't like:

// A   A  
// |   |
// B   C  
//  \ /  
//   D 


// We like:

//   A  
//  / \  
// B   C  
//  \ /  
//   D 
//   |
//   E

// A
// |
// B (InputFile)

#include <iostream>

struct File {
    int a;
    File(int a) : a{a} {}
};

struct InputFile : virtual public File {
    int b;
    InputFile(int b) : File(b * 2), b{b} {}
};

struct OutputFile : virtual public File {
    int c;
    OutputFile(int c) : File(c * 3), c{c} {}
};

struct IOFile : public InputFile, public OutputFile {
    int d;
    IOFile(int d) : File(d),  InputFile(d), OutputFile(d), d(d) {}
};

struct IOFile2 : public IOFile {
    int e;
    IOFile2(int e) : File(e), IOFile(e), e(e) {}
};

int main() {
    IOFile2 f(11);

    std::cout << f.InputFile::a << std::endl;
    std::cout << f.OutputFile::a << std::endl;
    std::cout << f.a << std::endl;

    InputFile g(11);
    OutputFile h(11);
}
