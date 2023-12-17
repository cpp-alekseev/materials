template <typename T>
struct counter
{
    static int objects_created = 0;
    static int objects_alive = 0;

    counter()
    {
        ++objects_created;
        ++objects_alive;
    }
    
    counter(const counter&)
    {
        ++objects_created;
        ++objects_alive;
    }
protected:
    ~counter() 
    {
        --objects_alive;
    }
};

class X : counter<X> // EBO
{
    // ...
};

class Y : counter<Y>
{
    // ...
};

int main() {
    X x;
}