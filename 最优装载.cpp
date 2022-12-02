#include<iostream>
#define Amount 5
using namespace std;
int main(){
	int i,j,x[Amount],w[Amount],c,t[Amount],a[Amount],temp;
	for(i=0;i<Amount;i++)
	{
		x[i]=0;
		t[i]=i;
	}

	cout<<"输入"<<Amount<<"个集装箱的重量："<<endl;
	for(i=0;i<Amount;i++)
	{
		cout<<"w["<<i<<"]=";
		cin>>w[i];
		a[i]=w[i];
	}
	cout<<"输入轮船载重量："<<endl<<"c=";
	cin>>c;

	for(i=0;i<Amount;i++)
		for(j=0;j<Amount-1;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}

	for(i=0;i<Amount&&w[t[i]]<=c;i++)
	{
		x[t[i]]=1;
		c-=w[t[i]];
	}

	cout<<endl<<"装载的货箱："<<endl;
	for(i=0;i<Amount;i++)
		if(x[i]==1)
			cout<<"w["<<i<<"]="<<w[i]<<endl;
	return 0;
}
