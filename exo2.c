#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

#define NBMAX 50
/*procedure d'intialisation de la matrice aleatoirement*/
void initialisationmatrice(int mat[NBMAX ][NBMAX ],  int *n){

int i,j;
printf("Introduire la dimension de votre matrice carree: ");
scanf("%d",n);
printf("\n\n\n");
while(*n<0||*n>NBMAX){
printf("Veuillez reintroduire la dimention de votre matrice :");
scanf("%d",n);
printf("\n\n\n");


};
for( i=0; i<*n; i++){
	for( j=0; j<*n;j++){
		mat[i][j]=rand()%10;

		}
		}
	}

/*procedure d'affichage de la matrice*/

void affihagematrice(int mat[NBMAX ][NBMAX ], int *n){
int i,j;
for(i=0; i<*n; i++){
	for(j=0; j<*n;j++){
		printf("%d | ",mat[i][j]);

		}
		printf("\n");
		}


}




int main(){

int mat[NBMAX ][NBMAX ];
int nbligne,nbcolonne;
int i,j,create;



printf("Initialisation de la matrice : \n");

/*appel de la procedure d'intialisation de la matrice */
initialisationmatrice(&mat[NBMAX ][NBMAX ],&nbligne);
/*appel de la procedure qui affiche les elements de la matrice*/

affihagematrice(&mat[NBMAX ][NBMAX ],&nbligne);














return 0;
}


