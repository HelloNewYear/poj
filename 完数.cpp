#include<iostream>
using namespace std;
int main()
{
	int i,j,n,sum;
	cout<<"·¶Î§:"; 
	cin>>n;
	cout<<"ÍêÊı:";
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<i;j++)
			if(i%j==0)
				sum+=j;
		if(sum==i)
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}