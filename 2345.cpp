#include<iostream>
#include<cstring>
using namespace std;
#define MAX_N 256

int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int matrix[MAX_N][MAX_N];    // 增广矩阵
    int ans[MAX_N];              // 解向量
    int n;
    while(~scanf("%d", &n)){
        memset(matrix, 0, sizeof(matrix));
        memset(ans, 0, sizeof(ans));

        int t;
        for(int i = 1; i <= n; ++i){
            while (~scanf("%d", &t) && t != -1){
                matrix[t][i] = 1;
            }
            matrix[i][n + 1] = 1;
        }

        for(int i = 1; i <= n; ++i){
            int col = -1;
            // 从[i, n)行中找到第col列中元素绝对值最大的行记作col
            for(int j = i; j <= n; ++j){
                if(matrix[j][i]){
                    col = j;
                    break;
                }
            }

            for(int j = i; j <= n + 1; j++){
                swap(matrix[i][j], matrix[col][j]);            // 交换第i行和第col行
            }

            // 对于所有的行j (i < j < n)
            for(int j = i + 1; j <= n; j++){
                if(matrix[j][i])                            // 如果m[j][i]不为0，则需要进行消元
                {
                    for(int k = i; k <= n + 1; k++)         // 以期第i行以下的第col列的所有元素都消为0
                    {
                        matrix[j][k] ^= matrix[i][k];       // 具体的步骤就是将第j行的所有元素减去第i行的所有元素乘上一个系数，这个系数即m[j][col] / m[i][col]
                    }
                }
            }
        }

        for(int i = n; i >= 1; --i)                        // 行梯阵式
        {
            ans[i] = matrix[i][n + 1];                     // 简化行梯阵式
            for(int j = i - 1; j >= 1; --j){
                matrix[j][n + 1] ^= (ans[i] & matrix[j][i]);// m[j][n+1] -= ans[i] * m[j][i]
            }
        }

        bool first = true;
        for(int i = 1; i <= n; i++){
            if(ans[i]){
                if(first){
                    printf("%d", i);
                    first = false;
                }
                else{
                    printf(" %d", i);
                }
            }
        }
        puts("");
    }

    /*
    #ifndef ONLINE_JUDGE
        fclose(stdin);
        fclose(stdout);
        system("out.txt");
    #endif
    */
    return 0;
}
