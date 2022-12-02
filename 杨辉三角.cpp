#include<stdio.h>
#define Line 10
void main(){
	int i,j,a[Line][Line];
	for(i=0;i<Line;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
		for(j=1;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		for(j=0;j<=i;j++)
			printf("%-5d",a[i][j]);
		printf("\n");
	}
}
