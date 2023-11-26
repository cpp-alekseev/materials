// https://stackoverflow.com/questions/53993917/downcasting-in-c-with-virtual-base-class

class Base { };

class Derived: public virtual Base {};

class Derived2: public virtual Base {};

class Common: public  Derived, Derived2 {}

int main(void) {
    Derived * d = new Derived();
    Base *b = d;
    Derived * x = static_cast<Derived*>(b);

    delete x;
}
