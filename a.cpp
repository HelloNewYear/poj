#include<iostream>
using namespace std;
unsigned int a[251][31];
int main()
{
	a[1][0]=1;                                        //n==1时,答案是1,所以长度也是1
    a[1][30]=1;
    a[2][0]=1;
    a[2][30]=3;
    int i,j,k,f,n;
    for(i=3;i<=250;i++)
    {
		j=0;
		f=31-a[i-1][0];
		for(k=30;k>=f;k--)
		{
			a[i][k]=a[i-1][k]+a[i-2][k]+a[i-2][k]+j;//每次都对对应位上的7位长度的答案进行一次性计算,而不是每一位依次相加;
			j=0;
			if(a[i][k]>=100000000)
			{   
				j=a[i][k]/100000000;
				a[i][k]-=j*100000000;
			}
		}
		if(j)										//如果计算完了有进位,那么a[i]的长度是a[i-1]长度的基础上加上1,否则和a[i-1]的长度相同
		{
			a[i][0]=a[i-1][0]+1;
			a[i][k]=j;
		}
		else
			a[i][0]=a[i-1][0];
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			cout<<1<<endl;
		else
		{
			for(i=31-a[n][0];i<=30;i++)
			{
				if(a[n][i]==0)
					printf("00000000");
				else
				{    
					f=10000000;
					if(i!=31-a[n][0])
					{
						while(a[n][i]<f)
						{
							printf("0");
							f/=10;
						}
					}
					printf("%d",a[n][i]);
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
