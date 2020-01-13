#include<stdio.h>
struct player{
    int number;
    char name[20];
    char role;
    char time[100];
	int flag;
}p[22];

bool cmp(player a,player b)
{
    return a.num<b.num;
}

int main(){
    int D=0,M=0,S=0,G=0;
	int i,j,k;
    for(i=0;i<22;i++){
        scanf("%d %s %c %[^\n]",&p[i].number,p[i].name,&p[i].role,p[i].time);
        if(p[i].role == 'D') D++;
        else if(p[i].role == 'M') M++;
        else if(p[i].role == 'S') S++;
        else G++;
    }
    char team[5];
    scanf("%s",team);
    int d=team[0]-'0',m=team[2]-'0',s=team[4]-'0';
    if(G<1 || D<d || M<m || S<s){
        printf("IMPOSSIBLE TO ARRANGE\n\n");
    }
    sort(p,p+22,cmp);
	for(i=0;i<22;i++){
		printf("%d %s %c %s\n",p[i].number,p[i].name,p[i].role,p[i].time);
	}
	
    return 0;
}
