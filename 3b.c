#include<stdio.h>

void warshal(int A[][10],int n)
{
	int k,i,j;
    for( k=1;k<=n;k++)
        for( i=1;i<=n;i++)
            for( j=1;j<=n;j++)
                A[i][j]=A[i][j] || (A[i][k] && A[k][j]);
}
    
void main() 
{
    int n, adj[10][10],i,j;
    printf("Enter no. of Vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for( i=1;i<=n;i++)
        for( j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    warshal(adj,n);
        
    printf("Transitive closure of the given graph is\n");
    for( i=1;i<=n;i++)
    {            
	for( j=1;j<=n;j++)
            printf("%d  ",adj[i][j]);
        printf("\n");
    }
}
