#include <iostream>
using namespace std;
 
void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void swap2(int& first, int& second) {
    first ^= second; // first = prev_first ^ prev_second
    second ^= first; // second = prev_second ^ (prev_first ^ prev_second) = prev_first
    first ^= second; // (prev_first ^ prev_second) ^ prev_first = prev_second
}
 
int main()
{
    int a = 2, b = 3;
 
    swap(a, b);
 
    cout << a << " " << b;
    return 0;
}