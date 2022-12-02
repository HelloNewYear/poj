#include<iostream>
using namespace std;
typedef int DataType;
void CreatHeap (DataType a[], int n, int h)
{
	int i, j, flag;
	DataType temp;
	i = h;				// iΪҪ���ѵĶ�����������±�
	j = 2*i+1;			// jΪi�����ӽ����±�
	temp = a[i];
	flag = 0;
	//�����Һ�����ֵ�ϴ����ظ�����ɸѡ
	while(j < n && flag != 1)
	{	//Ѱ�����Һ��ӽ���еĽϴ���,jΪ���±�
		if(j < n-1 && a[j].key < a[j+1].key) j++;
		if(temp.key > a[j].key)			//a[i].key>a[j].key
			flag=1;				//��ǽ���ɸѡ����
		else					//�����a[j]����
		{
			a[i] = a[j];
			i = j;
			j = 2*i+1;
		}
	}
	a[i] = temp;				//�������a[i]��������a[j]
}

void InitCreatHeap(DataType a[], int n)	
{
	int i;
	for(i = (n-1)/2; i >= 0; i--)	
		CreatHeap(a, n, i);
}
int main(){
	int i;
	DataType a[10];
	for(i=0;i<10;i++)
		cin>>a[i];
	InitCreatHeap(a[10],10);
	for(i=0;i<10;i++)
		cout<<a[i];
	return 0;
}