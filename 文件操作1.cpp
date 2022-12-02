#include<stdio.h>
#include<stdlib.h>

void Copy(){
	FILE *fp1;
	if((fp1=fopen("1.txt","r"))==NULL)
	{
		printf("1.txt Open Error!!!\n");
		return;
	}
	FILE *copy;
	copy=fopen("copy.txt","w");
	while(!feof(fp1))
		fputc(fgetc(fp1),copy);
	fclose(fp1);
	fclose(copy);
}

void Print(){
	FILE *fp1;
	if((fp1=fopen("1.txt","r"))==NULL)
	{
		printf("1.txt Open Error!!!\n");
		return;
	}
	else
		while(!feof(fp1))
			printf("%c  ",fgetc(fp1));
	fclose(fp1);
	printf("\n\n");
}

void Creat(){
	FILE *fp1;
	fp1=fopen("1.txt","w");
	char ch;
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp1);
		ch=getchar();
	}
	fclose(fp1);
}

void main(){
	void Creat();
	void Print();
	void Copy();
}



	

