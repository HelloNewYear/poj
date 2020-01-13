#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct player{
    int number;
    char name[20];
    char role;
    int time;
    int flag;
}p[22];

bool cmpnumber(player a,player b){
    return a.number<b.number;
}

bool cmpflag(player a,player b){
    return a.flag>b.flag;
}

int get_time(char s[]){
    int len=strlen(s),i;
    int t1,t2,flag,sum;
    t1=t2=0;
    flag=0;
    sum=0;
    for(i=0;i<len;i++){
        if(s[i]==' '){
            sum+=(t2-t1+1);
            flag=t1=t2=0;
            continue;
        }
        if(s[i]=='-'){
            flag=1;
            continue;
        }
        if(!flag)
            t1=t1*10+s[i]-'0';
        else
            t2=t2*10+s[i]-'0';
    }
    sum+=t2-t1+1;
    return sum;
}

int main(){
    char str[500];
    int D=0,M=0,S=0,G=0,i;
    for(i=0;i<22;i++){
        scanf("%d %s %c %[^\n]",&p[i].number,p[i].name,&p[i].role,str);
        p[i].time=get_time(str);
        if(p[i].role == 'D')D++;
        else if(p[i].role == 'M')M++;
        else if(p[i].role == 'S')S++;
        else G++;
    }
    char team[5];
    scanf("%s",team);
    int g=1,d=team[0]-'0',m=team[2]-'0',s=team[4]-'0';
    if(G<g || D<d || M<m || S<s){
        printf("IMPOSSIBLE TO ARRANGE\n\n");
    }
    scanf("%d",&i);
    sort(p,p+22,cmpnumber);
    D=d,M=m,S=s,G=g;
    for(i=0;i<22;i++){
        if(G && p[i].role == 'G'){
            G--;
            p[i].flag=12-g+G;
        }
        else if(D && p[i].role == 'D'){
            D--;
            p[i].flag=12-g-d+D;
        }
        else if(M && p[i].role == 'M'){
            M--;
            p[i].flag=12-g-d-m+M;
        }
        else if(S && p[i].role == 'S'){
            S--;
            p[i].flag=12-g-d-m-s+S;
        }
        else p[i].flag=0;
    }
    //captain
    int max_time=-1,max_time_number;
    for(i=0;i<22;i++){
        if(p[i].flag){
            if(p[i].time>max_time){
                max_time=p[i].time;
                max_time_number=i;
            }
        }
    }
    p[max_time_number].flag=12;

    sort(p,p+22,cmpflag);
    for(i=0;i<22;i++){
        if(p[i].flag != 0){
            printf("%d %s %c\n",p[i].number,p[i].name,p[i].role);
        }
    }

    return 0;
}
