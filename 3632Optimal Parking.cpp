#include<stdio.h>
int main(){
    int t,i,j,min,max,n,a[20];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++)scanf("%d",&a[j]);
        min=max=a[0];
        for(j=0;j<n-1;j++){
            if(min>a[j+1])min=a[j+1];
            if(max<a[j+1])max=a[j+1];
        }
        printf("%d\n",2*(max-min));
    }
    return 0;
}
