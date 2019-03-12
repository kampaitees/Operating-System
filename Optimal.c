#include<stdio.h>
int n;
int findmax(int []);
void main(void) {

	int seq[30],fr[5],pos[5];
	int find, flag, max, i, j, m, k, t, s;
	int count=1,pf=0,p=0;
	float pfr;// page fault rate
	
	printf("Enter length of reference string: ");
	scanf("%d",&max); // max - length of reference string
	
	printf("\nEnter the reference string: ");
	for(i=0;i<max;i++)
		scanf("%d",&seq[i]); // seq - array of reference string
	
	printf("\nEnter no. of frames: ");
	scanf("%d",&n); // n - number of frames
	
	fr[0] = seq[0];
	pf++; // pf - number of page fault
	printf("%d\t",fr[0]); // fr - taking care of frames array changes
	
	i=1;
	while(count<n) {
		flag=1;
		p++;
		for(j=0;j<i;j++) {// here we are seeing whether new page exists or not in fr(frame) array
			if(seq[i]==seq[j])
				flag=0;
		}
		if(flag!=0) {
			fr[count]=seq[i];
			printf("%d\t",fr[count]);
			count++;
			pf++;
		}
		i++;
	}
	printf("\n");
	for(i=p+1;i<max;i++) {	
		flag=1;
		for(j=0;j<n;j++) { // here we are seeing whether new page exists or not in fr(frame) array
			if(seq[i]==fr[j]) 
			flag=0;
		}
		if(flag!=0) {
			for(j=0;j<n;j++) {// here we are finding occurrences of pages in frame array in futures to replace
				m=fr[j];//with new page by assigning in pos array
				for(k=i+1;k<max;k++) {
					if(seq[k]==m) { 
						pos[j]=k;
						break;
					}
					else
						pos[j]=1;// if pages doesn't exist then assign 1 to correspoding position in
				}// pos array
			}
			for(k=0;k<n;k++) {
				if(pos[k]==1)// if in pos arrray if 1 is there then flag = 0
					flag=0;
			}
			if(flag!=0)
				s=findmax(pos);// if not then finding the page farthest from current page to replace it
			if(flag==0) {
				for(k=0;k<n;k++) {
					if(pos[k]==1) {
						s=k;
						break;
					}
				}
			}
			fr[s]=seq[i];// replacing the farthest page with current page in frame array
			for(k=0;k<n;k++)
				printf("%d\t",fr[k]);
			pf++;
			printf("\n");
		}
	}
	
	pfr=(float)pf/(float)max;
	
	printf("\nThe no. of page faults are %d",pf);
	printf("\nPage fault rate %f",pfr);
	printf("\n");
}

int findmax(int a[]) {            // finding the page farthest fron the current page
	int max, i;
	int k=0;
	max=a[0];
	for(i=0;i<n;i++) {
	 	if(max<a[i]) {
			max=a[i];
			k=i;
		}
	}
	return k;
}
