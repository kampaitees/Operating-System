#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define BUUFFER_SIZE 16
sem_t full, empty;
int buffer[BUFFER_SIZE];
int count;
sem_t mutex;
pthread_t producerThread[50], consumerThread[50];

void init() {
	sem_init(&mutex, 0, 1);
	sem_init(&full, 1, 0);
	sem_init(&empty, 1, BUFFER_SIZE);
	counter = 0;
}

void produce(int item) {
	buffer[count++] = item;
}
int consume() {
	counter--;
	return buffer[count];
}

void *producer(void *arg) {
	int item = rand()%5;
	sem_wait(&empty);
	sem_wait(&mutex);
	printf("Item produces: ", item);
	produce(item);
	sem_post(&mutex);
	sem_post(&full);
}

void *consumer(void *arg) {
	int item;
	sem_wait(&full);
	sem_wait(&mutex);
	item = comsume();
	printf("Item consumed: %d", item);
	sem_post(&mutex);
	sem_post(&empty);
}	

void main() {
	init();
	int numberOfProducer, numberOfConsumer, i;
	printf("Enter the number of producer:");
	scanf("%d", &numberOfProducer);
	printf("Enter the number of consumer:");
	scanf("%d", &numberOfConsumer);
	for(i=0; i<numberOfProducer; i++) 
		pthread_create(&producerThread[i], NULL, producer,NULL);
	for(i=0; i<numberOfConsumer; i++) 
		pthread_create(&consumerThread[i], NULL, consumer, NULL);
	for(i=0; i<numberOfProducer; i++) 
		pthread_join(&producerThread[i], NULL);
	for(i=0; i<numberOfProducer; i++) 
		pthread_join(&producerThread[i], NULL);
}	
