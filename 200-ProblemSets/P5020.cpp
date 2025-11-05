//货币系统内冗余的货币就是可以用别的货币组合得到的面额
//将题面转化为背包： 完全背包
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25000 + 10;

vector<int> arr; 
vector<int> dp(MAXN, -1);

int temp;

bool isNotNeccessary(int a) {
    if(a < 0) return 0;
    if (dp[a] != -1 && a != temp) return dp[a];
    for (auto i : arr) {
        if (isNotNeccessary(a - i)) {
            dp[a - i] = 1;
            return 1;
        }
    }
    dp[a] = 0;
    return 0;
}
int main() {
    int T, ans, n;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        dp[0] = 1;
        cin >> n;
        ans = n;
        for (int j = 0; j < n; j++) {
            cin >> temp;
            arr.push_back(temp);
            dp[arr[j]] = 1;
        }
        sort(arr.begin(), arr.end());
        for (int j = n - 1; j >= 1; j--) {
            temp = arr.back();
            arr.pop_back();
            if (isNotNeccessary(temp)) ans--;
        }
        cout << ans << endl;
        arr.clear();
        fill(dp.begin(), dp.end(), -1);
    }
}

// 转移方式：对于包含 k 种面额的货币系统，一个面额 l 能不能取，取决于其 减去各货币面额后的面额能不能取。

// 问题：目前实现没法混淆了货币本身面额

// 尝试：每次都把最后一位推出去