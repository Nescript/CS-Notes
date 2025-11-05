//简化题目：首先每一层只能用一次
//对第一颗棋子，我们搜索的范围是第 1 行到第 n-k 行间
//对第二颗棋子，当第一颗棋子确定在第一行时，搜索范围应该是第 2 行到第 n-1-k 行间
//对第二课棋子，当第一颗棋子确定在第 x 行时，搜索范围是第 x+1 行到第 n-x-k 行间
//所以应该是按棋子来转移
//所以不是以棋子为转移，而是以剩余棋子数和剩余行数转移
//猜测：像处理矩阵一样处理它：转化为对角阵
#include <iostream>
#include <stack>
using namespace std;
char map[9][9];
long long ans;
//int recoder[9];
//stack<int> recoder;
//用来记录之前选择的路线,但是数组不行，要用栈
//或者用map的[][8]来存？
int n,k;
int cnt = 0;
//recoder要随着return回退
void check_markline()
{
    for(int p = 0; p < n; p++)
    {
        cout<<map[8][p]<<" ";
    }
    cout<<endl;
}
void check_line(int line)
{
    for(int p = 0; p < n; p++)
    {
        cout<<map[line][p]<<" ";
    }
    cout<<endl;
}
void solve(int left_piece, int line)
{
    //现在的思路是：line表示当前要搜索的行
    //弹出条件：剩余棋子数为0
    if(left_piece == 0) {
        for(int l = 0; l < n; l++)
        {
            if(map[line][l] == '#' && map[8][l] == 'n')//u代表用了
            {
                ans++; 
                //cout<<"Now we found an ans with the last one in line "<<line<<endl;
                //check_markline();
            }
            else
            {
                //cout<<"we found no place avalible for the last piece"<<endl;
                //check_line(line);
            }
        }
        return;
    }
    //出现问题猜测：我们没有为最后一行的那个棋子安排去处
    for(int l = 0; l < n; l++)
    {
        if(map[line][l] == '#' && map[8][l] != 'u')//u代表用了
        {
            map[8][l] = 'u';
            for(int i = line + 1; i <= n - left_piece; i++)//这一部分思考
            { 
                //cout<<"We are going to the line "<<i<<" with " <<left_piece-1<<" pieces and markline belike:"<<endl;
                //check_markline();
                solve(left_piece - 1, i);
            }
            map[8][l] = 'n';
        }
    }
    //弹出条件：当前搜索的这一行没有可以放的位置
    return;
}
int main()
{
    cin>>n>>k;
    while(n != -1)
    {
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>map[i][j];
            }
            map[8][i] = 'n';
        }
        for(int l = 0; l <= n-k; l++) solve(k - 1 , l);
        cout<<ans<<endl;
        cin>>n>>k;
    }
    return 0;
}



/*
bool is_useable(int column)
{
    for(int i = 0; i <= n; i++)
    {
        if(recoder[i] == column) return false;
    }
    return true;
}
*/