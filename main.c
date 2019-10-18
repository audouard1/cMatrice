#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gauss.h"
#include "testMatrice.h"

int main(){
    double tab[100]={1,2,1,3,1,2,1,4,2}, a[3]={8,11,15};
    //init_zero(tab);
    printf("matrice bord\n");
    //a_bord1(tab);
    affiche_tab(tab);
    clock_t start=clock();
    gauss(tab, a, 3);
    clock_t end=clock();
    double extime=(double) (end-start)/CLOCKS_PER_SEC;
    affiche_tab(tab);
    affiche_tab_res(a);
    printf("exec time : %f.5", extime);

    return 0;
}