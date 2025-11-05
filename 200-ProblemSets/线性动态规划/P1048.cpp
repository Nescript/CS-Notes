#include <bits/stdc++.h>
const int MAXN = 100 + 10;
using namespace std;
int dp[MAXN][1010];
int info[MAXN][2];

int solve(int item, int time)
{
    //cout << "for now item is " << item << " ans time is " << time <<endl;
    if(item == 0) return 0;
    if(dp[item][time] != -1) return dp[item][time];
    if(time >= info[item][0]) 
        return dp[item][time] = max(solve(item - 1, time), 
                                    solve(item - 1, time - info[item][0]) + info[item][1]);
    else return dp[item][time] = solve(item - 1, time);
}

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
    
    //cout << "wtf" << endl;
    cout << solve(M, T) << endl;
    //cout << dp[M][T] << endl;
}