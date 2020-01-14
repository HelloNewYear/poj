#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    char c;
    c=getchar();
    while(c!='#'){
        switch(c){
            case ' ':cout<<"%20";break;
            case '!':cout<<"%21";break;
            case '$':cout<<"%24";break;
            case '%':cout<<"%25";break;
            case '(':cout<<"%28";break;
            case ')':cout<<"%29";break;
            case '*':cout<<"%2a";break;
            default :cout<<c;
        }
        c=getchar();
    }
    return 0;
}

/**
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(){
    char str[500];
    scanf("%[^#]",str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        switch(str[i]){
            case ' ':cout<<"%20";break;
            case '!':cout<<"%21";break;
            case '$':cout<<"%24";break;
            case '%':cout<<"%25";break;
            case '(':cout<<"%28";break;
            case ')':cout<<"%29";break;
            case '*':cout<<"%2a";break;
            default :cout<<str[i];
        }
    }
    return 0;
}
**/
