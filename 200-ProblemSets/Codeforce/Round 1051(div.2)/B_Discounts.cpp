#include <iostream>
#include <algorithm>
#include <numeric>
const int MAXN = 200000 + 100;
using namespace std;
long long price[MAXN], discount[MAXN], res[MAXN];

int main()
{
    int t;
    int n,k;
    cin>>t;
    int num;
    int discount_arr = 0;
    long long ans = 0;
    for(int i = 0; i < t; i++)
    {
        cin>>n>>k;
        discount_arr = 0;
        ans = 0;
        for(int j = 0; j < n; j++)
        {
            cin>>price[j];
        }
        for(int kk = 0; kk < k; kk++)
        {
            cin>>discount[kk];
        }
        sort(price, price + n);
        sort(discount, discount + k);
        partial_sum(price, price + n, res);
        num = n;
        n--;
        
        while(num)
        {
            if(discount_arr < k && discount[discount_arr] <= num)
            {
                //cout<<"now n is "<<n<<endl;
                ans += res[n] - res[n - discount[discount_arr] + 1];
                //cout<<"now resn is "<<res[n]<<endl;
                //cout<<"now ans is "<<ans<<" and disnum is "<<discount[discount_arr]<<endl;
                n -= discount[discount_arr];
                num -= discount[discount_arr];
                discount_arr++;
            }
            else 
            {
                ans += res[n];
                num = 0;
            } 
        }
        cout<<ans<<endl;

    }
}