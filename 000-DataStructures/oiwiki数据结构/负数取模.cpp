#include <iostream>
using namespace std;

int main() {
    int a = -7;
    int b = 3;
    cout << a << " % " << b << " = " << (a % b) << endl;

    a = -7;
    b = 3;
    cout << a << " % " << b << " = " << ((a % b) + b) % b << endl;
    cout << a << " % " << b << " = " << (a % b) << endl;

    return 0;
}