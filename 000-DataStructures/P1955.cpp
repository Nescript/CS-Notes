//同时维护两个并查集，分别记录相等关系和相不等关系，
//如果两个变量同时在两个并查集中出现，则关系无法被满足
//但是要注意，对same关系可以默认自己与自己相同
//但是diff关系不能默认自己与自己不同
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

class UnionFindSet {
public:
    vector<size_t> pa, size;
    UnionFindSet(size_t size) : pa(size), size(size, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    size_t findpa(int num) {
        return pa[num] == num ? num : pa[num] = findpa(pa[num]);
    }
    void merge(int a, int b) {
        a = findpa(a);
        b = findpa(b);
        if (a == b) return;
        if (size[a] >= size[b]) {
            size[a] += size[b];
            pa[b] = a;
        }
        else {
            size[b] += size[a];
            pa[a] = b;
        }
    }
    int getSize(int num) {
        return size[findpa(num)];
    }
};

int main(){
    vector<pair<int, int>> diff_;
    int T, n;
    int e, a, b;
    int cnt = 0;
    bool tag = 1;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cnt = 1;
        UnionFindSet same(MAXN);
        map<int, int> mp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> e;
            if (!mp[a]) mp[a] = cnt++;
            if (!mp[b]) mp[b] = cnt++;
            if (e) {same.merge(mp[a], mp[b]);}
            else diff_.push_back(make_pair(mp[a], mp[b]));
        }
        for (auto i : diff_) {
            if (same.findpa(i.first) == same.findpa(i.second)) 
            {
                cout << "NO" << endl;
                tag = 0;
                break;
            }
        }
        if (tag) cout << "YES" << endl;
        tag = 1;
        diff_.clear();
    }  
}

//问题在于关系输入不完全，有问题的语句可能被略过

//新的问题在于，读入的 i, j 数值上会很大，导致runtime error，
//因为前文并查集的实现是将 i, j 本身作为下标去访问 pa容器
//我们要做的是将所有的i, j映射到MAXN空间内。这里采用闭散列法

//需求是设计一个函数，给出原本的大数，返回一个较小的键值，确保键值和大数的唯一对应

//