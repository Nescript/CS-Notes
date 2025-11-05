#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 350 + 50;
int board_score[350];
int card[5] = {0, 0, 0, 0, 0};
int dp[45][45][45][45] = {-1};
int N, M;
int get_score(int a, int b, int c, int d)
{
    int dis = (card[1] - a) * 1 + (card[2] - b) * 2 
            + (card[3] - c) * 3 + (card[4] - d) * 4;
    return board_score[dis];
}

int tur(int a, int b, int c, int d)
{
    if(a > card[1] || b > card[2] || c > card[3] || d > card[4]) return dp[a][b][c][d] = -1;
    if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
    dp[a][b][c][d] = get_score(a, b, c, d) + 
                            max(max(tur(a + 1, b, c, d), tur(a, b + 1, c, d)), 
                                max(tur(a, b, c + 1, d), tur(a, b, c, d + 1)));
    return dp[a][b][c][d];
}
int main()
{
    memset(dp, -1, sizeof(dp));
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
        dp[card[1]][card[2]][card[3]][card[4]] = -1; 
    }
    dp[card[1]][card[2]][card[3]][card[4]] = board_score[0];
    cout<<tur(0, 0, 0, 0)<<endl;
}