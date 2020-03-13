#include <iostream>
using namespace std;

long F(long x, long y){
    if(x==y)return 1000000;
    else return x*y-x-y;
}

long min(long a, long b, long c, long d, long e, long f){
    long g=a;
    if(g>b)g=b;
    if(g>c)g=c;
    if(g>d)g=d;
    if(g>e)g=e;
    if(g>f)g=f;
    if(g<1000000)return g;
    else return 1000000;
}

int main(){
    long a,b,c,d;//输入的4个数
    long m;//最小的不能表示的数
    a=8;b=5;c=9;d=7;
    a=5;b=8;c=5;d=5;
    a=1938;b=1939;c=1940;d=1937;
    m=min(F(a,b),F(a,c),F(a,d),F(b,c),F(b,d),F(c,d));
    long f[m+1],i;//循环变量
    for(i=0;i<m+1;i++)f[i]=0;
    long w,x,y,z;//系数
    long s;//和
    for(w=0;1;w++){
        for(x=0;1;x++){
            for(y=0;1;y++){
                for(z=0;1;z++){
                    s=a*w+b*x+c*y+d*z;
                    if(s>m){z=0;break;}
                    else f[s]=1;
                }
                s=a*w+b*x+c*y+d*z;
                if(s>m){y=0;z=0;break;}
            }
            s=a*w+b*x+c*y+d*z;
            if(s>m){x=0;y=0;z=0;break;}
        }
        s=a*w+b*x+c*y+d*z;
        if(s>m)break;
    }
    s=0;
    for(i=1;i<m+1;i++)s+=f[i];
    cout<<m-s<<endl;
    i=m;
    while(i){
        if(f[i]!=1){cout<<i;break;}
        i--;
    }
    return 0;
}
