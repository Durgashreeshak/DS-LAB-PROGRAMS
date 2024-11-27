#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],visited[20],reach[10],n,i,j,f=0,r=-1,count=0,v,choice;
void DFS_Connectivity(int v)
{
reach[v]=1;
for(i=1;i<=n;i++)
{
if(a[v][i]&&!reach[i])
{
printf("\n%d->%d",v,i);
count++;
DFS_Connectivity(i);
}
}
}
void main()
{
printf("\nEnter the number of vertices:");
scanf("%d",&n);
for(i=1;i<=n-1;i++)
reach[i]=0;
printf("\nEnter graph data in matrix form:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("DFS-Connectivity check");
DSF_Connectivity(0);
if(count==n-1)
printf("\nGraph is connected");
else
printf("\n Graph is not connected");
}

