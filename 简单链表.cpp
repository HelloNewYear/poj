#include<iostream>
using namespace std;
struct Node{
	int data;
	char c;
	Node *p;
}a[3];

int main(){
	int i;
	Node *q;
	for(i=0;i<3;i++)
	{
		cin>>a[i].data>>a[i].c;
		a[i].p=&a[i+1];
	}
	cout<<endl<<endl;
	q=&a[0];
	for(i=0;i<3;i++,q++)
		cout<<q->data<<"   "<<q->c<<endl;
	return 0;
}
