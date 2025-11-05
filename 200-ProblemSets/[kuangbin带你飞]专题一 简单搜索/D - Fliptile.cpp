#include <iostream>
#include <cstring>

using namespace std;
const int MAXN = 20;
int map[MAXN];
//int tmp_map[MAXN][MAXN];
int operate[MAXN];
//用于记录翻转操作

int M,N;
int tmp;

//获取num二进制表示下第x位的数，最低位为0
int GetBit(int num, int x)
{
    num = num >> x;
    return num & 1;
}

//将num二进制的第x位反转，最低位为0
void FlipBit(int &num, int x)
{
    num = num ^ (1 << x);
    return;
}

//根据上一行的情况判断line行x位要不要翻转,operate + map % 2 == 0说明是0，==1说明是1，要翻转
bool ShouldFlip(int line, int x)
{
    //这里不对，还要看上左右
    int check_line = line - 1;
    int state = 0;
    state += GetBit(operate[check_line], x);
    if(check_line >= 1) state += GetBit(operate[check_line - 1], x);
    if(x > 0) state += GetBit(operate[check_line], x - 1);
    if(x < N - 1) state += GetBit(operate[check_line], x + 1);
    state += GetBit(map[check_line], x);
    //cout<<"now state is "<<endl;
    return state % 2;
}

void output()
{
    for(int i = 1; i <= M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(GetBit(operate[i], j)) cout<<"1"<<" ";
            else cout<<"0"<<" ";
        }
        cout<<endl;
    }
    return;
}

void output_map()
{
    for(int i = 1; i <= M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(GetBit(map[i], j)) cout<<"1"<<" ";
            else cout<<"0"<<" ";
        }
        cout<<endl;
    }
    return;
}

void test()
{
    for(int i = 0; i <= (1 << N) - 1; i++) //i<=2^{N}-1
    {
        cout<<"now i is "<<i<<endl;
        operate[1] = i;
        cout<<"should line2 num 1(left) flip? "<<ShouldFlip(2, 0)<<endl;
    }
}
void onlyOne()
{
    bool tag = 1;
    for(int i = 0; i <= (1 << N) - 1; i++) //i<=2^{N}-1
    {
        operate[1] = i;
        for(int kk= 0; kk < N; kk++)
        {
            if(ShouldFlip(2, kk))
            {
                tag = false;
                break;
            }
        }
        if(tag) {output(); return;}
        tag = 1;
    }
    cout<<"IMPOSSIBLE"<<endl;
}

void solve()
{
    //首先枚举第一行,i就是了
    bool tag = 1; 
    for(int i = 0; i <= (1 << N) - 1; i++) //i<=2^{N}-1
    {
        //cout<<i<<" ";
        operate[1] = i;
        for(int j = 2; j <= M; j++)
        {
            for(int k = 0; k < N; k++)
            {
                if(ShouldFlip(j, k)) 
                {
                    FlipBit(operate[j], k);
                    //output();
                    //cout<<"now the operate is "<<operate[j]<<" and j and k is "<<j<<" "<<k<<endl;
                }
            }
            if(j == M)
            {
                for(int kk= 0; kk < N; kk++)
                {
                    if(ShouldFlip(M + 1, kk))
                    {
                        tag = false;
                        break;
                    }
                }
                if(tag) {output(); return;}
            }
            //output();
            //cout<<endl;
        }
        tag = 1;
        memset(operate, 0, sizeof(operate));
    }
    cout<<"IMPOSSIBLE"<<endl;
}
int main()
{    
    cin>>M>>N;
    
    for(int i = 1; i <= M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin>>tmp;
            if(tmp)
            {
                map[i] += 1 << j;
            }           
        }
    }
    if(M == 1){
        onlyOne();
        return 0;
    }
    //test();
    //output_map();
    solve();
    //cout<<FlipBit(4, 0)<<endl;
}