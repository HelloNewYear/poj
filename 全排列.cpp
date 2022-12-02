#include<iostream>
using namespace std;
template<class Type>
void Perm(Type list[],int k,int m)
{
	if(k==m)
	{
		for(int i=0;i<=m;i++)
			cout<<list[i];
		cout<<endl;
	}
	else
		for(int i=k;i<=m;i++)
		{
			Swap(list[k],list[i]);
			Perm(list,k+1,m);
			Swap(list[k],list[i]);
		}
}
template<class Type>
inline void Swap(Type &a,Type &b)
{
	Type temp=a;
	a=b;
	b=temp;
}
int main()
{
	char c[5]={'a','b','c','d','e'};
	Perm(c,0,3);
	return 0;
}