#include <iostream>
using namespace std;
int main()
{
    int mana, s, t;
    cin>>mana>>s>>t;

    int run = 0;
    int tp = 0;
    for(int i = 1; i <= t; i++)
    {
        if(mana >= 10)
        {
            tp += 60;
            mana -= 10;  
        } 
        else mana += 4;
        run += 17;
        if(tp >= run) run = tp;
        if(tp >= s || run >= s)
        {
            cout<<"Yes"<<endl;
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    cout<<max(run, tp)<<endl;
}