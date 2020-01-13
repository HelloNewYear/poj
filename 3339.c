#include<stdio.h>
struct player{
    int number;
    char name[20];
    char role;
    char time[100];
}p[22],t[12];

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
    
    for(i=0;i<22;i++){
		if(p[i].role == 'G') t[1]=p[i];
		break;
	}
	for(j=i+1;j<22;j++){
		if(p[j].role == 'G' && p[j].number < t[1].number) t[1]=p[j];
	}
	printf("%d %s %c",t[1].number,t[1].name,t[1].role);
	
    return 0;
}