#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "testMatrice.h"

int main(){
    double tab[100]={1,2,-8,4,0,3,5,-7,0,0,2,4,0,0,0,-2}, a[4]={5,8,7,4};
    //init_zero(tab);
    printf("matrice bord\n");
    //a_bord1(tab);
    gauss(tab, a, 4);
    affiche_tab(tab);
    affiche_tab_res(a);

    return 0;
}