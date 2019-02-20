#include<stdio.h>
#include<stdlib.h>
void main() {
	int i, j, swap, swap2, n, pid[40], bt[40], wt[40], tat[40], ct[40], at[40];
	printf("Enter the number of processes:");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		pid[i] = i+1;
	for(i = 0; i < n; i++){
		printf("Enter arrival time for process %d:  ", i);
		scanf("%d", &at[i]);
		printf("Enter burst   time for process %d:  ", i);
		scanf("%d", &bt[i]);	
	}
	for (i = 0 ; i < n - 1; i++) {
	    for (j = 0 ; j < n - i - 1; j++) {	      		
		if (at[j] > at[j+1]) {
			 swap = at[j];
			 at[j] = at[j+1];
			 at[j+1] = swap;
			 swap2 = bt[j];
			 bt[j] = bt[j+1];
			 bt[j+1] = swap2;
		      }
	    	}
	}
	int exe = 0, index;
	for(i = 0; i < n-1; i++) {
		exe += bt[i];
		int min = 1000;
		for(j = i+1; j < n; j++) {
			if(at[j] <= exe && min > bt[j]) {
				min = bt[j];
				index = j;
			}
		}
		swap = at[i+1];
		at[i+1] = at[index];
		at[index] = swap;
		swap2 = bt[i+1];
		bt[i+1] = bt[index];
		bt[index] = swap2;
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
