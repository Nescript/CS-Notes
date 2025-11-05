#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class UnionFindSet {
private:
    vector<size_t> pa;
public:
    UnionFindSet(size_t size) : pa(size) {
        iota(pa.begin(), pa.end(), 0);
    }
    size_t findpa(size_t son) {
        return pa[son] == son ? son : pa[son] = findpa(pa[son]);
    }
    void merge(size_t a, size_t b) {
        pa[findpa(a)] = findpa(b);
    }
};

int main() {
    // 输入 n k
    // n 个关系 k 次查询
    int n, k;
    UnionFindSet rela(200);
    cin >> n >> k;
    int pa, son;
    for (int i = 0; i < n; i++) {
        cin >> pa >> son;
        rela.merge(pa, son);
    }
    for (int i = 0; i < k; i++) {
        cin >> pa >> son;
        if (rela.findpa(pa) == rela.findpa(son)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}