#include<iostream>
using namespace std;
typedef int DataType;
void CreatHeap (DataType a[], int n, int h)
{
	int i, j, flag;
	DataType temp;
	i = h;				// i为要建堆的二叉树根结点下标
	j = 2*i+1;			// j为i的左孩子结点的下标
	temp = a[i];
	flag = 0;
	//沿左右孩子中值较大者重复向下筛选
	while(j < n && flag != 1)
	{	//寻找左右孩子结点中的较大者,j为其下标
		if(j < n-1 && a[j].key < a[j+1].key) j++;
		if(temp.key > a[j].key)			//a[i].key>a[j].key
			flag=1;				//标记结束筛选条件
		else					//否则把a[j]上移
		{
			a[i] = a[j];
			i = j;
			j = 2*i+1;
		}
	}
	a[i] = temp;				//把最初的a[i]赋予最后的a[j]
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