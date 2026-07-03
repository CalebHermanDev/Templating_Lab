#include <iostream>
using namespace std;

template <typename T>
T max_two(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
T max_three(T a, T b, T c)
{
    return max_two(max_two(a, b), c);
}
template <typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << max_two(5, 10) << endl;      // 10
    cout << max_three(5, 10, 7) << endl; // 10
    cout << max_two(3.5, 2.1) << endl;   // 3.5

    int x = 5, y = 10;
    my_swap(x, y);

    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}