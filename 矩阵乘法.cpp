#include <iostream>
using namespace std;
int main()
{
	float A[100][100],B[100][100],C[100][100];
	int i,j,k,m,n,q;
	FILE *p;
	cin>>m>>n>>q;
    if((p=fopen("juzhenshuju.txt","r"))==NULL)
	{printf("File open error!\n");
     exit(0);
	}

    printf("du ru juzhenA:\n");
    for(i=0;i<m;i++)
	{for(j=0;j<n;j++)
	{
		fscanf(p,"%f",&A[i][j]);
	    printf("%f  ",A[i][j]);
	}
    printf("\n");
	}
 
  
    printf("du ru juzhenB:\n");
    for(i=0;i<n;i++)
	{for(j=0;j<q;j++)
	{
		fscanf(p,"%f",&B[i][j]);
        printf("%f  ",B[i][j]);
	}
    printf("\n");
	}
    
	fclose(p);

	printf("shu chu juzhenC:\n");
    for(i=0;i<m;i++)	 
	{for(j=0;j<q;j++)
	 {C[i][j]=0;
      for(k=0;k<n;k++)
	  C[i][j]+=A[i][k]*B[k][j];
      printf("%f   ",C[i][j]);    
	 }
    printf("\n");
	}
 return 0;
}

