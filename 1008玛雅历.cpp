#include<stdio.h>
#include<string.h>
int main(){
	char *HaabDay[20]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
	char *Tzolkin[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
	int n,i,j,d,y,days;
	char *s;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		//getchar();
		scanf("%d %s %d",&d,s,&y);
		/*
		scanf("%d",&d);
		getchar();
		//getchar();
		scanf("%s",s);
		getchar();
		scanf("%d",&y);
		for(j=0;j<20;j++){
			if(strncmp(HaabDay[j],s,strlen(s)))
				break;;
		}
		days=d+1+(j+1)*20+y*365;
		printf("%d %s %d",days%260/20+1,Tzolkin[days%260%20-1],days/260);
		*/
	}
	return 0;
}