#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Max 200005
using namespace std;

int cmp(const void *s,const void *t){
    return strcmp((*(Node *)s).s, (*(Node *)t).s);
}

int main(){
    char num[]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
    char Map[100],temp[100];
    for(int i=0;i<26;i++) Map['A'+i]=num[i];
    
    int n;
    struct Node{
        char s[50];
    }str[Max];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int pos=0;
        scanf("%s",temp);
        for(int k=0;k<strlen(temp);k++){
            if(temp[k]>='0'&&temp[k]<='9') str[i].s[pos++]=temp[k];
            else if(temp[k]>='A'&&temp[k]<'Z') str[i].s[pos++]=Map[temp[k]];
            else continue;
            if(pos==3) str[i].s[pos++]='-';
        }
        str[i].s[pos]='\0';
    }

    qsort(str,n,sizeof(str[0]),cmp);
    int pos=0; bool flag=true;
    for(int i=1;i<n;i++){
        if(!strcmp(str[i].s,str[i-1].s)){
            pos++;
            flag=false;
            if(i==n-1) cout<<str[i-1].s<<" "<<pos+1<<endl;
        }
        else if(pos){
            cout<<str[i-1].s<<" "<<pos+1<<endl;
            pos=0;
        }
    }
    if(flag) cout<<"No duplicates."<<endl;

    return 0;
}
