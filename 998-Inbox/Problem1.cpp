#include <iostream>

using namespace std;
int dp[21][21];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == 1 || j == 1 || j == i)
            {
                cout << "1" << " ";
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                cout << dp[i][j] << " ";
            }  
        }
        cout << endl;
    }
}