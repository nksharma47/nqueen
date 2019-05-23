#include <stdio.h>
#include<math.h>

int count,x[10];

void print(int n)
{
    int i,j;
    printf("Solution #%d\n",++count);
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
                printf("\tQ");
            else
                printf("\t-");
        }
        printf("\n");
    }
    printf("\n");
}

int place(int k,int j)
{
    int i;
    for(i=1;i<=k-1;i++)
    {
        if(x[i]==j)
            return 0;
        else if(abs(x[i]-j)==abs(i-k))
            return 0;
    }
    return 1;
}

void nqueen(int k,int n)
{
    int j;
    for(j=1;j<=n;j++)
    {
        if(place(k,j))
        {
            x[k]=j;
            if(k==n)
                print(n);
            else
                nqueen(k+1,n);
            
        }
    }
}

int main(void) 
{
	int n;
	scanf("%d",&n);
	nqueen(1,n);
	return 0;
}

