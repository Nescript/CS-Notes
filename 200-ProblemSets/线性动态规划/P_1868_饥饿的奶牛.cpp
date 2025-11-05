#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<int,int>> segs;
    segs.reserve(N);
    int maxY = 0;
    for (int i = 0; i < N; i++) {
        int x, y; 
        cin >> x >> y;
        segs.emplace_back(x, y);
        if (y > maxY) maxY = y;
    }

    vector<vector<int>> endAt(maxY + 1);
    for (auto [x, y] : segs) {
        if (0 <= y && y <= maxY) endAt[y].push_back(x);
    }

    vector<int> dp(maxY + 1, 0);
    for (int i = 1; i <= maxY; i++) {
        dp[i] = dp[i - 1];
        for (int start : endAt[i]) {
            int pre = (start > 0 ? dp[start - 1] : 0);
            int len = i - start + 1;        // 区间长度
            dp[i] = max(dp[i], pre + len);
        }
    }

    cout << dp[maxY] << '\n';
    return 0;
}