#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define N 5
int data = 0, readerCount = 0;
//db for writer, mutex for reader
sem_t db, mutex;
void initSemaphores() {
// sem_init(semaphore variable reference, 0 to share semaphore between all threads, inital value)
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);
}

void *writer(void *arg) {
    int f = ((int) arg);
    // check for access to database 
    // if no access put process in sleep queue of db semaphore
    // else write to database
    sem_wait(&db);
    data++;
    // write data 
    printf("Data writen by the writer(%d) is %d\n", f,data);
    sleep(2);
// free the db semaphore
// also wake up a writer or reader from the sleep queue of the semaphore
    sem_post(&db);
}
void *reader(void *arg) {   
// let only 1 reader increment reader count and get access to database
// if not allowed put that reader in sleep queue of the mutex semaphore
       sem_wait(&mutex);
	readerCount++;
	if(readerCount==1)
		sem_wait(&db);
// get access to db if first reader is trying to access it
// release mutex variable as multiple readers is allowed
// also wake up a reader from the sleep queue of the mutex semaphore
    sem_post(&mutex);
    printf("Data read by the reader(%d) is %d\n", ((int) arg), data);
    sleep(2);
// let only 1 reader decrement reader count and release access to database
// if no put that reader in sleep queue of the mutex semaphore 
    sem_wait(&mutex);
    readerCount--;
    if(readerCount ==0)
    	sem_post(&db);
// if last reader release access to database
// release mutex variable also wake up a reader from the sleep queue of the mutex semaphore
    sem_post(&mutex);
}        
int main() {       
    initSemaphores();  
// declare pthread (POSIX threads) ids
// A thread is a single sequence stream within in a process
    pthread_t read[N], write[N];    
    // create readers and writer threads
    int i;
    for (i = 0; i < N; i++) {
        pthread_create(&write[i], NULL, writer, (void *)i);
        pthread_create(&read[i], NULL, reader, (void *)i);
    }   
    for (i = 0; i < N; i++) {
        pthread_join(write[i], NULL);
        pthread_join(read[i], NULL);
    }   
}
