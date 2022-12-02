#include <iostream>
#include <math.h>
#include <malloc.h>
#include <iomanip>
using namespace std;
const int N=10;

float MatDet(float *p,int n)	//求矩阵行列式的值
{
	int r,c,m,lop=0;
	float result=0,mid=1;
	if(n!=1)
	{
		lop=(n==2)?1:n;
		for(m=0;m<lop;m++)
		{
			mid=1;
			for(r=0,c=m;r<n;r++,c++)
			{
				mid=mid*(*(p+r*n+c%n));
			}
			result+=mid;
		}
		for(m=0;m<lop;m++)
		{
			mid=1;
			for(r=0,c=n-1-m+n;r<n;r++,c--)
			{
				mid=mid*(*(p+r*n+c%n));
			}
			result-=mid;
		}
	}
	else
		result=*p;
	return result;
}

float Creat_M(float *p,int m,int n,int k)	//求逆矩阵
{
	int len;
	int i,j;
	float mid_result=0;
	int sign=1;
	float *p_creat,*p_mid;
	len=(k-1)*(k-1);
	p_creat=(float*)calloc(len,sizeof(float));
	p_mid=p_creat;
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(i!=m&&j!=n)
			{
				*p_mid++=*(p+i*k+j);
			}
		}
	}
	sign=(m+n)%2==0?1:-1;
	mid_result=(float)sign*MatDet(p_creat,k-1);
	free(p_creat);
	return mid_result;
}

void print(float *p,int n)	//打印矩阵
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<setw(4);
		for(j=0;j<n;j++)
			cout<<setiosflags(ios::right)<<*p++<<setw(10);
		cout<<endl;
	}
}

int main()
{
	int row,num,i,j,n;
	float *buffer,*p,determ;
	while(1){
		cout<<"Please input the row of matrix:";
		cin>>row;
		num=2*row*row;
		buffer=(float *)calloc(num,sizeof(float));
		p=buffer;
		if(p!=NULL)
			for(i=0;i<row;i++)
			{
				cout<<"Please input the number of "<<i+1<<" row:";
				for(j=0;j<row;j++)cin>>*p++;
			}
		else
			cout<<"can't distribute memory\n";
		cout<<"the original matrix:\n";
		print(buffer,row);
		determ=MatDet(buffer,row);
		p=buffer+row*row;
		if(determ!=0)
		{
			cout<<"the determinant of the matrix is:"<<determ<<endl;
			for(i=0;i<row;i++)
			{
				for(j=0;j<row;j++)
				{
					*(p+j*row+i)=Creat_M(buffer,i,j,row)/determ;
				}
			}
			cout<<"the inverse matrix:"<<endl;
			print(p,row);
		}
		else
			cout<<"the determinant is 0,and there is no inverse matrix!\n";
		free(buffer);
		cout<<endl;
	}
	return 0;
}

