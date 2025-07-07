#include "kernel/types.h"
#include "user/user.h"

#define N 4

int child[N];
int bilhetes[N] = {50, 150, 250, 400};
//int bilhetes[N] = {10, 20, 30, 40, 50, 60, 70, 80};


void waste_time(int id, int meus_bilhetes){
  volatile unsigned long long i;
  printf("Processo %d (bilhetes = %d): start\n", id, meus_bilhetes);
  for (i = 0; i < 300000000ULL; ++i);  
  printf("Processo %d (bilhetes = %d): stop\n", id, meus_bilhetes);
}

int main(int argc, char *argv[])
{
  int n, pid;

  for (n = 0; n < N; n++) {
    pid = fork(bilhetes[n]);
    if (pid == 0) {
      // Processo filho
      waste_time(n, bilhetes[n]);
      exit(0);
    } else {
      // Processo pai
      child[n] = pid;
    }
  }

  for (n = 0; n < N; n++) {
    pid = wait(0);
    printf("Child pid = %d finished!", pid);
  }  

  return 0;
}
