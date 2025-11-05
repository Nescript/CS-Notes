#include <iostream>
using namespace std;
int main()
{
    //猜测：实际上是要我输出所有交叉点的数量
    //猜测；实际上就是输出激光的数量
    int t;
    cin>>t;
    int n,m,x,y;
    int tmp;
    for(int i=0;i<t;i++){
        cin>>n>>m>>x>>y;
        for(int j=0;j<n;j++)
        {
            cin>>tmp;
        }
        for(int k=0;k<m;k++)
        {
            cin>>tmp;
        }
        cout<<n+m<<endl;
    }
}