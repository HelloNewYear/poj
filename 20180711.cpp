#include<iostream>
using namespace std;
int main(){
    unsigned int i1=-1;
    unsigned int i2=1;
    cout<<(i1>i2?++i1:i2++)<<endl;
    cout<<i2++<<"  "<<i2<<"  "<<sizeof(char*)<<endl;

    struct test{
        char ch;
        int i;
    };
    cout<<sizeof(test)<<"  "<<sizeof(char)<<"  "<<sizeof(int)<<endl;

    return 0;
}
