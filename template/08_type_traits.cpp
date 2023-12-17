#include <type_traits>
#include <iostream>

// is_same<int, int>::value
template<class T, class U>
struct is_same : std::false_type {}
 
template<typename T>
// struct is_same<T, T> :: std::true_type;
// struct is_same<T, T> :: std::bool_constant<true>;
struct is_same<T, T> :: std::integral_constant<bool, true>;

template<class T, class U>
using is_same_v = is_same<T, U>::value;


template<class T>
struct remove_const { typedef T type; }; // using type = T;

template<class T>
struct remove_const<const T> { typedef T type; };

template<class T>
using remove_const_t = remove_const<T>::type;

template<class T>
struct remove_reference { typedef T type; };

template<class T>
struct remove_reference<T&>{ typedef T type; };

template<class T>
struct remove_reference<T&&> { typedef T type; };


template<bool B, class T, class F>
struct conditional { using type = T; };
 
template<class T, class F>
struct conditional<false, T, F> { using type = F; };

template<class T>
struct rank : public std::integral_constant<std::size_t, 0> {}; // static constexpr size_t value = 0;
 
template<class T>
struct rank<T[]> : public std::integral_constant<std::size_t, rank<T>::value + 1> {};
 
template<class T, std::size_t N>
struct rank<T[N]> : public std::integral_constant<std::size_t, rank<T>::value + 1> {};


// Pointer to member
// https://stackoverflow.com/questions/670734/what-is-a-pointer-to-class-data-member-and-what-is-its-use

template<class T>
struct is_member_pointer_helper : std::false_type {};
 
template<class T, class U>
struct is_member_pointer_helper<T U::*> : std::true_type {};
 
template<class T>
struct is_member_pointer : is_member_pointer_helper<typename std::remove_const<T>::type> {};

class Car {
    public:
    int speed;
};

int main() {
    std::remove_const_t<const int> x; // int x
}

// https://en.cppreference.com/w/cpp/language/parameter_pack
// https://en.cppreference.com/w/cpp/language/fold
