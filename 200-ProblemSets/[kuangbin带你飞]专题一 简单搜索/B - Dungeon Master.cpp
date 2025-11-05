#include <iostream>
#include <queue>
using namespace std;
const int MAX_D = 40000;
char map[32][32][32];

typedef pair<int, int> RC;
typedef pair<int, RC> LRC;

int dx[6] ={-1, 0, 1, 0, 0, 0}; 
int dy[6] ={0, -1, 0, 1, 0 ,0};
int dz[6] ={0, 0, 0, 0, 1, -1};
LRC end_point;
LRC start_point;
LRC current;
int d[32][32][32];

queue<LRC> search_que;
int L,R,C;
int cnt=0;
void output_location(LRC k)
{
    cout<<"now the location is "<<k.first<<","<<k.second.first<<","<<k.second.second<<endl;
}
void solve()
{
    int x,y,z;
    //压进队列的要求：不超过边界，没有访问过，
    while(search_que.size())
    {
        //cout<<"Now we go into the while loop"<<endl;
        current = search_que.front();
        search_que.pop();
        //cout<<"Now we pop one item from the que"<<endl;
        //cout<<endl;
        //output_location(current);
        cnt++;
        for(int i = 0; i < 6; i++)
        {
            z = current.first + dz[i];
            x = current.second.first + dx[i];
            y = current.second.second + dy[i];
            if(map[z][x][y] == 'E')
            {
                d[z][x][y] = d[current.first][current.second.first][current.second.second] + 1;
                //cout<<"we are going out because we meet the end"<<endl;
                while(search_que.size())
                {
                    search_que.pop();
                }
                return;
            }
            if(z >= 0 && z < L &&
               x >= 0 && x < R &&
               y >= 0 && y < C &&
               map[z][x][y] == '.' &&
               d[z][x][y] == MAX_D)
            {
                d[z][x][y] = d[current.first][current.second.first][current.second.second] + 1;
                search_que.push(LRC(z, RC(x, y)));
                //cout<<"Now we push one item to the que with d is "<<d[z][x][y]<<endl;
                //output_location(LRC(z, RC(x, y)));
                //跳出条件，遇到终点，否则队列跑完还没出来就是trapped
            }
        }
    }
    return;
}
//宽度优先搜索
//需要用到队列
//还是循环的问题
int main()
{
    cin>>L>>R>>C;
    while(L!=0)
    {
        for(int k = 0; k < L; k++)
        {
            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    cin>>map[k][i][j];
                    d[k][i][j] = MAX_D; 
                    if(map[k][i][j] == 'S')
                    {
                        start_point = LRC(k,RC(i,j));
                        d[k][i][j] = 0;
                        search_que.push(start_point);
                    }
                    if(map[k][i][j] == 'E')
                    {
                        end_point = LRC(k,RC(i,j));
                        //output_location(end_point);
                    }
                }
            }
        }
        solve();
        //cout<<d[end_point.first][end_point.second.first][end_point.second.second]<<endl;
        if(d[end_point.first][end_point.second.first][end_point.second.second] != MAX_D)
        {
            cout<<"Escaped in ";
            cout<<d[end_point.first][end_point.second.first][end_point.second.second];
            cout<<" minute(s)."<<endl;
        }
        else 
        {
            cout<<"Trapped!"<<endl;
        }
        cin>>L>>R>>C;
    }
}