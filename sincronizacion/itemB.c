#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

int cantVeces;
int contador;

sem_t A;
sem_t C;
sem_t D;
sem_t E;
sem_t F;
sem_t G;
sem_t AUX;
sem_t AUX2;

static void * thread1(void* arg) {	
	while(contador<(cantVeces * 7)){
		contador++;
        sem_wait(&A);
		printf("\nPienso\n");
		sem_post(&E);
		sem_post(&F);
		sem_post(&G);
		sem_post(&AUX2);
	}
}

static void * thread2(void* arg) {
	while(contador<(cantVeces * 7)){
		contador++;
		sem_wait(&E);
		sem_wait(&AUX2);
		printf("Mientras lavo los platos, ");
		sem_post(&AUX2);	
		sem_post(&AUX);
	}
}

static void * thread3(void* arg) {	
	while(contador<(cantVeces * 7)){
		contador++;
		sem_wait(&F);
		sem_wait(&AUX2);
		printf("Mientras limpio el piso, ");
		sem_post(&AUX2);
		sem_post(&AUX);
	}
}
static void * thread4(void* arg) {	
	while(contador<(cantVeces * 7)){
		contador++;
		sem_wait(&G);
		sem_wait(&AUX2);
		printf("Mientras riego las plantas, ");
		sem_post(&AUX2);
		sem_post(&AUX);
	}
}
static void * thread5(void* arg) {	
	while(contador<(cantVeces * 7)){
		contador++;
		sem_wait(&AUX);
		sem_wait(&AUX);
		sem_wait(&AUX);
		printf("\nExisto!\n");
		sem_post(&C);
	}
}
static void * thread6(void* arg) {	
	while(contador<(cantVeces * 7)){
		contador++;
	    sem_wait(&C);
		printf("Hablar, ");
		sem_post(&D);
	}
}
static void * thread7(void* arg) {	
	while(contador<(cantVeces * 7)){
		contador++;
        sem_wait(&D);
		printf("tomar una desicion.\n");
		sem_post(&A);
	}
}

int main(void)    {
	printf ("Ingrese cantidad de veces que quiere que se repita:\n");
	scanf("%d",&cantVeces);	
	pthread_t thread_1, thread_2, thread_3, thread_4, thread_5, thread_6, thread_7;
	
	sem_init(&A,0,1);
    sem_init(&C,0,0);
    sem_init(&D,0,0);	
	sem_init(&E,0,0);
	sem_init(&F,0,0);    
    sem_init(&AUX,0,0);
    sem_init(&AUX2,0,0);
	
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
    sem_destroy(&C);
    sem_destroy(&D);
	sem_destroy(&E);
	sem_destroy(&F);
    sem_destroy(&AUX);
	sem_destroy(&AUX2);
	pthread_exit(NULL);
	return 0;
}
