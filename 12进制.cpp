#include<iostream>
using namespace std;
int main(){
    int num,a[16],i=0;
    cout<<"输入十进制数:";
    cin>>num;
    while(num){
        a[i++]=num%2;
        num=num/2;
    }
    cout<<"输出二进制数:";
    while(i)
        cout<<a[--i];
    return 0;
}


