#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> b{1, 2, 3, 4, 5, 2, 0, 8, 9};
std::vector<unsigned int> c{1, 2, 3, 4, 5, 2, 0, 8, 9};

int main()
{
    bool equal = 1;
    if (a == b) cout << "a is equal b" << endl;
    else cout << "a is not equal to b" << endl;

    for (auto i = 0; i < b.size(); i++)
    {
        if (b[i] != c[i])
        {
            equal = 0;
            break;
        }
    }

    if (equal) cout << "b is equal to c" << endl;
    else cout << "b is not equal to c" << endl;
}