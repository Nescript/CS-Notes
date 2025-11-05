#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
int num[MAXN];
int dp_front[MAXN];
int dp_back[MAXN];
int dp_front_arr;
int dp_back_arr;
int ans[MAXN];
int final_ans;
void output(int dp[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    memset(ans, 0, sizeof(ans));
    final_ans = 0;
    int n;
    cin>>n;
    dp_back_arr = 0;
    dp_front_arr = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    dp_front[0] = num[0];
    dp_back[0] = num[n - 1];
    for(int j = 0; j < n; j++)
    {
        if(num[j] > dp_front[dp_front_arr])
        {
            dp_front_arr++;
            dp_front[dp_front_arr] = num[j];
        }
        else
        {
            dp_front[lower_bound(dp_front, dp_front + dp_front_arr + 1, num[j]) - dp_front] = num[j];
        }
        ans[j] += dp_front_arr + 1;
        //output(dp_front, dp_front_arr + 1);
    }
    for(int j = n - 1; j >= 0; j--)
    {
        if(num[j] > dp_back[dp_back_arr])
        {
            dp_back_arr++;
            dp_back[dp_back_arr] = num[j];
        }
        else
        {
            dp_back[lower_bound(dp_back, dp_back + dp_back_arr + 1, num[j]) - dp_back] = num[j];
        }
        ans[j] += dp_back_arr;
        if(ans[j] > final_ans) final_ans = ans[j];
        //output(dp_back, dp_back_arr + 1);
    }
    //output(ans, n);
    cout<<n - final_ans<<endl;
}