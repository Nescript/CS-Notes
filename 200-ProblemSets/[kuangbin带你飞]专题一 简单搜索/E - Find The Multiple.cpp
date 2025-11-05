//猜测：给出所有质数的满足条件的倍数
//猜测：筛去一些数 10 20 30 40 50 60
//11 111 100 101 1 
//研究了一下时间复杂度发现，好像直接累加就可以了

#include<iostream>

using namespace std;
string num;//给出最后答案
string tmp;//存储过程
void solve(int n)
{
    int tmp_length = 0;
    while(!check_all_binary(tmp_length))
}
bool check_all_binary(int length)
{
    for(int i = 0; i < length; i++)
    {
        if(num[i] != '0' && num[i] != '1')
        {
            return false;
        }
    }
    return true;
}
void output()
{

}
int main()
{
    int n;
    while(n)
    {
        solve(n)
        output();
        cin>>n;
    }
}