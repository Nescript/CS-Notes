#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000100;
int main()
{
    int t;
    cin>>t;
    int n,m,x,y;
    long long cnt_odd[MAXN];
    long long cnt_even[MAXN];
    long long odd_arr = -1;
    long long even_arr = -1;
    long long tot_dandelions = 0;
    long long tot_even = 0;
    long long tmp;
    for(int i = 0; i < t; i++)
    {
        cin>>n;
        //cout<<"Now we got an n"<<endl;
        for(int j = 0; j < n; j++)
        {
            cin>>tmp;
            //cout<<"Now we got an tmp"<<endl;
            if(tmp % 2 == 0)
            {
                //cout<<"this tmp is an even"<<endl;
                cnt_even[++even_arr] = tmp; 
                tot_even += tmp;
            }
            else 
            {
                cnt_odd[++odd_arr] = tmp;
                //cout<<"this tmp is an odd"<<endl;
                //cout<<"(input)the odd_arr is "<<odd_arr<<endl;
            }
        }
        //sort(cnt_even, cnt_even + even_arr);
        if(odd_arr == -1)
        {
            cout<<"0"<<endl;
            tot_dandelions = 0;
            tot_even = 0;
            odd_arr = -1;
            even_arr = -1;
            continue;
        }
        sort(cnt_odd, cnt_odd + odd_arr + 1);
        //cout<<"Now we finished the sort"<<endl;
 
        //cout<<"the odd_arr is "<<odd_arr<<endl;
        if((odd_arr+1)%2==0)
        {
            for(int l = odd_arr; l > odd_arr/2; l--)
            {
                tot_dandelions += cnt_odd[l];
                //cout<<"now the odd "<<cnt_odd[l]<<" had been added into tot"<<endl;
            }
            tot_dandelions += tot_even;
            cout<<tot_dandelions<<endl;
            tot_dandelions = 0;
            tot_even = 0;
            odd_arr = -1;
            even_arr = -1;
        }
        else
        {
            for(int l = odd_arr; l >= odd_arr/2; l--)
            {
                tot_dandelions += cnt_odd[l];
                //cout<<"now the odd "<<cnt_odd[l]<<" had been added into tot"<<endl;
            }
            tot_dandelions += tot_even;
            cout<<tot_dandelions<<endl;
            tot_dandelions = 0;
            tot_even = 0;
            odd_arr = -1;
            even_arr = -1;
        } 
    }
}