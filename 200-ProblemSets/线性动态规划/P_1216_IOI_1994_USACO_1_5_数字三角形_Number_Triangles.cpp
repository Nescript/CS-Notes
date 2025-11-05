#include <iostream>
using namespace std;
const int MAXN = 1000 + 10;
int num[MAXN][MAXN];
int dp[MAXN][MAXN];
int main()
{
    int r;
    cin>>r;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin>>num[i][j];
            if(i == r)
            {
                dp[i][j] = num[i][j];
            }
        }
    }
    for(int k = r - 1; k >= 1; k--)
    {
        for(int l = 1; l <= k; l++)
        {
            dp[k][l] = num[k][l] + max(dp[k + 1][l], dp[k + 1][l + 1]);
        }
    }
    cout<<dp[1][1];
}