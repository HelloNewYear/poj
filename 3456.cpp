#include <iostream>
using namespace std;

int main(){
    int a,b,c,d;
    a=8;b=5;c=9;d=7;
    long s,w,x,y,z;
    int f[1000001];
    for(long i=0;i<1000001;i++)f[i]=0;
    for(w=0;1;w++){
        for(x=0;1;x++){
            for(y=0;1;y++){
                for(z=0;1;z++){
                    s=a*w+b*x+c*y+d*z;
                    if(s<1000001)f[s]=1;
                    else{z=0;break;}
                }
                s=a*w+b*x+c*y+d*z;
                if(s>1000000){y=0;z=0;break;}
            }
            s=a*w+b*x+c*y+d*z;
            if(s>1000000){x=0;y=0;z=0;break;}
        }
        s=a*w+b*x+c*y+d*z;
        if(s>1000000)break;
    }
    s=0;
    for(long i=0;i<1000001;i++)s+=f[i];
    cout<<1000001-s;
    return 0;
}
