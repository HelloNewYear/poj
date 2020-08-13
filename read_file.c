#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("read_file.c","r");
    char c;
    while((c=fgetc(fp))!=EOF)
        if(c != '\n')
            printf("%c ",c);
    fclose(fp);
}
