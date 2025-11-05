#include <iostream>
#include <algorithm>
const int MAX_N = 100010;
using namespace std;
pair<int, int> jobs[MAX_N];
int T[MAX_N], S[MAX_N];
int n;
int Solve()
{
    for (int i = 0; i < n; i++)
    {
        jobs[i].first = T[i];
        jobs[i].second = S[i];
    }
    sort(jobs, jobs + n);
    int ans = 0; int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (t < jobs[i].second)
        {
            t = jobs[i].first;
            ans++;
        }
    }
    return ans;
} 
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>S[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>T[i];
    }
    cout<<Solve()<<endl;
    return 0;
}