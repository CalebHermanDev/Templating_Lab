#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

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

template <typename T>
vector<T> vec_fill(T elem)
{
    vector<T> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(elem + i);
    }

    return v;
}

template <typename T>
T until(T elem, function<T(T)> func, function<bool(T)> predicate)
{
    while (!predicate(elem))
    {
        elem = func(elem);
    }

    return elem;
}
template <typename T>
void order(T &a, T &b, T &c)
{
    if (a < b)
        my_swap(a, b);

    if (a < c)
        my_swap(a, c);

    if (b < c)
        my_swap(b, c);
}

int main()
{
    vector<int> vi = vec_fill(5);
    assert(vi.size() == 10);
    assert(vi[0] == 5);
    assert(vi[9] == 14);

    vector<double> vd = vec_fill(1.5);
    assert(vd[0] == 1.5);
    assert(vd[9] == 10.5);

    vector<char> vc = vec_fill('a');
    assert(vc[0] == 'a');
    assert(vc[9] == 'j');

    assert(
        until<int>(
            1,
            [](int x)
            { return x + 1; },
            [](int x)
            { return x >= 5; }) == 5);

    assert(
        until<double>(
            1.0,
            [](double x)
            { return x + 0.5; },
            [](double x)
            { return x >= 3.0; }) == 3.0);

    assert(
        until<char>(
            'a',
            [](char c)
            { return c + 1; },
            [](char c)
            { return c == 'f'; }) == 'f');

    int a = 3, b = 7, c = 1;
    order(a, b, c);
    assert(a == 7 && b == 3 && c == 1);

    double p = 2.5, q = 9.1, r = 4.4;
    order(p, q, r);
    assert(p == 9.1 && q == 4.4 && r == 2.5);

    char m = 'b', n = 'z', o = 'm';
    order(m, n, o);
    assert(m == 'z' && n == 'm' && o == 'b');

    cout << "All tests passed!" << endl;

    return 0;
}