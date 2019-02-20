#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
//#define N 5
#define BUFFER_SIZE 16
//sem_t mutex, db;
//int data = 0, readerCounter = 0;
int buffer[BUFFER_SIZE];
sem_t mutex, full, empty;
pthread_t producerThread[50], consumerThread[50];
int count;

void initSemaphores() {
	sem_init(&mutex, 0, 1);
	//sem_init(&db, 0, 1);
	sem_init(&full, 1, 0);
	sem_init(&empty, 1, BUFFER_SIZE);
	count = 0;
}
/*void *writer(void *args) {
	int f = ((int)args);
	sem_wait(&db);
	data++;
	printf("Data written by the writer(%d) is: %d\n", f, data);
	sleep(2);
	sem_post(&db);
}
void *reader(void *args) {
	int f = ((int)args);
	sem_wait(&mutex);
	readerCounter++;
	if(readerCounter==1)
		sem_wait(&db);
	sem_post(&mutex);
	printf("Data read by the reader(%d) is: %d\n", f, data);
	sleep(2);
	sem_wait(&mutex);
	readerCounter--;
	if(readerCounter==0)
		sem_post(&db);
	sem_post(&mutex);
}*/
void produce(int item) {
	buffer[count++] = item;
}
int consume() {
	return buffer[--count]; 
}
void *producer(void *arg) {
	int item = rand()%5;
	sem_wait(&empty);
	sem_wait(&mutex);
	printf("Produced item: %d\n", item);
	produce(item);
	sem_post(&mutex);
	sem_post(&full);
}
void *consumer(void *arg) {
	int item;
	sem_wait(&full);
	sem_wait(&mutex);
	item = consume();
	printf("Consumed item: %d\n", item);
	sem_post(&mutex);
	sem_post(&empty);
}

void main() {
	initSemaphores();
	int i, numberOfConsumer, numberOfProducer;
	//pthread_t write[N], read[N];
	printf("Enter the number of producer:");
	scanf("%d", &numberOfProducer);
	printf("Enter the number of consumer:");
	scanf("%d", &numberOfConsumer);
	for(i=0; i<numberOfProducer; i++) {
		pthread_create(&producerThread[i], NULL, producer, NULL);
	}
	for(i=0; i<numberOfConsumer; i++) {
		pthread_create(&consumerThread[i], NULL, consumer, NULL);
	}
	for(i=0; i<numberOfProducer; i++) {
		pthread_join(producerThread[i], NULL);
	}
	for(i=0; i<numberOfConsumer; i++) {
		pthread_join(consumerThread[i], NULL);
	}
}	
