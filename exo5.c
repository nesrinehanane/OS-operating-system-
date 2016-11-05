#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include<semaphore.h>


#define NBTHREAD 5
sem_t semaph;
int compteur;
pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER;

void *threadFunction(void *thid){
long tid;
int i;
tid=(long)thid;
sleep(rand()%20);
printf("Les thread %ld arrive a son point de rendez-vous compteur = %d\n",tid,compteur);
pthread_mutex_lock(&mutex);
    compteur++;

if(compteur==NBTHREAD){

    printf("Tous les thread sont arrives au rendez-vous\n");
    for(i=0;i<NBTHREAD;i++)
        sem_post(&semaph);
    }
pthread_mutex_unlock(&mutex);
    sem_wait(&semaph);
    printf("Le thread %ld poursuit son execution! \n", tid);
    sleep(rand()%20);
    pthread_exit(0);
    }

int main(void){
pthread_t thread[NBTHREAD];
    sem_init(&semaph,0,0);

int create;
long i;
srand(time(NULL));
    for(i=0;i<NBTHREAD;i++){
        printf("Creation du thread num %ld\n",i);
        create=pthread_create(&thread[i],NULL,threadFunction,(void *)i);
        if(create){
            printf("Erreur de creation de thread %d\n",create);
            exit(-1);

        }

    }


pthread_exit(0);


}

