#include <stdio.h>  //incluimos la libreria de estandar input/output
#include <unistd.h> //para hacer sleep
#include <stdlib.h> //para libreria de numeros random: srand, rand 
#include <time.h>   //para inicializar el tiempo
#include <sys/types.h>  
#include <sys/wait.h>

void do_nothing(int microseconds, char* mensaje){
  usleep(microseconds); //dormir el thread, simula que esta haciendo alguna tarea
  printf("\n %s \n",mensaje);   
}

void do_nothing_random(char* mensaje){
  srand(time(NULL));                    //inicializar la semilla del generador random:
  int microseconds = rand() % 1000 + 1; //generar un numer random entre 1 y 1000:
  usleep(microseconds);                 //dormir el thread, simula que esta haciendo alguna tarea
  printf("\n %s \n",mensaje); 
}


int main() {
  char* msg= "hola";
  pid_t proc;

  proc = fork();
  if (proc == 0){
    do_nothing(2000000,msg); //esperar 2 segundos, 1 millon de microsegundos en 1 segundo
    do_nothing_random(msg);  //esperar un tiempo random antes de imprimir el mensaje
  }

  else if (proc > 0){
    do_nothing(2000000,msg);
    do_nothing_random(msg);
  }

  else{
    printf("Error");
  }

  int status;
  wait(&status);

  return 0;
}