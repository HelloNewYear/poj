#include<stdio.h>
void main()
{
	int i,j,flag,n;
	printf("��Χ:");
	scanf("%d",&n);
	printf("����:");
	for(i=2;i<=n;i++)
	{
		flag=0;
		for(j=2;j<i;j++)
			if(i%j==0)
			{
				flag=1;
				break;
			}
		if(flag==0)printf("%d  ",i);
	}
}
	
	

