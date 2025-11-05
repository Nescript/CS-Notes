#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 350 + 50;
vector<int> board_score(350, 0);
vector<int> card(5, 0);
vector<int> dp;
int A, B, C, D;

//int dp[45][45][45][45] = {-1};
/*
static inline size_t id(int a, int b, int c, int d) {
    return ((size_t(a) * size_t(B) + size_t(b)) * size_t(C) + size_t(c)) * size_t(D) + size_t(d);
}
*/

int id(int a, int b, int c, int d)
{
    return ((a * B + b) * C + c) * D + d;
}

int N, M;
int get_score(int a, int b, int c, int d)
{
    int dis = (card[1] - a) * 1 + (card[2] - b) * 2 
            + (card[3] - c) * 3 + (card[4] - d) * 4;
    return board_score[dis];
}

int tur(int a, int b, int c, int d)
{
    if(a > card[1] || b > card[2] || c > card[3] || d > card[4]) return -1;
    /*
    if(dp[id(a, b, c, d)] != -1) return dp[id(a, b, c, d)];
    dp[id(a, b, c, d)] = get_score(a, b, c, d) + 
                            max(max(tur(a + 1, b, c, d), tur(a, b + 1, c, d)), 
                                max(tur(a, b, c + 1, d), tur(a, b, c, d + 1)));
    return dp[id(a, b, c, d)];
    */
    const size_t idx = id(a, b, c, d);
    int &memo = dp[idx];
    if (memo != -1) return memo;

    memo = get_score(a, b, c, d) +
           max(
               max(tur(a + 1, b, c, d), tur(a, b + 1, c, d)),
               max(tur(a, b, c + 1, d), tur(a, b, c, d + 1))
           );
    return memo;
}
int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; i++)
    {
        cin>>board_score[i];
    }
    
    int tmp_card;
    for(int j = 0; j < M; j++)
    {
        cin>>tmp_card;
        card[tmp_card]++;
    }
    A = card[1] + 1; B = card[2] + 1; C = card[3] + 1; D = card[4] + 1;
    dp.assign(A * B * C * D, -1);
    dp[id(card[1], card[2], card[3] ,card[4])] = board_score[0];
    cout<<tur(0, 0, 0, 0)<<endl;
}