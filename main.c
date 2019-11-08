/**
 * \file main.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de clacule matriciel avec les methodes gauss ou/et cholesky.
 * \version 0.1
 * \date 21 octobre 2019
 *
 * Programme de clacule matriciel avec les methodes gauss ou/et cholesky.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include "gauss.h"
#include "testMatrice.h"
#include "cholesky.h"
#include "display.h"

int main(){
    //test_gauss_Dyn(10000);
    //test_cholesky_Dyn(10000);

    double tab[9] = {4,0,3,
                     0,5,2,
                     3,2,9},
    res[3]={1,
            1,
            1};
    int dim = 3;
    double tmpTab[9];
    copy(tab, tmpTab, dim);
    printf("matrice : \n");
    display_tab(tab, dim);
    cholesky(tab, res, dim);
    //gauss(tab, res, dim);
    printf("resultat : \n");
    display_tab_res(res, 3);
    printf("erreur %.2f\n", error(tmpTab,res,dim));
    return 0;
    
}
