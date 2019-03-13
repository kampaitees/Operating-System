#include<stdio.h>
#define max 25
void main()
{
	int frag[max],b[max],f[max],i,j,nb,nf,temp;
	static int bf[max],ff[max];
	
	printf("\nMemory Management Scheme - First Fit");				//nb number of blocks
																	//b array of blocks
	printf("\nEnter the number of blocks:");						//nf number of processes
	scanf("%d",&nb);												//f array of processes
	
	printf("Enter the number of processes:");
	scanf("%d",&nf);
	
	printf("\nEnter the size of the blocks:-\n\n");
	
	for(i=1;i<=nb;i++) { 
		
		printf("Block %d:",i);
		scanf("%d",&b[i]);
	
	}
	
	printf("Enter the size of the processes :-\n");
	
	for(i=1;i<=nf;i++) {
		
		printf("Block %d:",i);
		scanf("%d",&f[i]);
	
	}
	
	for(i=1;i<=nf;i++) {
		
		for(j=1;j<=nb;j++) {
		
			if(bf[j]!=1) {
		
				temp=b[j]-f[i];
				
				if(temp>=0) {
		
					ff[i]=j;
					break;
				
				}
			
			}
		
		}
		
		frag[i]=temp;
		bf[ff[i]]=1;
	
	}
	
	printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
	
	for(i=1;i<=nf;i++) {
		
		if(frag[i] < 0) {
			
			printf("\n%d\t\t%d\t\t", i, f[i]);
			printf("Not Allocated\t-----\t\t-----");
		}
		
		else
			printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
	}
	
	int count = 0;
	printf("\n");
	for(i=0;i<=nb;i++) {
		if(bf[i] != 1) 
			count += b[i];
	}
	printf("External fragment: %d", count);
	printf("\n");
}
