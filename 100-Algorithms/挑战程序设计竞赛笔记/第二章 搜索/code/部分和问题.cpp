#include <iostream>
#define MAXNUM 21
using namespace std;
int N,k;
int num[MAXNUM];
bool dfs(int n, int sum)
{
    if (n == N) return sum == k;
    if (sum > k) return false;
    if (sum + num[n] == k) return true;
    if (dfs(n + 1, sum)) return true;
    if (dfs(n + 1, sum + num[n])) return true;
    return false;
}
void solve()
{
    if (dfs(0, 0)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        cin>>num[i];
    }
    cin>>k;
    solve();
}