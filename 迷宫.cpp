#include<iostream>
#include<conio.h>
using namespace std;
const int l=10;
int main(){
	int mg[l][l]={
		{0,0,0,0,0,0,0,0,0,0},
		{0,-1,1,0,1,1,1,0,1,0},
		{0,1,1,0,1,1,1,0,1,0},
		{0,1,1,1,1,0,0,1,1,0},
		{0,1,0,0,0,1,1,1,1,0},
		{0,1,1,1,0,1,1,1,1,0},
		{0,1,0,1,1,1,0,1,1,0},
		{0,1,0,0,0,1,0,0,1,0},
		{0,0,1,1,1,1,1,1,2,0},
		{0,0,0,0,0,0,0,0,0,0}};
	int r=0,c=0,i,j;
	char dir=NULL;
	while(!kbhit())
	{
		system("cls");
		for(i=0;i<l;i++)
		{
			for(j=0;j<l;j++)
			{
				if(mg[i][j]==-1){cout<<'@';r=i;c=j;mg[i][j]=1;}
				else if(i==r&&j==c&&dir!=NULL)cout<<'@';
				else if(mg[i][j]==0)cout<<'#';
				else if(mg[i][j]==1)cout<<' ';
				else cout<<'$';
			}
			cout<<endl;
		}
		if(mg[r][c]==2)cout<<"SUCCESS!"<<endl;
		dir=getch();
		switch(dir){
		case 'd':if(mg[r][c+1]!=0){r=r;c=c+1;}break;
		case 'a':if(mg[r][c-1]!=0){r=r;c=c-1;}break;
		case 'w':if(mg[r-1][c]!=0){r=r-1;c=c;}break;
		case 's':if(mg[r+1][c]!=0){r=r+1;c=c;}break;
		}
	}
	return 0;
}