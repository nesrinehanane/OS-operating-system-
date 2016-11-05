#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include<string.h>
#include<semaphore.h>

sem_t semaph;

void affichagemessage1(void){
   sleep(rand()%5);
   sem_wait(&semaph);
   printf("Un,...");
   pthread_exit(0);


}


void affichagemessage2(void){
   sleep(rand()%5);
   sem_wait(&semaph);
   printf("Deux,...");
   pthread_exit(0);


}


int main(void){
pthread_t thread1,thread2;

/*initialisation de semaphore sans nom*/
if(sem_init(&semaph,0,0)){
   perror("seminit");
   exit(EXIT_FAILURE);
   }



   if(pthread_create(&thread1, NULL,  (void*)affichagemessage2,NULL)){
    fprintf(stderr,"thread2");
    exit(EXIT_FAILURE);
   }

   if(pthread_create(&thread2, NULL, (void*) affichagemessage1,NULL)){
    fprintf(stderr,"thread1");
    exit(EXIT_FAILURE);
   }
/*attente du thread main*/
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("\nFini!\n");
sem_destroy(&semaph);
exit(EXIT_FAILURE);

}
