#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include<string.h>

#define NBthread 3

int v[NBthread],u[NBthread];
int result=0;

pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER;


/*procedure d'intialisation des vecteurs aleatoirement*/
void initialisationvecteur(int t[NBthread],long n){
long i,j;
int rnd;
for( i=0; i<n; i++){
	
        rnd=rand()%10;
		t[i]=rnd;
		}
	}



void produit_scalaire_seq(void * i) {
long elem=(intptr_t)i;
long j;

   for ( j= 0; j <elem ; j++) {
       pthread_mutex_lock(&mutex);
       result =result+ v[j]*u[j];
       printf("thread %ld somme de la ligne %ld = %d \n\n\n\n",elem,elem,result);
       pthread_mutex_unlock(&mutex);
        }
}





int main(void){
long i;
int som=0;

int creation;
pthread_t threads[NBthread];
initialisationvecteur(v,NBthread);
initialisationvecteur(u,NBthread);

   for(i=0; i<NBthread; i++){
        
         creation=pthread_create(&threads[i], NULL,(void *)produit_scalaire_seq,(void*)(intptr_t)i);
        

                 if(creation){
                     printf("Erreur de creation de thread %d\n",creation);
                     exit(0);
                      }
			}

for(i=0;i<NBthread;i++){
pthread_join(threads[i],NULL);

}

printf("le resultat est %d\n",result);

printf("fin du main\n");



}
