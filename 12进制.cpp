#include<iostream>
using namespace std;
int main(){
    int num,a[16],i=0;
    cout<<"����ʮ������:";
    cin>>num;
    while(num){
        a[i++]=num%2;
        num=num/2;
    }
    cout<<"�����������:";
    while(i)
        cout<<a[--i];
    return 0;
}


