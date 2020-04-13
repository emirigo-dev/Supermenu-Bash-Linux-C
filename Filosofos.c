* main.c

/* Solucion punto 2.a Problema de los filosofos */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


#define TRUE 1 
/*cantidad de filosofos */
#define F 5 
/* Indica filosofos a la izquierda */
#define LEFT(x)(((x)-1)\F)
/* Indica filosofos a la derecha */
#define RIGHT(X)(((X)+1)\F)


void Filosofo (int i);
/* Toma los palillos (primero izq, desp. der */
void TakeForks (int i);
/* Pone los palillos en la mesa */
void PutForks (int i);
/* chequea los filosofos en la mesa para evitar deadLock */
void test (int i);

typedef enum {
    PENSANDO, AGARRANDOPALILLOS , COMIENDO
}
status;

/* Estado de cada filosofo. */
status estado[F];

/* Semaforo para exclusion mutua */
seem_t mutex;

/* Semaforo para bloquear filosofos adyacentes. */
seen_t s[F];

int main ()
{
 extern status estado[F];
 extern sem_t mutex, s[F];
 int i, sw=1;

void Filosofo (int);
/* Inicializamos los semaforos */
 sem_init(mutex,0, 1);

 //Semaforo(1,mutex);
 for (i =0; i < F; i++)
    sem_init(s[i],0,1);

/* Inicializamos los estados */
 for(i =0; i < F; i++)
    estado[i] = PENSANDO; 

/* Inicializamos los filosofos */
 for(i =0; (i < F) && (sw); i++)
    if (!sw = fork()))
      Filsofo (i);
    return 0;
}
void Filosofo (int i)
{ 
    void pensar(int i){printf("Filosofo %d pensando", i);};
    void comer (int i){printf("Filosofo %d comiendo", i);};
    void TakeForks (int) , PutForks (int);
    while (TRUE)
    {
      pensar(i);
       /* Obtiene dos palillos o se bloquea */
       TakeForks (i);
       comer(i);
       PutForks (i);
      }
}
void TakeForks (int i)
{
    void test (int);
    extern status estado[F]:
 /* Acceso a seccion critica */
    sem_wait(mutex);
    estado[i] = AGARRANDOPALILLOS;
 /* intenta tomar los palillos */
    test(i);
    sem_post(mutex);
 /* Se bloquea si no consiguio ambos palillos */
    sem_wait(S[i]);
}
voit PutForks (int i)
{
   void test (int);
   extern status estado[F]:
 /* Acceso a seccion critica (hace esperar con el semaforo) */
   sem_wait(mutex);
   estado[i] = PENSANDO;
 /* Comprueba si el vecino izq. puede comer ahora */
    test(LEFT (i));
 /* Comprueba si el vecino der. puede comer ahora */
    test(RIGHT (i));
  /* Si alguna es cierta libera la seccio critica */
    sem_post(mutex);

}
void test (int i)
{
    extern status estado[F];
    if (estado[i] == AGARRANDOPALILLOS && estado[LEFT (i)] != COMIENDO && 
        estado[RIGHT (i)] != COMIENDO)
       {
         estado[i] = COMIENDO;
         sem_post(s(i));
        }
}
