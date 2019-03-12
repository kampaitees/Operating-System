#include<stdio.h>
void main(void) {
	int i, j, k, f, n;
	int pf = 0, count = 0;
	int rs[30], m[10];
	
	printf("Enter the length of reference string:");
	scanf("%d",&n); // n - length of referenc string
	
	printf("\nEnter the reference string\n");
	
	for(i=0;i<n;i++)
		scanf("%d",&rs[i]); // rs - reference string
	
	printf("\nEnter no. of frames:");
	scanf("%d",&f);  // f - nmuber of frames
	
	for(i=0;i<f;i++)
		m[i]=-1; // initially assigned all the values to one
	
	printf("\nThe Page Replacement Process is :-\n");
	
	for(i=0;i<n;i++) {
	
		for(k=0;k<f;k++) {
			
			if(m[k]==rs[i])
			break;
		}
		if(k==f) {
			
			m[count++]=rs[i];
			pf++; // pf - number of page fault
		}
		
		for(j=0;j<f;j++)
			printf("\t%d",m[j]); // m - storing the page fault values
		
		if(k==f)
			printf("\tPF No. %d",pf);
		printf("\n");
		
		if(count==f)
			count=0;
	}
	printf("\nThe number of Page Faults using FIFO are %d",pf);
	printf("\n");
}
