//猜测：牛在人左边的时候直接输出距离差，因为只能一步一步走没法传送
//猜测：从牛的位置倒推
//猜测：宽度优先搜索可以找到最短路线

#include <iostream>
#include <queue>
const int MAXN = 100010;
const int INF = 200010;
int N,K;
using namespace std;
queue<int> search_que;
int d[MAXN];
int dx[2] = {-1, 1}; 
int BFS()
{
    int nx;
    int current;
    while(search_que.size())
    {
        current = search_que.front();
        //cout<<"now we are about to get front "<<current<<endl;
        search_que.pop();
        if(2 * current == K || current + 1 == K || current - 1 == K)
        {
            return d[current] + 1;
        }
        for(int i = 0; i <= 1; i++)
        {
            nx = dx[i] + current;
            //cout<<"now we get an nx "<<nx<<endl;
            if(nx >= 0 && nx <= 100000 && d[nx] == INF)
            {
                d[nx] = d[current] + 1;
                //cout<<"now we are about to push dnx "<<nx<<endl;
                search_que.push(nx);
            }
        }
        nx = 2 * current;
        if(nx >= 0 && nx <= 100000 && d[nx] == INF)
        {
            d[nx] = d[current] + 1;
            //cout<<"now we are about to push dnx "<<nx<<endl;
            search_que.push(nx);
        }
    }
    //cout<<"now we are about to return dk"<<endl;
    return d[K];
}
int main()
{
    for(int i = 0; i < MAXN; i++)
    {
        d[i] = INF;
    }
    cin>>N>>K;
    if(N==K)
    {
        cout<<"0"<<endl;
        return 0;
    }
    search_que.push(N);
    d[N] = 0;
    cout<<BFS()<<endl;
}