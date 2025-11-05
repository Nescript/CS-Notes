#include <iostream>
#include <algorithm>
#include <cstring>

//对于小于k的数，缺谁补谁（计入cnt）
//对于等于k的数，可以用来补缺的数（要用掉，可以和上面抵消）

using namespace std;
const int MAXN = 200000 + 200;
int main()
{
    int n;
    cin>>n;
    int m,k;
    int tmp;
    int a[MAXN];
    int ans = 0;

    int cnt_nonk = 0;
    int cnt_k = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>m>>k;
        for(int j = 0; j < m; j++)
        {
            cin>>tmp;
            a[tmp]++;
        }
        cnt_k = a[k];
        for(int kk = 0; kk < k; kk++)
        {
            if(a[kk] == 0) cnt_nonk++;
        }
        cout<<max(cnt_nonk, cnt_k)<<endl;
        cnt_nonk = 0;
        cnt_k = 0;
        memset(a, 0, sizeof(a));
    }
    
}