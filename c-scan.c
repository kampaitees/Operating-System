/*#include <stdio.h>

int curr_pos;
int size;
int requests[1000];
int n;

void sort(); 
    
int main() {
    
    // inputs
    int cylinder;
    printf("Enter size of cylinder: ");
    scanf("%d", &cylinder);
    
    printf("Enter current position of head: ");
    scanf("%d", &curr_pos);

    //printf("Enter size: ");
    //scanf("%d", &size);   
    
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int total_dist = 0;
    
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    // sort as per location
    sort();
    
    // get location of greater than the curr head position
    int curr_req_greater = n + 1;
    
    for (i = 0; i < n; i++) {
        if (requests[i] >= curr_pos) {
            curr_req_greater = i;
            break;        
        }
    }

	int min = cylinder - curr_pos;
    int max = cylinder;
   
   
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
		curr_pos = cylinder;
	
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
		curr_pos = 0;
		
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
    printf("Distance moved: %d\n", abs(size -1 - curr_pos)); 
    curr_pos = 0; 

    // respond to all requests to the left
    for (i = 0  ; i <= curr_req_greater - 1; i++) {
        printf("From %d to %d\n", curr_pos, requests[i]);
        printf("Distance moved: %d\n", abs(requests[i] - curr_pos)); 
        total_dist += abs(requests[i] - curr_pos);
        curr_pos = requests[i];
    }
   
    printf("Total distance moved: %d", total_dist);
    return 0;
}


 
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
}*/


#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct request
{
	int request_track_number;
	bool visited;
};

int main()
{
	int i,no_of_requests,initial_head,limit,j,choice,previous_head;
	
	printf("Enter the number of requests: ");
	scanf("%d",&no_of_requests);
	struct request req[no_of_requests];
	
	printf("Enter the requests: ");
	for (i = 0; i < no_of_requests; ++i)
	{
		scanf("%d",&req[i].request_track_number);
		req[i].visited = false;
	}
	printf("Enter initial position of R/W head: ");
	scanf("%d",&initial_head);

	//printf("Enter the previous position of R/W head: ");
	//scanf("%d",&previous_head);

	printf("Enter the cylinder size: ");
	scanf("%d",&limit);

	int min = limit - initial_head;
    int max = limit;


	//if(previous_head - initial_head > 0 )
	if(max > min)
	{
		choice = 2;
	}
	else
		choice = 1;
	//scanf("%d",&choice);
	int seek_time=0;
	printf("%d -> ",initial_head );
	int cp_initial_head = initial_head;
	if(choice == 1)
	{
		for(i=initial_head;i<limit;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		//printf("%d -> \n", limit-1);
		//seek_time += abs(limit-1 - initial_head);
		initial_head = 0;
		for(i=0;i<cp_initial_head;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		printf("\n");
	}
	else if(choice == 2)
	{
		for(i=initial_head;i>=0;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		//printf("%d -> ", 0 );
		//seek_time += abs(initial_head - 0);
		initial_head = limit-1;
		for(i=limit;i>cp_initial_head;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		printf("\n");
	}
	printf("Seek Time: %d\n", seek_time);
}
