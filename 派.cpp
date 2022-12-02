#include<stdio.h>
void main()
{
	int i=1,n;
	double pai=0;
	printf("please imput a number:");
	scanf("%d",&n);
	while(i<=n)
	{
		pai+=4.0/(2*i-1)-4.0/(2*i+1);//pai=4*(1-1/3+1/5-1/7+1/9-бнбн)
		i=i+2;
	}
	printf("Pai=%lf\n",pai);
}






	