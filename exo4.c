#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
void mes1(void){
 sleep(rand()%5);
 printf("Deux,...");
 

pthread_exit(NULL);}
void mes2(void){
sleep(rand()%5);
printf("Un,...");
pthread_exit(NULL);
  }
int main(){
  pthread_t th1, th2;
  srand(time(NULL));
  if(pthread_create(&th1, NULL, (void*) mes1, NULL)){
  fprintf(stderr,"thread1");
  exit(EXIT_FAILURE);
  }
if(pthread_create(&th2, NULL, (void*) mes2, NULL)){
fprintf(stderr,"thread2");
exit(EXIT_FAILURE);
}
pthread_join(th1,NULL);
pthread_join(th2,NULL);
printf("\nFini!\n");
exit(EXIT_SUCCESS);
}
