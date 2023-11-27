// https://en.wikipedia.org/wiki/Run-time_type_information

#include <iostream>
#include <typeinfo>

class Person {
public:
    virtual ~Person() = default;
};

class Employee : public Person {};

int main() {
    Person person;
    Employee employee;
    Person* ptr = &employee;
    Person& ref = employee;
    
    std::cout << typeid(*ptr).hash_code()
              << std::endl;  // Employee (looked up dynamically at run-time
                             //           because it is the dereference of a
                             //           pointer to a polymorphic class).
    std::cout << typeid(ref).hash_code()
              << std::endl;  // Employee (references can also be polymorphic)
} 
