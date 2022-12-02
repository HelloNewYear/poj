#include<stdio.h>
void main()
{
	int i,j,n;
	while(1)
	{
		printf("ÐÇÐÇ²ãÊý:");
		scanf("%d",&n);
		if(n%2==0)break;
		for(i=0;i<n/2;i++)
		{
			for(j=n/2-i;j>0;j--)
				printf(" ");
			for(j=0;j<2*i+1;j++)
				printf("*");
			printf("\n");
		}
		for(j=0;j<n;j++)
			printf("*");
		printf("\n");
		for(i=0;i<n/2;i++)
		{
			for(j=0;j<i+1;j++)
				printf(" ");
			for(j=0;j<n-2-2*i;j++)
				printf("*");
			printf("\n");
		}
	}
}
