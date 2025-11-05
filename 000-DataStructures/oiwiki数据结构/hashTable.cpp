#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct hashTable
{
    using ll = long long;
    const int SIZE = 1e5;
    const int M = 1e5 -3;
    vector<list<pair<ll, ll>>> ware;

    hashTable() : ware(SIZE) {}
    void add(ll key, ll value) {
        ware[hash(key)].push_back(make_pair(key, value));
    }
    inline int hash(ll key) {
        return (key % M + M) % M;
    }
    ll getValue(ll key) {
        if (ware[hash(key)].empty()) return -1;
        else for (auto i : ware[hash(key)]) {
            if (i.first == key) return i.second;
        }
        return -1;
    }
    void modify(ll key, ll value) {
        for (auto i : ware[hash(key)]) {
            if (i.first == key) i.second = value;
        }
        return;
    }
};

int main()
{
    hashTable ha;
    ha.add(99997, 100);
    ha.add(999989345, 999989345);
    ha.add(1, 100);
    ha.add(0, 120);

    cout << ha.getValue(1) << endl;
    cout << ha.getValue(0) << endl;
    cout << ha.getValue(99997) << endl;
    cout << ha.getValue(999989345) << endl;
}