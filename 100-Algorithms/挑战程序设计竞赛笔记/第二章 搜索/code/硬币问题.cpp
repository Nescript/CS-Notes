#include <iostream>


using namespace std;
const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];
int k;
int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin>>C[i];
    }
    cin>>k;
    int num = 0;
    for (int i = 5; i >= 0; i--)
    {
        num += min(k / V[i], C[i]);
        k -= V[i] * min(k / V[i], C[i]);
    }
    cout<<num;
    return 0; 
}