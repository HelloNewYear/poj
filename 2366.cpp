#include <iostream>
using namespace std;

int a[50000],b[50000];
int bs(int key,int n,int c[])
{
    int lo=0,hi=n-1;
    int mi;
    while(lo<=hi)
    {
        mi=((hi-lo)>>1)+lo;//二分查找，“>>”相当于除以二取整
        if(c[mi]==key) return mi;
        else if(c[mi]<key) lo=mi+1;
        else hi=mi-1;
    }
    return -1;
}

int main()
{
    int i,n1,n2;
    cin>>n1;
    for(i=0;i<n1;i++){cin>>a[i];}
    cin>>n2;
    for(i=0;i<n2;i++){cin>>b[i];}
    for(i=0;i<n2;i++)
    {
        if(bs(10000-b[i],n1,a)!=-1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
