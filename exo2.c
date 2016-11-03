#include<stdlib.h>
#include<stdio.h>
#include<pthread.h> 
#include <unistd.h> 


/*procedure d'intialisation de la matrice aleatoirement*/
void initialisationmatrice(int mat[][],  int *n){
 

prinft("Introduire la dimension de votre matrice carree: ");
scanf("%d",n);
printf("\n\n\n");
for(int i=0; i<*n; i++){
	for(int j=0; j<*n;j++){
		mat[i][j]=rand()%10;

		}
		}
	}

/*procedure d'affichage de la matrice*/

void affihagematrice(int mat[][], int *n){

for(int i=0; i<*n; i++){
	for(int j=0; j<*n;j++){
		printf("%d | ",mat[i][j]);

		}
		printf("\n");
		}


}




int main(){

int mat[10][10];
int nbligne,nbcolonne;
int i,j,create;



pritnf("Initialisation de la matrice : \n");

/*appel de la procedure d'intialisation de la matrice */
initialisationmatrice(mat,&n);
/*appel de la procedure qui affiche les elements de la matrice*/

affihagematrice(mat,&n);














return 0;
}


