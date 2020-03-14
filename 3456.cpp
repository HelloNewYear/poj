#include <iostream>
using namespace std;

int a,b,c,d;
bool f[1000001];

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

bool judge(long i){
    if(i<0)return false;
    if(i==0||i==a||i==b||i==c||i==d){f[i]=true;return true;}
    f[i]=judge(i-a)|judge(i-b)|judge(i-c)|judge(i-d);return f[i];
}

int main(){
    long n,m,s,i;
    cin>>n;
    while(n--){
        cin>>a>>b>>c>>d;
        m=min(F(a,b),F(a,c),F(a,d),F(b,c),F(b,d),F(c,d));
        for(i=1;i<m+1;i++)f[i]=false;
        s=0;
        for(i=m;i>0;i--)
            if(!f[i]){
                judge(i);
                if(!f[i])s++;
            }
        cout<<s<<endl;
        m=2*s-1;
        if(m<=1000000)cout<<m<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
