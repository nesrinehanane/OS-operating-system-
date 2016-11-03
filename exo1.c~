#include<stdlib.h>
#include<stdio.h>
#include<pthread.h> 
#include <unistd.h> 
#define MAXTHREADS 10 /* Nombre max de threads pouvant être créés */
#define NUMTHREADS 5 /* Nombre de threads à créer */

void *threadFunction(void){ 
  pthread_t mon_tid; 
  mon_tid = pthread_self(); 
  int i, nbreIters; 
  nbreIters = rand()%100; 
  i=0; 
  printf("Thread (0x)%x : DEBUT\n", (int)mon_tid);  
  while(i < nbreIters) i++; 
  printf("Thread (0x)%x : FIN\n", (int)mon_tid); 
  pthread_exit(NULL); 
}

int main(){ 
   int i; 
   
   int nbthread; 
  
   pthread_t thread_main, threads[10]; 
   srand(time(NULL)); 
   thread_main = pthread_self(); 
  

        printf("Introduisez le nombre de threads a créer: \n");
        scanf("%d",&nbthread);
                while(nbthread>10||nbthread<0){
                        printf("Veuillez Introduire une valeur entre 0 et 10");
                        scanf("%d",&nbthread);
                                };

for(i=0; i<nbthread; i++){
        
        int creation=pthread_create(&threads[i], NULL,(void *)threadFunction,NULL);
        
        printf("Le thread main (Tid (0x)%x) vient de creer les %d threads:(0x)%x\n",  (int)thread_main, nbthread, (int)threads[i]); 
                 if(creation){
                     printf("Erreur de creation de thread %d\n",creation);
                     exit(0);
                      }}

  printf("Le thread main (Tid (0x)%x) attend la fin de tous les threads crees\n",(int)thread_main); 
  
for(i=0; i<nbthread; i++){
        pthread_join(threads[i],NULL);
        }



  return 0;
} 

