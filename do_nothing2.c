#include <stdio.h>  //incluimos la libreria de estandar input/output
#include <unistd.h> //para hacer sleep
#include <stdlib.h> //para libreria de numeros random: srand, rand 
#include <time.h>   //para inicializar el tiempo

void do_nothing(int microseconds, char* mensaje){

  usleep(microseconds); 
  printf("\n %s \n",mensaje);   
  
}

void do_nothing_random(char* mensaje){

  srand(time(NULL));
  int microseconds = rand() % 1000 + 1;
  usleep(microseconds);

  printf("\n %s \n",mensaje);   
}


int main() {

  char* msg= "hola";

  pid_t proc;
  proc = fork();

  do_nothing(15000000,msg); //esperar 2 segundos, 1 millon de microsegundos en 1 segundo 
  do_nothing_random(msg);  //esperar un tiempo random antes de imprimir el mensaje
  return 0;
}
