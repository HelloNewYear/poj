#include<stdio.h>
#include<string.h>

int a,b,c,d,f[2000002];
int main(){
    long n,m,s,i;
    scanf("%ld",&n);
    while(n--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        memset(f,0,sizeof(f));
        f[0]=1;
        s=0;
        m=-1;
        for(i=0;i<1050001;i++){
            if(i<=1000000&&!f[i])s++;
            if(f[i])f[i+a]=f[i+b]=f[i+c]=f[i+d]=1;
            else m=i;
        }
        printf("%ld\n%ld",s,m>1000000?-1:m);
        if(n!=0)printf("\n");
    }
    return 0;
}
