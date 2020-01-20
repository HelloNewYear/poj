#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    const int INF = 1e9+5;
    int dp[1001][51];
    int op,B,M,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&op,&B,&M);
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=M;i++) dp[i][1] = i;
        for(int i=1;i<=B;i++) dp[1][i] = 1;
        for(int i=1;i<=M;i++){
            for(int j=2; j<=B; j++){
                dp[i][j] = INF;
                for(int k=1; k<=i; k++) dp[i][j] = min(dp[i][j],max(dp[k-1][j-1],dp[i-k][j])+1);
            }
        }
        printf("%d %d\n",op, dp[M][B]);
    }
    return 0;
}
