#include<iostream>
using namespace std; 
double f(int i){
	if(i==1)
		return 1;
	else 
		if(i==2)
			return 1;
	return f(i-1)+f(i-2);
}
int main() 
{    
	int i;
	cin>>i;
	cout<<f(i)<<endl;
	return 0;
}

