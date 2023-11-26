// https://www.programiz.com/cpp-programming/inheritance#:~:text=Access%20Modes%20in%20C%2B%2B%20Inheritance&text=However%2C%20we%20can%20also%20use,protected%20Animal%20%7B%20%2F%2F%20code%20%7D%3B

#include <iostream>

using namespace std;

struct InnerField {
    std::string caller_;

    InnerField(const std::string& caller): caller_(caller) {
        std::cout << "InnerField ctor from " << caller << '\n';
    }

    ~InnerField() {
        std::cout << "InnerField dtor from " << caller_ << '\n';
    }
};

// base class
class Animal {
protected:
    InnerField field{"animal"};
public:
    Animal() {
        std::cout << "Animal ctor body\n";
    }

    Animal(std::string name) {
        std::cout << "Animal name ctor\n";
    }

    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }

    ~Animal() {
       std::cout << "Animal dtor\n"; 
    }
};

// derived class
class Dog : public Animal {
private:
    InnerField field{"dog"};
public:
    // using Animal::Animal; // Inherits Animal's constructors, all other members default-initialized (not with a default constructor)
    
    Dog(const std::string& name) : Animal(name) {
        std::cout << "Dog ctor body\n";
    }
    
    Dog() {
        std::cout << "Dog ctor body\n";
    }
    
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }

    using Animal::eat;
    void eat(const std::string& dogFoodBrand) {
        cout << "I can eat my dogfood: " << dogFoodBrand << "!" << endl;
    }

    ~Dog() {
       std::cout << "Dog dtor\n"; 
    }
};

int main() {
    // Create object of the Dog class
    Dog dog1("barsik");
    std::cout << "---------\n";
    Dog dog2;
    std::cout << "---------\n";

    // Calling members of the base class
    dog1.eat();
    dog1.sleep();

    // Calling member of the derived class
    dog1.eat("Premium");
    dog1.bark();


    std::cout << "---------\n";

    return 0;
}
