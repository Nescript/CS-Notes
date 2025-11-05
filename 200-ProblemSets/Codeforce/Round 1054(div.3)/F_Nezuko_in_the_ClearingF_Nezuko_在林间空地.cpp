#include <iostream>
#include <cstring>
using namespace std;

long long cul_cost(long long n)//from 1 to n 
{
    return (1 + n) * n / 2;
}
long long solve(long long hp, long long ans, long long d)
{
    if(hp == 1)
    {
        return solve(2, 1, d);
    }
    if(hp == 2 || hp == 3)
    {
        if(d == 1)
        {
            return ans + 1;
        }
        return ans += d * 2 - 1;
    }
    for(long long j = 1; j <= hp; j++)
    {
        if(cul_cost(j) >= hp)
        {
            //cout<<"now hp is "<<hp<<" and j is "<<j<<endl;
            if((j - 1) >= d)
            {
                return ans += d;
            }
            d -= (j - 1);
            ans += (j - 1) + 1;
            hp -= cul_cost(j - 1);
            hp++;
            break;
        }
    }
    return solve(hp, ans, d);
}

int main()
{
    //memset(cul, 0, sizeof(cul));
    long long n;
    long long d;
    cin>>n;
    long long h;
    for(long long i = 0; i < n; i++)
    {
        cin>>h>>d;
        cout<<solve(h, 0, d)<<endl;
    }
}