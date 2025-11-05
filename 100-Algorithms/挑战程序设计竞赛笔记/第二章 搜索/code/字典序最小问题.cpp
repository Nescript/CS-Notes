#include <iostream>

using namespace std;
const int MAX_N = 2010;
int N;
char S[MAX_N],T[MAX_N];
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>S[i];
    }
    int arr_front = 0;
    int arr_back = N - 1;

    while (arr_front <= arr_back)
    {
        bool front = false;
        for (int i = 0; arr_front + i <= arr_back; i++)
        {
            if (S[arr_front + i] < S[arr_back - i])
            {
                front = true;
                break; 
            }
            else if (S[arr_back - i] <S[arr_front] +i)
            {
                front =false;
                break;
            }
        }
        if (front) putchar(S[arr_front++]);
        else putchar(S[arr_back--]);
    }
}