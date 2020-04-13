/* Solucion punto 2.a Problema de los filosofos */

#include <stdio.h>  //incluimos la libreria de estandar input/output
#include <unistd.h> //para hacer sleep
#include <stdlib.h> //para libreria de numeros random: srand, rand 
#include <time.h>   //para inicializar el tiempo
#include <sys/types.h>  
#include <sys/wait.h>

/*Bandera While */
#define TRUE 1 
/*cantidad de filosofos */
#define N 5

void Filosofo (int i);
//Estado Agarrando palillo (primero izq, desp. der)
void agarrandoPalillos (int i);
 //Estado Pensando
void pensar (int i);
//Estado Comiendo
void comer (int i);

void do_nothing(int microseconds, char* mensaje){

  usleep(microseconds); 
  printf("\n %s \n",mensaje);   

}


int main ()
{
  char* msg= "";
  pid_t proc;	
  proc = fork();
  int i = 1; 
  int status;

  if (proc > 0){
    wait(&status); 
  }

void Filosofo (int i);
/* Inicializamos los filosofos */
// for(int i = 0; i < N ; i++)

    while (TRUE)
    {
// void pensar(int i){printf("Filosofo %d pensando", i);};
      pensar(i);
      msg= "Eureka!";
      do_nothing(10000000,msg);
      agarrandoPalillos (i);
      comer(i);
      msg=  "Provecho!";
      do_nothing(10000000,msg);
      }
    return 0;

}

void pensar (int i)
{
  //Estado Pensando
    printf("Filosofo %d pensando ", i);

//char* msg= "Eureka!";
}

void agarrandoPalillos (int i)
{
//Estado Agarrando palillo
    printf("Soy el Filosofo %d agarrando palillo izquierdo\n ",i);
    printf("Soy el Filosofo %d agarrando palillo derecho\n", i);
//    char* msg=  "Provecho!";
}

void comer (int i)
{
//Estado Comiendo   
    printf("Filosofo %d comiendo ", i);
}







