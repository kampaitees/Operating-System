#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int n;
phthread_t philosopher[50];
phthread_mutex chopstick[50];

void *thinkEatReapeat(int i) {
	printf("%d\t Thinking.....\n", i+1);
	pthread_mutex_lock(&chopstick[i]);
	pthread_mutex_lock(&chopstick[(i+1)%n]);
	printf("%d\t Eating.....\n", i+1);
	sleep(1);
	pthread_mutex_unlock(&chopstick[i]);
	pthread_mutex_unlock(&chopstick[(i+1)%n]);
	printf("%d\t Finished Eating.....\n", i+1);
	return NULL;
}

void main() {
	printf("Enter the number of philosopher:");
	scanf("%d", n);
	int i;
	for(i=0; i<n; i++) 
		phtread_mutex_init(&chopstick[i], NULL);
	for(i=0; i<n; i++) 
		phtread_create(&philosopher[i], NULL, thinkEatReapeat, i);
	for(i=0; i<n; i++) 
		phtread_join(chopstick[i], NULL);
}
