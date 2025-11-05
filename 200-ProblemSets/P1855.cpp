#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200 + 10; 

int t[MAXN];
int m[MAXN];
int dp[MAXN][MAXN] = {0};
int main()
{
    int n, M, T;
    cin >> n >> M >> T;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i] >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = M; j >= m[i]; j--)
        {
            for (int k = T; k >= t[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - m[i]][k - t[i]] + 1);
            }
        }
    }
    cout << dp[M][T] << endl; 
}