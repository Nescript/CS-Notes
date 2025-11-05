#include <iostream>
#include <numeric>

const int MAXN = 100 + 10;
//规则1：一个数和左右数之和的差值不能大于2
//规则2：与自身左右数之和相等的数不得多于1个
int t;
int num[MAXN], res[MAXN];
int n;

using namespace std;
int main()
{
    int tmp;
    int cnt_r2 = 0;
    cin>>t;
    int arr_l = 0; 
    bool tag = 1;
    int arr_r;
    int current_num = 1;
    for(int i = 0; i < t; i++)
    {
        cin>>n;
        for(int j = 0; j < n; j++)
        {
            cin>>num[j];
        }
        arr_l = 0;
        tag = 1;
        arr_r = n - 1;
        current_num = 1;
        for(int k = 1; k <= n; k++)
        {
            if(num[arr_l] == current_num)
            {
                arr_l++;
                current_num++;
            }
            else if(num[arr_r] == current_num)
            {
                arr_r--;
                current_num++;
                //cout<<"current num is "<<current_num<<endl;
            }
            else 
            {
                cout<<"NO"<<endl;
                tag = 0;
                break;
            }
        }
        if(tag) cout<<"YES"<<endl;
    }
}