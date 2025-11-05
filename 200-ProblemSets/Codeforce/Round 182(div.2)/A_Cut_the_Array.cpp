#include <iostream>
#include <numeric>
using namespace std;

int t;
int n;
int a[50];
int res[50];
void solve()
{
    int left_arr = 0, right_arr = n - 1;
    for(int i = 0; i <= n - 3; i++)
    {
        for(int j = i + 1; j <= n - 2; j++)
        {
            if(res[i] % 3 == (res[j] - res[i]) % 3 && res[i] % 3 == (res[n - 1] - res[j]) % 3)
            {
                //cout<<"now res[i] is "<<res[i]<<" and res[j-i] is "<<res[j] - res[i]<<" and res is "<<(res[n - 1] - res[j])<<endl;
                cout<<i + 1<<" "<<j + 1<<endl;
                return;
            }
            if(res[i] % 3 != (res[j] - res[i]) % 3 && res[i] % 3 != (res[n - 1] - res[j]) % 3 && (res[j] - res[i]) % 3 != (res[n - 1] - res[j]) % 3)
            {
                //cout<<"now res[i] is "<<res[i]<<" and res[j-i] is "<<res[j] - res[i]<<" and res is "<<(res[n - 1] - res[j])<<endl;
                cout<<i + 1<<" "<<j + 1<<endl;
                return;
            }
        }
    }
    cout<<"0 0"<<endl;
    return;
}
int main()
{
    
    cin>>t;
    int tmp;
    for(int i = 0; i < t; i++)
    {
        cin>>n;
        for(int j = 0; j < n; j++)
        {
            cin>>tmp;
            a[j] = tmp % 3;
        }
        partial_sum(a, a + n, res);
        solve();
    }
}