#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 200050;

int t;
int n;
int a[MAXN];

int cnt_0 = 0;
int num_test[MAXN];
int findTheRestNum()
{
    for(int i = 1; i <= n; i++)
    {
        if(!num_test[i]) return i;
    }
}
int main()
{
    memset(num_test, 0 ,sizeof(num_test));
    cin>>t;
    int arr_left = -1, arr_right = -1;
    int arr_r_without_0 = -1;
    int arr_l_without_0 = -1;
    int tmp;
    for(int i = 0; i < t; i++)
    {
        cin>>n;
        for(int j = 1; j <= n; j++)
        {
            cin>>a[j];
            if(a[j] == 0) cnt_0++;
            if(a[j] != 0) num_test[a[j]]++;
            if(a[j] != j && j > arr_r_without_0 && a[j] != 0)
            {
                arr_r_without_0 = j;
            }
            if(a[j] != j && arr_l_without_0 == -1 && a[j] != 0)
            {
                arr_l_without_0 = j;
            }
            if(a[j] != j && arr_left == -1)
            {
                arr_left = j;
            }
            if(a[j] != j && j > arr_right)
            {
                arr_right = j;
            }
        }
        if(cnt_0 == 1)
        {
            if(arr_l_without_0 == -1 && arr_r_without_0 == -1)
            {
                cout<<"0"<<endl;
            }
            else if((a[arr_left] == 0 && findTheRestNum() == arr_left) || 
                    (a[arr_right] == 0 && findTheRestNum() == arr_right))
            {
                cout<<arr_r_without_0 - arr_l_without_0 + 1<<endl;
            }
            else if(arr_right > arr_left && arr_left != -1)
            {
                cout<<arr_right - arr_left + 1<<endl;
            }
        }
        else if(arr_right > arr_left && arr_left != -1)
        {
            cout<<arr_right - arr_left + 1<<endl;
        }
        else cout<<"0"<<endl;
        arr_left = -1;
        arr_right = -1;
        arr_r_without_0 = -1;
        arr_l_without_0 = -1;
        cnt_0 = 0;
        memset(num_test, 0 ,sizeof(num_test));
    }
}