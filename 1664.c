#include<stdio.h>

int main(){
    int a[11][11],t,m,n;
    for(t=0;t<=10;t++){a[0][t]=0;a[t][0]=0;}
    a[0][0]=1;
    for(m=0;m<=10;m++){
        for(n=1;n<=10;n++){
            if(m<n)a[m][n]=a[m][m];
            else a[m][n]=a[m][n-1]+a[m-n][n];
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        printf("%d\n",a[m][n]);
    }
    return 0;
}
