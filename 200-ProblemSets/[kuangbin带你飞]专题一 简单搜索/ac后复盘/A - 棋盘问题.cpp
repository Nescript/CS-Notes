#include <iostream>
using namespace std;
char map[9][9];
long long ans;
int n,k;
int cnt = 0;
void solve(int left_piece, int line)
{
    for(int i = line; i <= n - left_piece; i++)
    {
        for(int l = 0; l < n; l++)
        {
            if(map[i][l] == '#' && map[8][l] != 'u')
            {
                if(left_piece == 1) ans++;
                else
                {
                    map[8][l] = 'u';
                    solve(left_piece - 1, i + 1);
                    map[8][l] = 'n';
                }
            }
        }
    }
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
        solve(k , 0);
        cout<<ans<<endl;
        cin>>n>>k;
    }
    return 0;
}

//首先我们采用的是深度优先搜索，每一行每一行往下看（这是因为我们知道这一行一旦放了一个棋子就不能用了）
//被使用过的列我们通过map[8][]来标记，当然也有别人的做法是另开一个数组看有没有用
//在考虑状态回溯的时候，我们知道每一列只能用一次，这意味着我们只需要在确定“放在这一列”的时候标记，然后回溯的时候清除标记即可
//要注意递归函数的设计，我们这里就遇到了第一列的位置要另外搜索，以及最后一列没有安排位置的问题

//相比原本的代码，这里修改了递归函数，使得第一个棋子也可以直接在函数内搜索放在哪一行
//具体来说，之前的代码的solve接受“放了这个棋子还剩几个”以及“这个棋子放哪一行”
//现在改成了更符合直觉的“这个棋子从第几行开始放”和“包括这个棋子在内还有几个棋子”

//我觉得棋盘上搜索的题目，除了真的是走迷宫那种用广搜做的，很多时候会设法转换成一行一行来看
//不然的话深度优先搜索难以在符合题目要求的同时解决棋盘上的搜索问题
//后面的D题也是同理，但有很多可以研究的新技术，比如哈希表