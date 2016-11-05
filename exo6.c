#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include<semaphore.h>
#include<string.h>

sem_t s1,s2,s3,s4;

/*procedure affichage de "One..."*/
void affichage1(void){
        int i;
            for(i=0;i<4;i++){
                sleep(rand()%5);
                sem_wait(&s1);
                printf("One, ...\n");
                sem_post(&s2);
                }
      pthread_exit(0);
   }

/*procedure affichage de "Two..."*/
void affichage2(void){
        int i;
            for(i=0;i<4;i++){
                sleep(rand()%5);
                sem_wait(&s2);
                printf("Two, ...\n");
                sem_post(&s3);
                }
      pthread_exit(0);
    }

/*procedure affichage de "Three..."*/
void affichage3(void){
        int i;
            for(i=0;i<4;i++){
                sleep(rand()%5);
                sem_wait(&s3);
                printf("Three, ...\n");
                sem_post(&s4);
                }
      pthread_exit(0);
    }

/*procedure affichage de "Viva l'Algerie."*/
void affichage4(void){
        int i;
            for(i=0;i<4;i++){
                sleep(rand()%5);
                sem_wait(&s4);
                printf("Vive l'Algerie.\n");
                sem_post(&s1);
                }
      pthread_exit(0);
    }


int main(void){

pthread_t th1, th2, th3, th4;
 sem_init(&s1,0,1);
 sem_init(&s2,0,0);
 sem_init(&s3,0,0);
 sem_init(&s4,0,0);


srand(time(NULL));
/*creation du thread num1*/
if(pthread_create(&th1, NULL, (void*) affichage1, NULL)){
        fprintf(stderr,"thread1");
        exit(EXIT_FAILURE);
        }

/*creation du thread num2*/
if(pthread_create(&th2, NULL, (void*) affichage2, NULL)){
        fprintf(stderr,"thread2");
        exit(EXIT_FAILURE);
}

/*creation du thread num3*/
if(pthread_create(&th3, NULL, (void*) affichage3, NULL)){
        fprintf(stderr,"thread3");
        exit(EXIT_FAILURE);
}

/*creation du thread num4*/
if(pthread_create(&th4, NULL, (void*) affichage4, NULL)){
        fprintf(stderr,"thread4");
        exit(EXIT_FAILURE);
}

/*attente du main de la terminaison des threads*/
pthread_join(th1,NULL);
pthread_join(th2,NULL);
pthread_join(th3,NULL);
pthread_join(th4,NULL);

/*destruction des sema*/
sem_destroy(&s1);
sem_destroy(&s2);
sem_destroy(&s3);
sem_destroy(&s4);


pthread_exit(0);
}
