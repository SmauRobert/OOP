#include <iostream>
#include "./Math.h"

using namespace std;

int main() {
    int a = 123, b = 872, c = 435;
    double d = 2.35, e = 34.85, f = 98.07;

    // cout << a << " + " << b << " = " << Math::Add(a, b) << '\n';
    // cout << a << " + " << b << " + " << c << " = " << Math::Add(a, b, c) << '\n';
    // cout << d << " + " << e << " = " << Math::Add(d, e) << '\n';
    // cout << d << " + " << e << " + " << f << " = " << Math::Add(d, e, f) << '\n';

    // cout << c << " * " << b << " = " << Math::Mul(c, b) << '\n';
    // cout << c << " * " << a << " * " << b << " = " << Math::Mul(c, a, b) << '\n';
    // cout << e << " * " << f << " = " << Math::Mul(e, f) << '\n';
    // cout << e << " * " << f << " * " << d << " = " << Math::Mul(e, f, d) << '\n';

    cout << Math::Add("123", "456") << '\n';
    return 0;
}