#include<stdio.h>

 typedef struct
{
	int data, next;
}blocks;

typedef struct{
	int start,len;
}file;

int main()
{
	int size,block;
	printf("Enter the number of memory blocks\n");
	scanf("%d",&size);
	printf("Enter the size of each block\n");
	scanf("%d",&block);
	printf("Enter the number of files to be allocated\n");
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	blocks b[size+1];
	for(i=0;i<size+1;i++)
	{
		b[i].data=0;
		b[i].next=-1;
	}
	int x,y,f=0;
	for(i=0;i<n;i++)
	{
		f=0;
		printf("Enter number of blocks for allocation of the file-%d\n",i+1);
		scanf("%d",&a[i]);
		printf("Enter the sequence of blocks for file-%d to be allocated\n",i+1);
		scanf("%d",&x);
		if(b[x].data==0)
		{
			b[x].data=i+1;
			y=x;
		}
		else
		{
			printf("File-%d cannot be allocated due to conflict\n",i+1);
			continue;
		}
		for(j=0;j<a[i]-1;j++)
		{
			scanf("%d",&x);
			if(b[x].data==0)
			{
				b[x].data=i+1;
				b[y].next=x;
				y=x;
			}
			else
			{
				printf("File-%d cannot be allocated due to conflict\n",i+1);
				f=1;
				break;
			}
		}
		if(f==0)
		{
			printf("File-%d allocated\n",i+1);
		}
	}
	for(i=1;i<=size;i++)
		printf("%d",b[i].data);
}

