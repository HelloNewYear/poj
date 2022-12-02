#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 12500
#define MAXRC 100
typedef struct 
{
    int i,j;
    int e;
}Triple;
typedef struct//三元组是顺序表
{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;
}TSMatrix;

typedef struct
{
    Triple data[MAXSIZE+1];
    int rpos[MAXRC+1];//各*行*第一个非零元的位置
    int mu,nu,tu;
}RLSMatrix;
//
void initialSMatrix(TSMatrix *M,int *array,int m,int n)//初始化三元组顺序表
{
    int i,j;
    M->mu=m;
    M->nu=n;//预设=====
    M->tu=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(*(array+i*n+j)!=0)
            {
                M->tu++;
                M->data[M->tu].i=i+1;//=i+1 ,not i;
                M->data[M->tu].j=j+1;//the same as zbove
                M->data[M->tu].e=*(array+i*n+j);
            }
}



int initialarray(int *array,int m,int n)
{
    int a;
    int i,j,flag=0;
    printf("请输入一个%d行%d列的整数矩阵:\n",m,n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a);
            if(a==0)
                flag++;
            *(array+i*n+j)=a;
        }    
        if(flag/(m*n*1.0)>=0.5)//0的个数过半，采用稀疏矩阵存储方式
            return(0);
        else 
            return(1);
}
void printarray(int *array,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%5d ",*(array+i*n+j));
        printf("\n");
    }
}
void transpose(int *array,int m,int n)
{
    int i,j;
    int *array1=(int *)malloc(n*m*sizeof(int));
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            *(array1+j*m+i)=*(array+i*n+j);//array1+j*m+i not array1+j*n+i
        printf("转置后的矩阵为:\n");
        printarray(array1,n,m);//not array m,n
}

void printSMatrix(TSMatrix M)
{
    int i,j,k;
    int *array=(int *)malloc(M.mu*M.nu*sizeof(int));
        for(i=0;i<M.mu;i++)
        for(j=0;j<M.nu;j++)
            *(array+i*M.nu+j)=0;
        for(k=1;k<=M.tu;k++)
            *(array+(M.data[k].i-1)*M.nu+(M.data[k].j-1))=M.data[k].e;
        for(i=0;i<M.mu;i++)
        {
            for(j=0;j<M.nu;j++)
            printf("%d ",*(array+M.nu*i+j));
            printf("\n");
        }
}
/*void transposeSMatrix1(TSMatrix M,TSMatrix *T)//稀疏矩阵转置算法
{
    int col,p,q;
    int *array=(int *)malloc(M.mu*M.nu*sizeof(int));
    T->mu=M.nu;//**
    T->nu=M.mu;//**
    T->tu=M.tu;
    if(T->tu)
    {
        q=1;
        for(col=1;col<=M.nu;col++)
        {
            for(p=1;p<=M.tu;p++)
                if(M.data[p].j==col)
                {
                    T->data[q].i=M.data[p].j;
                    T->data[q].j=M.data[p].i;
                    T->data[q].e=M.data[p].e;
                    q++;
                }
        }
    }
    printf("矩阵转置后的结果是:\n");
    printSMatrix(*T,array,T->mu,T->nu);
}*/
void transposeSMatrix2(TSMatrix M,TSMatrix *T)//稀疏矩阵快速转置算法
{
    int col,p,q;
    int t;
    int *array=(int *)malloc(M.mu*M.nu*sizeof(int));
    int *cpot=(int *)malloc(M.nu*sizeof(int));
    int *num=(int *)malloc(M.mu*sizeof(int));
    T->mu=M.nu;//**
    T->nu=M.mu;//**
    T->tu=M.tu;
    if(T->tu)
    {
        for(col=1;col<=M.nu;col++)
            num[col]=0;
        for(t=1;t<=M.tu;t++)
            ++num[M.data[t].j];
        cpot[1]=1;
        for(col=2;col<=M.nu;col++)
            cpot[col]=cpot[col-1]+num[col-1];
        for(p=1;p<=M.tu;p++)
        {
            col=M.data[p].j;
            q=cpot[col];
            T->data[q].i=M.data[p].j;
            T->data[q].j=M.data[p].i;
            T->data[q].e=M.data[p].e;
            ++cpot[col];
        }
        printf("矩阵转置后的结果是:\n");
        printSMatrix(*T);
    }
}

void main()
{
    int a,b;
    int *A;
    int t1;
    TSMatrix *M1,*M2,T;
    M1=(TSMatrix *)malloc(sizeof(TSMatrix));
    M2=(TSMatrix *)malloc(sizeof(TSMatrix));
    printf("请输入你想创建的矩阵的行数和列数:\n");
    scanf("%d%d",&a,&b);
    A=(int *)malloc(a*b*sizeof(int));
    t1=initialarray(A,a,b);
    printf("请输出A矩阵:\n");
    printarray(A,a,b);
    if(t1)
    {
        transpose(A,a,b);
    }
    else
    {
        initialSMatrix(M1,A,a,b);
        transposeSMatrix2(*M1,&T);
    }
}