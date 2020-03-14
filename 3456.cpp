#include <iostream>
using namespace std;

int a,b,c,d;
bool f[1000001];

bool judge(long i){
    if(i<0)return false;
    if(f[i]==true)return true;
    if(i==0||i==a||i==b||i==c||i==d){f[i]=true;return true;}
    f[i]=judge(i-a)|judge(i-b)|judge(i-c)|judge(i-d);return f[i];
}

int main(){
    long n,m,s,i;
    cin>>n;
    while(n--){
        cin>>a>>b>>c>>d;
        m=1000000;
        for(i=1;i<m+1;i++)f[i]=false;
        s=0;
        for(i=m;i>0;i--)
            if(f[i]!=true){
                judge(i);
                if(f[i]!=true)s++;
            }
        cout<<s<<endl;
        m=2*s-1;
        if(m<=1000000)cout<<m<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
