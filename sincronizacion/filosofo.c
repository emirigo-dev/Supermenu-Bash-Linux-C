#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>  //incluimos la libreria de estandar input/output
#include <time.h>   //para inicializar el tiempo

sem_t A;
sem_t B;
sem_t C;
sem_t AUX;
sem_t AUX2;

pthread_mutex_t mutex;
pthread_mutex_t mutex2;

void do_nothing(int microseconds, char* mensaje){
  usleep(microseconds); //dormir el thread, simula que esta haciendo alguna tarea
  printf("\n %s \n",mensaje);   
}


static void * filosofo1(void* arg) {	
	while (1) {
	  
	  //Estado Pensando
	  printf("\nSoy el Filósofo 1 : Pensando\n");
	  do_nothing(1500000, "Filósofo 1 : Eureka!");
	  //pthread_mutex_lock(&mutex2);
	  sem_wait(&C);
	  sem_wait(&AUX);
	  sem_wait(&A);
	  //Estado Agarrando palillo
	  printf("\nSoy el Filósofo 1 : Agarrando palillo izquierdo\n");
	  printf("\nSoy el Filósofo 1 : Agarrando palillo derecho\n");

	  //Estado Comiendo
	  printf("\nSoy el Filósofo 1 : Comiendo\n");
	  do_nothing(3000000, "Filósofo 1 : Provecho!");
	  //pthread_mutex_unlock(&mutex2);
	   sem_post(&A);
           sem_post(&AUX);
	}
}

static void * filosofo2(void* arg)  {
	while (1) {
	  //Estado Pensando
	
       	printf("\nSoy el Filósofo 2 : Pensando\n");
	  do_nothing(1500000, "Filósofo 2 : Eureka!");
	  //pthread_mutex_lock(&mutex2);
	   sem_wait(&A);	
	  //Estado Agarrando palillo
	  printf("\nSoy el Filósofo 2 : Agarrando palillo izquierdo\n");
	  printf("\nSoy el Filósofo 2 : Agarrando palillo derecho\n");

	  //Estado Comiendo
	  printf("\nSoy el Filósofo 2 : Comiendo\n");
	  do_nothing(3000000, "Filósofo 2 : Provecho!");
	  //pthread_mutex_unlock(&mutex2);
	  sem_post(&A);
	  sem_post(&C);
	}
}
static void * filosofo3(void* arg)    {	
	while (1) {
	  //Estado Pensando
	  
	  printf("\nSoy el Filósofo 3 : Pensando\n");
	  do_nothing(1500000, "Filósofo 3 : Eureka!");
	   //pthread_mutex_lock(&mutex2);
	sem_wait(&C);
	sem_wait(&AUX2);
	sem_wait(&A);
	  //Estado Agarrando palillo
	  printf("\nSoy el Filósofo 3 : Agarrando palillo izquierdo\n");
	  printf("\nSoy el Filósofo 3 : Agarrando palillo derecho\n");

	  //Estado Comiendo
	  printf("\nSoy el Filósofo 3 : Comiendo\n");
	  do_nothing(3000000, "Filósofo 3 : Provecho!");
	  //pthread_mutex_unlock(&mutex2);
	sem_post(&A);
	}
}
static void * filosofo4(void* arg) {	
	while (1) {
		
  		//Estado Pensando
  		printf("\nSoy el Filósofo 4 : Pensando\n");
  		do_nothing(1500000, "Filósofo 4: Eureka!");
		//pthread_mutex_lock(&mutex);
		sem_wait(&AUX2);
	  	sem_wait(&B);
		  //Estado Agarrando palillo
		  printf("\nSoy el Filósofo 4 : Agarrando palillo izquierdo\n");
		  printf("\nSoy el Filósofo 4 : Agarrando palillo derecho\n");

		  //Estado Comiendo
		  printf("\nSoy el Filósofo 4 : Comiendo\n");
		  do_nothing(3000000, "Filósofo 4: Provecho!");
		  //pthread_mutex_unlock(&mutex);
		sem_post(&B);
	       		}
}
static void * filosofo5(void* arg) {	
	while (1) {
	  //Estado Pensando
	  printf("\nSoy el Filósofo 5 : Pensando\n");
	  do_nothing(1500000, "Filósofo 5: Eureka!");
	  //pthread_mutex_lock(&mutex);	
	  //Estado Agarrando palillo
	  sem_wait(&B);
	  sem_wait(&AUX);
	  printf("\nSoy el Filósofo 5 : Agarrando palillo izquierdo\n");
	  printf("\nSoy el Filósofo 5 : Agarrando palillo derecho\n");

	  //Estado Comiendo
	  printf("\nSoy el Filósofo 5 : Comiendo\n");
	  do_nothing(3000000, "Filósofo 5 : Provecho!");
	  //pthread_mutex_unlock(&mutex);
	sem_post(&AUX);	
	sem_post(&AUX2);	
	sem_post(&B);
	
	
}
}

int main(void)    {
	//pthread_mutex_init(&mutex, NULL);
	//pthread_mutex_init(&mutex2, NULL);
	pthread_t thread_1, thread_2, thread_3, thread_4, thread_5;
	sem_init(&A,0,1);
	sem_init(&B,0,1);
    	sem_init(&C,0,0);
    	sem_init(&AUX,0,1);
    	sem_init(&AUX2,0,0);

	pthread_create(&thread_1, NULL, filosofo1, NULL);
	pthread_create(&thread_2, NULL, filosofo2, NULL);
	pthread_create(&thread_3, NULL, filosofo3, NULL);
	pthread_create(&thread_4, NULL, filosofo4, NULL);
	pthread_create(&thread_5, NULL, filosofo5, NULL);
	
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
	pthread_join(thread_4, NULL);
	pthread_join(thread_5, NULL);
	
	sem_destroy(&A);
	sem_destroy(&B);
        sem_destroy(&C);
        sem_destroy(&AUX);
        sem_destroy(&AUX2);

	
	pthread_exit(NULL);
	return 0;
}
