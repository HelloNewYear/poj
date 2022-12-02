#include<stdio.h>
int main(int argc,char *argv[]){
        int i;
        printf("%d\n",argc);
        for(i=0;i<argc;i++)printf("%s\n",argv[i]);
        return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
        int input;
        if(argc!=2)return 1;
        input=atoi(argv[1]);
        printf("%.1f\n",32+input*1.8);
        return 0;
}
*/