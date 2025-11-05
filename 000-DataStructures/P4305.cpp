#include <iostream>
#include <list>
#include <vector>


using namespace std;

class hashTable {
using ll = long long;
private:
    const int SIZE { 50000 };
    const int M { 49997 }; // M 是取定的模数，一般定为小于 SIZE 的最大质数
    vector<list<ll>> table;
public:
    hashTable() : table(SIZE) {}
    void add(ll value) {table[hash(value)].push_back(value);}
    list<ll>* getList(int key) {return &table[key];}
    ll hash(ll value) {return (value % M + M) % M;}
    bool checkElem(ll value) {
        ll tmpKey = hash(value);
        list<ll>* ptr = getList(tmpKey);
        if (ptr->empty()) return false;
        else for (auto i : *ptr) if (i == value) return true;
        return false;
    }
};

int main() {
    //输入n个大数，要求存储进表，然后进行n次查询，检查输入数在不在表内
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    long long tmp;
    cin >> T;
    for (int i = 0; i < T; i++) {
        hashTable tb;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (!tb.checkElem(tmp)) {
                tb.add(tmp);
                cout << tmp << " ";
            }
        }
        cout << endl;
    }
}