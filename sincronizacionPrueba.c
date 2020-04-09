#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t A;
sem_t B;
sem_t C;
sem_t D;
sem_t E;
sem_t FIVE;
sem_t ONE;
sem_t AUX1;
sem_t AUX2;

static void * thread1(void* arg) {	
	while(1)   {
        sem_wait(&ONE);
		printf("\nPienso\n");
		sem_post(&A);
		sem_post(&B);
		sem_post(&C);
		sem_wait(&AUX1);
		sem_wait(&AUX1);
		sem_wait(&AUX1);
		sem_post(&FIVE);
	}
}

static void * thread2(void* arg)  {
	while(1)    {
		sem_wait(&A);
		printf("Mientras lavo los platos, ");
		sem_post(&AUX1);
	}
}

static void * thread3(void* arg)    {	
	while(1)    {
		sem_wait(&B);
		printf("Mientras limpio el piso, ");
        sem_post(&AUX1);
	}
}
static void * thread4(void* arg) {	
	while(1)   {
        sem_wait(&C);
		printf("Mientras riego las plantas, ");
		sem_post(&AUX1);
	}
}
static void * thread5(void* arg) {	
	while(1)   {
        sem_wait(&FIVE);
		printf("\nExisto!\n");
		sem_post(&D);
		sem_post(&E);
		sem_wait(&AUX2);
		sem_wait(&AUX2);
		sem_post(&ONE);
	}
}
static void * thread6(void* arg) {	
	while(1)   {
        sem_wait(&D);
		printf("Hablar. ");
		sem_post(&AUX2);
	}
}
static void * thread7(void* arg) {	
	while(1)   {
        sem_wait(&E);
		printf("Tomar una desicion. ");
		sem_post(&AUX2);
	}
}

int main(void)    {
	pthread_t thread_1, thread_2, thread_3, thread_4, thread_5, thread_6, thread_7;
	sem_init(&A,0,0);
	sem_init(&B,0,0);
    sem_init(&C,0,0);
    sem_init(&D,0,0);
    sem_init(&E,0,0);
    sem_init(&AUX1,0,0);
    sem_init(&AUX2,0,0);
    sem_init(&FIVE,0,0);
    sem_init(&ONE,0,1);

	pthread_create(&thread_1, NULL, *thread1, NULL);
	pthread_create(&thread_2, NULL, *thread2, NULL);
	pthread_create(&thread_3, NULL, *thread3, NULL);
	pthread_create(&thread_4, NULL, *thread4, NULL);
	pthread_create(&thread_5, NULL, *thread5, NULL);
	pthread_create(&thread_6, NULL, *thread6, NULL);
	pthread_create(&thread_7, NULL, *thread7, NULL);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
	pthread_join(thread_4, NULL);
	pthread_join(thread_5, NULL);
	pthread_join(thread_6, NULL);
	pthread_join(thread_7, NULL);

	sem_destroy(&A);
	sem_destroy(&B);
    sem_destroy(&C);
    sem_destroy(&D);
    sem_destroy(&E);
    sem_destroy(&FIVE);
    sem_destroy(&ONE);
    sem_destroy(&AUX1);
    sem_destroy(&AUX2);
	pthread_exit(NULL);
	return 0;
}
