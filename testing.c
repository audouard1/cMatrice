/**
 * \file testing.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme de test du temps d'execution des methodes gauss et cholesky.
 * \version 0.1
 * \date 21 octobre 2019
 *
 * Programme de test du temps d'execution des methodes gauss et cholesky.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "testing.h"
#include "gauss.h"
#include "cholesky.h"
#include "testMatrice.h"


/**
 * \fn error(double tab[], double res[], int N)
 * \brief Fonction pour calculer l'erreur cummulée sur une matrice.
 *
 * \param tab tableau contenant la matrice de départ.
 * \param N dimention de la matrice.
 * \param res tableau contenant les résultat pour la matrice "tab", après exécution d'une méthode de résolution
 * \return la somme des différences entre le résulat voulu et le résultat obtenu pour chaque ligne de la matrice.
 */
double error(double tab[], double res[], int N){
    int i,j;
    double tmp;
    double error = 0;
    for(i =0; i<N; i++){
        tmp = 0;
        for(j =0; j < N; j++){
            tmp = tmp + tab[i*N+j] * res[j];
        }
        error = error + pow(1.0-tmp, 2);
    }
    return sqrt(error);
}

/**
 * \fn void gauss_testing_core(int maxDim, double tab[], double res[])
 * \brief Fonction qui exécute une résolution par gauss pour chaque dimension jusqu'a la dimension saisi, puis affiche le temps d'execution, la dimension et l'erreur dans l'entrée standard si le temps d'execution est suppérieur a zero 
 * \param maxDim dimension max de la matrice
 * \param tab tableau pour contenir une matrice
 * \param res tableau pour contenir les résultats d'une matrice.
 */
void gauss_testing_core(int maxDim, double tab[], double res[]){
    int i,j;
    double err, *clone;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for( j = 100; j < maxDim; j+=100){
        for( i = 0; i < j; i++){
            res[i] = 1;
        }
        init_zero(tab,j);
        kms(tab,j);
        clone = calloc(j*j, sizeof(double));
        if(make_valide_gauss(tab,res,j)){
            copy(tab, clone, j);
            start=clock();
            gauss(tab, res, j);
            end=clock();
            init_zero(tab,j);
            err = error(clone, res, j);
            double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
            if(extime != 0.0){
                printf("%f;%d;%f\n",extime, j, err);
            }
        }
        free(clone);
    }
}

/**
 * \fn void gauss_testing_core(int maxDim, double tab[], double res[])
 * \brief Fonction qui exécute une résolution par cholesky pour chaque dimension jusqu'a la dimension saisi, puis affiche le temps d'execution, la dimension et l'erreur dans l'entrée standard si le temps d'execution est suppérieur a zero 
 * \param maxDim dimension max de la matrice
 * \param tab tableau pour contenir une matrice
 * \param res tableau pour contenir les résultats d'une matrice.
 */
void cholesky_testing_core(int maxDim, double tab[], double res[]){
    int i,j;
    double err, *clone;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for( j = 1; j < maxDim; j++){
        for( i = 0; i < j; i++){
            res[i] = 1;
        }
        clone = calloc(j*j, sizeof(double));
        init_zero(tab,j);
        moler(tab, j);
        copy(tab, clone, j);
        start=clock();
        cholesky_Dyn(tab, res, j);
        end=clock();
        init_zero(tab,j);
        kms(tab, j);
        err = error(clone, res, j);
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0.0){
                printf("%f;%d;%f\n",extime, j, err);
            }
        free(clone);
    }
}

/**
 * \fn void test_gauss()
 * \brief Fonction pour tester la rapidité de l'execution de gauss en fonction de la taille de la matrice, avec une allocation fixe qui va jusqu'a une matrice de dimention 1000
 */
void test_gauss(){
    double tab[1000000], a[1000], err; 
    gauss_testing_core(1000, tab, a);
}

/**
 * \fn void test_gauss()
 * \brief Fonction pour tester la rapidité de l'execution de cholesky en fonction de la taille de la matrice, avec une allocation fixe d'un tableau qui va jusqu'a une matrice de dimension 1000
 */
void test_cholesky(){
    double tab[1000000], a[1000]; 
    cholesky_testing_core(1000, tab, a);
}
    
/**
 * \fn void test_gauss_Dyn(int maxDim)
 * \brief Fonction pour tester la rapidité de l'execution de gauss en fonction de la taille de la matrice, avec une allocation dynamique d'un tableau qui va jusqu'a une matrice de dimension saisi
 * \param maxDim dimension max de la matrice
 */
void test_gauss_Dyn(int maxDim){
    double *tab, *a; 
    tab = calloc(maxDim*maxDim, sizeof(double));
    a = calloc(maxDim, sizeof(double));
    if(tab == NULL || a == NULL){
        printf("PB malloc");
        exit(0);
    }
    gauss_testing_core(maxDim, tab, a);
    free(tab);
    free(a);
}

/**
 * \fn void test_cholesky_Dyn(int maxDim)
 * \brief Fonction pour tester la rapidité de l'execution de cholesky en fonction de la taille de la matrice, avec une allocation dynamique d'un tableau qui va jusqu'a une matrice de dimension saisi
 * \param maxDim dimension max de la matrice
 */
void test_cholesky_Dyn(int maxDim){
    double *tab, *a; 
    tab = calloc(maxDim*maxDim, sizeof(double));
    a = calloc(maxDim, sizeof(double));
    if(tab == NULL || a == NULL){
        printf("PB malloc");
        exit(0);
    }
    cholesky_testing_core(maxDim, tab, a);
    free(tab);
    free(a);
}

