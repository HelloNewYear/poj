#include<stdio.h>
int main(){
	int p,e,i,d;
	int x=1,y=1;
	scanf("%d%d%d%d",&p,&e,&i,&d);
	while(d!=-1){
		while((x+d-p)%23!=0||(x+d-e)%28!=0||(x+d-i)%33!=0)x++;
		printf("Case %d: the next triple peak occurs in %d days.\n",y,x);
		scanf("%d%d%d%d",&p,&e,&i,&d);
		x=1;y++;
	}
	return 0;
}

		