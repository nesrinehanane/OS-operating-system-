#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>


#define N 100
#define NP 10
#define NC 5
char buffer [N];
int nextin = 0, nextout = 0;
int count = 0;

pthread_cond_t notfull= PTHREAD_COND_INITIALIZER;
pthread_cond_t notempty= PTHREAD_COND_INITIALIZER;

pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER;


void produce_char( void * args){
char x;
	if (count == N)
		pthread_cond_wait (&notfull,&mutex);
		pthread_mutex_lock (&mutex) ;
		buffer [nextin] = x;
		nextin = (nextin + 1) % N;
		count ++;
		pthread_mutex_unlock (&mutex) ;
		pthread_cond_signal (&notempty);
}

/* Fonction exécutée par les threads consommateur */
void take(void * args) {
char *x;
if (count == 0)
	pthread_cond_wait (&notempty,&mutex);
	pthread_mutex_lock (&mutex) ;
	*x = buffer [nextout];
	nextout = (nextout + 1) % N;
	count --;
	pthread_mutex_unlock (&mutex) ;
	pthread_cond_signal(&notfull);
}


int main(void){
pthread_t thread_P[NP];
pthread_t thread_C[NC];

int createP, createC;
long i;

    for(i=0;i<NP;i++){

        createP=pthread_create(&thread_P[i],NULL,(void *)produce_char,NULL);
        if(createP){
            printf("Erreur de creation de thread %d\n",createP);
            exit(-1);

        }

    }
for(i=0;i<NC;i++){

        createC=pthread_create(&thread_C[i],NULL,(void *)take,NULL);
        if(createC){
            printf("Erreur de creation de thread %d\n",createC);
            exit(-1);

        }

    }

printf("Le main attend la fin des threads producteur \n");
for(i=0;i<NP;i++){
pthread_join(thread_P[i],NULL);

}
printf("Le main attend la fin des threads consomateurs \n");
for(i=0;i<NC;i++){
pthread_join(thread_C[i],NULL);

}



pthread_exit(0);


}
