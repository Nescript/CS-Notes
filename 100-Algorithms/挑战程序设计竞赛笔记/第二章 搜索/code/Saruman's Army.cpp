#include <iostream>
#include <algorithm>
const int MAX_N = 1010;
using namespace std;
int N,R;
int ans = 0;
int X[1010];
int main()
{
    cin>>N;
    cin>>R;
    for (int i = 0; i < N; i++)
    {
        cin>>X[i];
    }
    sort(X, X + N);
    int left;
    int i = 0;
    while (i < N)
    {
        left = X[i];
        while (i < N && left + R >= X[i]) i++;
        int P = X[i - 1];
        while (i < N && X[i] <= P + R) i++;
        ans++;
    }
    cout<<ans<<endl;
}