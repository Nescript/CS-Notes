#include <bits/stdc++.h>
const int MAXN = 100 + 10;
using namespace std;
int dp[1010];
int info[MAXN][2];

int item;
int main()
{
    memset(dp, -1, sizeof(dp));    
    int T, M;
    cin >> T >> M;
    int time, val;
    //cout << "wtf" << endl;
    for (int i = 1; i <= M; i++)
    {
        cin >> info[i][0] >> info[i][1];
    }
    item = M;
    dp[0] = 0;
    //cout << "wtf" << endl;
    cout << solve(T) << endl;
    //cout << dp[M][T] << endl;
    cout << dp[100] << " " << dp[70] << " " << dp[1];
}