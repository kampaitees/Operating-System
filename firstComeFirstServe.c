#include<stdio.h>
#include<stdlib.h>
void main() {
	int n, pid[6], bt[6], wt[6], tat[6], ct[6], at[6];
	printf("Enter the number of processes:");
	scanf("%d", &n);
	int i, b;
	for(b = 0; b < n; b++)
		pid[b] = b+1;
	
	for(i = 0; i < n; i++){
		printf("Enter arrival time for process %d:  ", i);
		scanf("%d", &at[i]);
		printf("Enter burst   time for process %d:  ", i);
		scanf("%d", &bt[i]);	
	}
	int c, d, swap2, swap;
	for (c = 0 ; c < n - 1; c++) {
	    for (d = 0 ; d < n - c - 1; d++) {
	      if (at[d] > at[d+1]) {
		 swap       = at[d];
		 at[d]   = at[d+1];
		 at[d+1] = swap;
		 swap2       = bt[d];
		 bt[d]   = bt[d+1];
		 bt[d+1] = swap2;
	      }
	    }
	}	
	for(i = 0; i < n; i++) {
		if(i == 0)
			ct[i] = bt[i] + at[i];
		else 
			ct[i] = ct[i-1] + bt[i];
	}
	
	for(i = 0; i < n; i++) {
		tat[i] = ct[i] - at[i];
		wt[i] = ct[i] - at[i] - bt[i];
	}
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
	}	
}
