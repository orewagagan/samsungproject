#include<stdio.h>

int min(int a, int b)
{
        return(a < b ? a : b);
}

void floyd(int D[][10],int n)
{
	int k,i,j;
    for( k=1;k<=n;k++)
        for( i=1;i<=n;i++)
            for( j=1;j<=n;j++)
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
}
    
int main() 
{
    int n, cost[10][10],i,j;
    printf("Enter no. of Vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for( i=1;i<=n;i++)
	    for( j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    floyd(cost,n);
        
    printf("All pair shortest path\n");
    for( i=1;i<=n;i++)
    {            
		for( j=1;j<=n;j++)
            printf("%d  ",cost[i][j]);
        printf("\n");
    }
}
