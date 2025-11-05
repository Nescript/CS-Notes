#include <iostream>
#include <queue>
const int INF = 0x7ffffff;
const int MAXNUM = 110;
using namespace std;
typedef pair<int, int> P;
char maze[MAXNUM][MAXNUM];
int dis[MAXNUM][MAXNUM];
int sx,sy;
int gx,gy;
int N,M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs()
{
    queue<P> que;
    dis[sx][sy] = 0;
    que.push({sx, sy});

    while(que.size())
    {
        P p = que.front(); que.pop();
        if (p == P(gx, gy)) break;
        //if (p == make_pair(gx, gy)) break;
        //if (p.front == gx && p.second == gy) break;
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx > 0 && ny > 0 && nx <= N && ny <= M && maze[nx][ny] != '#' && dis[nx][ny] == INF) 
            {
                que.push(P(nx, ny));
                dis[nx][ny] = dis[p.first][p.second] + 1;
            }
        }
    }
    return dis[gx][gy];
}
int main()
{
    cin>>N>>M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dis[i][j] = INF;
            cin>>maze[i][j];
            if (maze[i][j] == 'S') 
            {
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
        }
    }
    cout<<bfs()<<endl;
}