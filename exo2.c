#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

#define NBMAX 5
float mat[NBMAX][NBMAX];
float sum[NBMAX];

/*procedure d'intialisation de la matrice aleatoirement*/
void initialisationmatrice(float mat[NBMAX][NBMAX],long n){
long i,j;
int rnd;
for( i=0; i<n; i++){
	for( j=0; j<n;j++){
        rnd=rand()%10;
		mat[i][j]=(float)rnd;

		}
		}
	}

/*procedure d'affichage de la matrice*/

void affihagematrice(float mat[NBMAX][NBMAX]){
float t[NBMAX][NBMAX];

long i,j;
for(i=0; i<NBMAX; i++){
	for(j=0; j<NBMAX;j++){
		t[i][j]=mat[i][j];
		printf("%f | ",t[i][j]);

		}
		printf("\n");
		}


}
/*la procedure qui fait la somme des elements de chaque ligne*/
void* somme(void *i){
long num_ligne= (long)i;
long j;

sum[num_ligne]=0.0;

for(j=0;j<NBMAX;j++){
    sum[num_ligne]=sum[num_ligne]+mat[num_ligne][j];
    printf(" thread %ld somme de la ligne %ld = %f \n\n\n\n",num_ligne,num_ligne,sum[num_ligne]);
        }
            }




int main(){


int create ; float som;
long i;
pthread_t thread[NBMAX];

som=0.0;



printf("Initialisation de la matrice : \n");

/*appel de la procedure d'intialisation de la matrice */
 initialisationmatrice(mat,NBMAX);

/*appel de la procedure qui affiche les elements de la matrice*/
affihagematrice(mat);

/*procedure de creation de nbthread*/
for(i=0; i<NBMAX; i++){

        create=pthread_create(&thread[i], NULL,(void* )somme,(void *)(intptr_t)i);


                 if(create){
                     printf("Erreur de creation de thread %d\n",create);
                     exit(0);
                      }
                      }


printf("Le main attend la fin des N threads crees \n");
for(i=0;i<NBMAX;i++){
pthread_join(thread[i],NULL);

}


for(i=0; i<NBMAX;i++){
som=som+sum[i];}
printf("La somme des elements de la matrice = %f\n",som);
printf("fin du main\n");



return 0;
}


