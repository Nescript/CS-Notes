#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 200000 + 200;
int main()
{
    int n;
    cin>>n;
    int m;
    int tmp;
    long long a[MAXN];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>m;
        for(int j = 0; j < m; j++)
        {
            cin>>a[j];
        }
        sort(a, a + m);
        for(int j = 1; j <= m; j+=2)
        {
            tmp = abs(a[j] - a[j - 1]);
            if(tmp > ans) ans = tmp;
        }
        cout<<ans<<endl;;
        ans = 0;
    }
    
}