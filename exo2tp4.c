#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include<semaphore.h>
#define N 100
#define NP 10
#define NC 5
char buffer [N];
int nextin = 0, nextout = 0;
int count = 0;
condition notfull, notempty;

pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER;


void produce_char ( char x)
{

if (count == N)
	cond_wait (notfull);
	pthread_mutex_lock (&mutex) ;
	buffer [nextin] = x;
	nextin = (nextin + 1) % N;
	count ++;
	pthread_mutex_unlock (&mutex) ;
	cond_signal (notempty);
}


/* Fonction exécutée par les threads consommateur */
void take (char *x) { // retirer un caractère du buffer
if (count == 0)
	cond_wait (notempty);
	pthread_mutex_lock (&mutex) ;
	*x = buffer [nextout];
	nextout = (nextout + 1) % N;
	count --;
	pthread_mutex_unlock (&mutex) ;
	cond_signal (notfull);
}


int main(void){
pthread_t thread_P[NP];
pthread_t thread_C[NC];

int createP, createC;
long i;

    for(i=0;i<NP;i++){
       
        create_P=pthread_create(&thread_P[i],NULL,(void *)produce_char,buffer[i]);
        if(create_P){
            printf("Erreur de creation de thread %d\n",create);
            exit(-1);

        }

    }
for(i=0;i<NC;i++){
       
        create_C=pthread_create(&thread_C[i],NULL,(void *)take,(void *));
        if(create_C){
            printf("Erreur de creation de thread %d\n",create);
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


