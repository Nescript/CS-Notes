#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    int tmp;
    int cnt_neg1 = 0;
    int cnt_0;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>m;
        for(int j = 1; j <= m; j++)
        {
            cin>>tmp;
            if(tmp == 0) ans++;
            if(tmp == -1) cnt_neg1++;
        }
        ans += 2* (cnt_neg1 % 2);
        cout<<ans<<endl;
        ans = 0;
        cnt_neg1 = 0;
    }
    
}