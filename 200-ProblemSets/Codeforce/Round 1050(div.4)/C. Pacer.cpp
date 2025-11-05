#include <iostream>
using namespace std;
int main()
{
    //猜测：就是要判断奇偶，能跑就跑
    int t;
    cin>>t;
    int n,m;
    int score=0;
    int last_place=0,current_place=0;
    int last_time=0,current_time=0;
    int time_gap;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        for(int j=0;j<n;j++)
        {
            cin>>current_time;
            cin>>current_place;
            time_gap=current_time-last_time;
            if(current_place == last_place)
            {
                if(time_gap%2==0)
                {
                    score += time_gap;
                    //cout<<"now the score is "<<score<<endl;
                }
                else 
                {
                    score += (time_gap-1);
                    //cout<<"now the score is "<<score<<endl;
                }
            }
            else
            {
                if(time_gap%2==0)
                {
                    score += (time_gap-1);
                    //cout<<"now the score is "<<score<<endl;
                }
                else 
                {
                    score += time_gap;
                    //cout<<"now the score is "<<score<<endl;
                }
            }
            last_place=current_place;
            last_time=current_time;
        }
        score += (m-last_time);
        cout<<score<<endl;
        score = 0;
        last_place = 0;
        last_time = 0;
    }
}