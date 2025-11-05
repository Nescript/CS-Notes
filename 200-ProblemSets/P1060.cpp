#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30000 + 10;
int dp[MAXN] = {0};
int info[30][2];
//0 is for cost, 1 is for val (cost * p)

int main()
{
    int n, m;
    int v, p;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p;
        info[i][0] = v;
        info[i][1] = v * p;
        //cout << "read info cost and val " << info[i][0] << info[i][1] <<endl;
    }
    for (int i = 1; i <= m; i++)
    {
        //cout << "current i is " << i << " and val is" << info[i][1] << endl;
        for (int j = n; j >= info[i][0]; j--)
        {
            //cout << "current i is " << i << " and val is" << info[i][1] << endl;
            dp[j] = max(dp[j], dp[j - info[i][0]] + info[i][1]);
            //cout << "current dpj is " << dp[j] << " and j is" << j << endl;
        }
    }
    cout << dp[n] <<endl;
}