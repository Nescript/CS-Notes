#include <iostream>
#define MAX_N 110
using namespace std;

int N, M;
char map[MAX_N][MAX_N];
void dfs(int i, int j)
{
    map[i][j] = '.';

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = i + dx;
            int ny = j + dy;
            if (nx > 0 && ny > 0 && nx <= N && ny <= M && map[nx][ny] == 'W') dfs(nx, ny);
        }
    }
    return;
}

int main()
{
    cin>>N>>M;
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin>>map[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (map[i][j] == 'W')
            {
                dfs(i, j);
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}