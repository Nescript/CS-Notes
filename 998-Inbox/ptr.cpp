#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> num(new int(42));
    *num = 41;
    cout << *num << endl;

}