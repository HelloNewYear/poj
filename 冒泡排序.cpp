#include<stdio.h>
#include<stdlib.h>
#define Size 10
void main(){
	FILE *fp;
	if((fp=fopen("data.txt","r"))==NULL)
	{
		printf("Open Error!\n");
		exit(0);
	}
	char a[Size];
	int i=0,j,temp;
	while(!feof(fp)&&i<Size)
		a[i++]=fgetc(fp);
	for(i=0;i<Size;i++)
		for(j=0;j<Size-i;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	for(i=0;i<Size;i++)
		printf("%c  ",a[i]);
}

