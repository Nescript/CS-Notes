#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n;
    int ans, tmp;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (j == 0) ans = tmp;
            else if (tmp > ans) ans = tmp;
        }
        cout << ans << endl;
    }
}