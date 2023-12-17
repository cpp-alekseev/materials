template<typename ConcretePrinter = void>
class Printer
{
    using return_type = std::conditional_t<std::is_same_v<ConcretePrinter, void>, Printer&, ConcretePrinter&>
public:
    Printer(ostream& pstream) : m_stream(pstream) {}
 
    template <typename T>
    return_type print(T&& t) { m_stream << t; return *this; }
 
    template <typename T>
    return_type println(T&& t) { m_stream << t << endl; return *this; }
private:
    ostream& m_stream;
};

class CoutPrinter : public Printer<CoutPrinter>
{
public:
    CoutPrinter() : Printer(cout) {}

    CoutPrinter& SetConsoleColor(Color c)
    {
        // ...
        return *this;
    }
};

int main() {
    CoutPrinter().print("Hello ").SetConsoleColor(Color.red).println("Printer!");
    //           ^               ^
}
