#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "testMatrice.h"

int main(){
    double tab[100], a[3]={1,1,1};
    init_zero(tab);
    printf("matrice bord\n");
    a_bord1(tab);
    affiche_tab(tab);
    gauss(tab, a, 3);
    affiche_tab(tab);
    affiche_tab_res(a);

    return 0;
}