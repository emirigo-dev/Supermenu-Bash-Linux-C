#include <stdio.h>  //incluimos la libreria de estandar input/output
#include <unistd.h> //para hacer sleep
#include <stdlib.h> //para libreria de numeros random: srand, rand 
#include <time.h>   //para inicializar el tiempo
#include <sys/types.h>  
#include <sys/wait.h>

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

  int status;

  if (proc > 0){
    wait(&status); 
  }

  do_nothing(10000000,msg);
  do_nothing_random(msg); 
  return 0;
}
