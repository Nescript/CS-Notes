#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int a[MAXN];
int b[MAXN];//第二问
int num[MAXN];

bool cmp(const int &a, const int &b)
{
    return a>b;
}

void output_a(int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void output_b(int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n = 0;
	while(cin>>num[n])
    {
		n++;
	}
    //cout<<n;
    //
    //cin>>n;
    int a_arr = 0;
    int b_arr = 0;
    /*
    for(int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";
    }
    */
    a[0] = num[0];
    b[0] = num[0];
    
    for(int j = 1; j < n; j++)
    {
        if(num[j] <= a[a_arr])
        {
            a_arr++;
            a[a_arr] = num[j];
        }
        else 
        {
            //a[lower_bound(a, a + a_arr + 1, num[j], [](int x, int y){ return x > y; }) - a] = num[j];
            a[upper_bound(a, a + a_arr + 1, num[j], cmp) - a] = num[j];
        }
        if(num[j] > b[b_arr])
        {
            b_arr++;
            b[b_arr] = num[j];
        }
        else
        {
            b[lower_bound(b, b + b_arr + 1, num[j]) - b] = num[j];
        }
        //output_b(b_arr + 1);
    }
    cout<<a_arr + 1<<endl;
    cout<<b_arr + 1<<endl;
}
