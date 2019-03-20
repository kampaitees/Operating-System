#include <stdio.h>

int curr_pos;
int size;
int requests[1000];
int n;
int cylinder;
void sort(); 
    
int main() {
    
    // inputs
   
    printf("Enter size of cylinder: ");
    scanf("%d", &cylinder);
    
    printf("Enter current position of head: ");
    scanf("%d", &curr_pos);

   // printf("Enter size: ");
   // scanf("%d", &size);   
    
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int total_dist = 0;
    printf("Enter requests: ");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    // sort as per location
    sort();
    
    // get location of greater than the curr head position
    
    
    int min = cylinder - curr_pos;
    int max = cylinder;
    
    int curr_req_greater = n + 1;
    
    for (i = 0; i < n; i++) {
        if (requests[i] >= curr_pos) {
            curr_req_greater = i;
            break;        
        }
    }


	if(max < min) {
	
		 for (i = curr_req_greater; i < n; i++) {
		    printf("From %d to %d\n", curr_pos, requests[i]);
		    printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
		    total_dist += abs(requests[i] - curr_pos);
		    curr_pos = requests[i];           
		}
		
		printf("From %d to %d\n", curr_pos, cylinder - 1);
		printf("Distance moved: %d\n", abs(cylinder - 1 - curr_pos));
		total_dist += abs(cylinder - 1 - curr_pos);
	
		for (i = curr_req_greater - 1; i >= 0; i--) {
		    printf("From %d to %d\n", curr_pos, requests[i]);
		    printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
		    total_dist += abs(requests[i] - curr_pos);
		    curr_pos = requests[i];
		       
		}
	}
	else  {
	
		 for (i = curr_req_greater - 1; i >= 0; i--) {
		    printf("From %d to %d\n", curr_pos, requests[i]);
		    printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
		    total_dist += abs(requests[i] - curr_pos);
		    curr_pos = requests[i];
		       
		}
		
		printf("From %d to %d\n", curr_pos, 0);
		printf("Distance moved: %d\n", abs(0 - curr_pos));
		total_dist += abs(0 - curr_pos);
		
		for (i = curr_req_greater; i < n; i++) {
		    printf("From %d to %d\n", curr_pos, requests[i]);
		    printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
		    total_dist += abs(requests[i] - curr_pos);
		    curr_pos = requests[i];           
		}
	}

/*
    // respond all requests to the right
    for (i = curr_req_greater; i < n; i++) {
        printf("From %d to %d\n", curr_pos, requests[i]);
        printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
        total_dist += abs(requests[i] - curr_pos);
        curr_pos = requests[i];           
    }
    
    // go till the end 
   total_dist += abs(curr_pos - size + 1); 
    printf("From %d to %d\n", curr_pos, size - 1);
    printf("Distance moved: %d\n", abs(size - 1 - curr_pos)); 
    curr_pos = size - 1;    

    // respond to all requests to the left
    for (i = curr_req_greater - 1; i >= 0; i--) {
        printf("From %d to %d\n", curr_pos, requests[i]);
        printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
        total_dist += abs(requests[i] - curr_pos);
        curr_pos = requests[i];
           
    }*/
   
    printf("Total distance moved: %d\n", total_dist);
    return 0;
}


/**
 * Sort requests as per location
 */ 
void sort() {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[j] < requests[i]) {
                int tmp = requests[i];
                requests[i] = requests[j];    
                requests[j] = tmp;
            }
        }
    }
}
