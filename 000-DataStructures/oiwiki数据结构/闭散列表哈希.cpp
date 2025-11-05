#include <iostream>
#include <vector>

using namespace std;
class Hash {
private:
    const int M = 360007;
    vector<int> key, value;
public:
    Hash() : key(M), value(M);
    inline int f(int key) {
        return (key % M + M) % M;
    }
    int& operator[](int n) {
        int idx = f(n);
        int cnt = 1;
        while (key[idx] != n && value[idx] != 0) {
            cnt++;
        }
        key[cnt] = n;
        return value[idx];
    }
}