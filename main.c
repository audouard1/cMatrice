#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gauss.h"
#include "cholesky.h"
#include "testMatrice.h"

int main(){
    //float tab[100]={1,2,1,3,1,2,1,4,2}, a[3]={8,11,15}; //test pour gauss
    float tab[100]={1,-1,2,-1,5,-4,2,-4,6}, a[3]={8,11,15}; //test pour cholesky
    //init_zero(tab);
    /*printf("matrice bord\n");
    a_bord1(tab);*/
    printf("matrice de départ :\n");
    affiche_tab(tab);
    printf("\n");
    clock_t start=clock();
    //gauss(tab, a, 3);
    cholesky(tab, a, 3);
    clock_t end=clock();
    double extime=(double) (end-start)/CLOCKS_PER_SEC;
    //affiche_tab(tab);
    printf("resultat :\n");
    affiche_tab_res(a);
    printf("exec time : %f.5\n", extime);

    return 0;
}