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



int main(){
    //test_gauss_Dyn(1000);
    
    test_cholesky(1000);

    return 0;
}
