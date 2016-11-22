#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>


#define N 10
#define NP 10
#define NC 5
char buffer [N];
int nextin = 0, nextout = 0;
int count = 0;

//initialisation des variables de condition
pthread_cond_t notfull= PTHREAD_COND_INITIALIZER;
pthread_cond_t notempty= PTHREAD_COND_INITIALIZER;

//initialisation du mutex
pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER;

//Fonction exécutée par les threads producteurs
void produce_char( void * args ){
int i;
	
	 char x= 65+rand()%27;
        if (count == N)
        pthread_cond_wait(&notfull,&mutex);
        pthread_mutex_lock(&mutex);
        buffer [nextin] = x;
	printf("produit %c\n",buffer[nextin]);
        nextin = (nextin + 1) % N;
        count ++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&notempty);
    
    pthread_exit(0);

}

/* Fonction exécutée par les threads consommateur */
void take(void * args) {
char x;

        if (count == 0)
        pthread_cond_wait(&notempty, &mutex) ;
        pthread_mutex_lock(&mutex);
        x = buffer [nextout] ;
	printf("consommé %c\n", x);
        nextout = (nextout + 1) % N;
        count --;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&notfull);
    
    pthread_exit(0);
}


int main(void){
pthread_t thread_P[NP];
pthread_t thread_C[NC];

int createP, createC;
long i;
int j;

//inisialisation 
/*char T[N];
    printf("initialisation\n");
    for (j = 0; j < N; i++) {
	/*initialisation du tableau avec des lettres alphabetiques aleatoires 
	65 represente le code de A %27 de 0 a 26 nb de lettre alphabetiques
       T[j] = 65+rand()%27;
        
    }*/


//creation des threads producteurs 
    for(i=0;i<NP;i++){

        createP=pthread_create(&thread_P[i],NULL,(void *)produce_char,NULL);
        if(createP){
            printf("Erreur de creation de thread %d\n",createP);
            exit(-1);

        }

    }

//creation des threads consommateurs
for(i=0;i<NC;i++){

        createC=pthread_create(&thread_C[i],NULL,(void *)take,NULL);
        if(createC){
            printf("Erreur de creation de thread %d\n",createC);
            exit(-1);

        }

    }


//jointures des threads avec le thread main
printf("Le main attend la fin des threads producteur \n");
for(i=0;i<NP;i++){
pthread_join(thread_P[i],NULL);

}
printf("Le main attend la fin des threads consomateurs \n");
for(j=0;j<NC;j++){
pthread_join(thread_C[j],NULL);

}
//destruction des variables de condition

pthread_cond_destroy(&notfull); 
pthread_cond_destroy(&notempty);
pthread_mutex_destroy(&mutex);


pthread_exit(0);


}
