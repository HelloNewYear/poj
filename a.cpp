#include<iostream>
using namespace std;
unsigned int a[251][31];
int main()
{
	a[1][0]=1;                                        //n==1ʱ,����1,���Գ���Ҳ��1
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
			a[i][k]=a[i-1][k]+a[i-2][k]+a[i-2][k]+j;//ÿ�ζ��Զ�Ӧλ�ϵ�7λ���ȵĴ𰸽���һ���Լ���,������ÿһλ�������;
			j=0;
			if(a[i][k]>=100000000)
			{   
				j=a[i][k]/100000000;
				a[i][k]-=j*100000000;
			}
		}
		if(j)										//������������н�λ,��ôa[i]�ĳ�����a[i-1]���ȵĻ����ϼ���1,�����a[i-1]�ĳ�����ͬ
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
