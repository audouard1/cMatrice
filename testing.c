/**
 * \file testing.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \version 0.1
 * \date 21 octobre 2019
 *
 * Programme de test des methode gauss et cholesky.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gauss.h"
#include "cholesky.h"
#include "testMatrice.h"
#include "display.h"


double error(double tab[], double res[], int N){
    int i,j;
    double tmp;
    double error;
    for(i =0; i<N; i++){
        tmp = 0;
        for(j =0; j < N; j++){
            tmp = tmp + tab[i*N+j] * res[j];
        }
        error =  1.0-tmp;
    }
    return error;
}

/**
 * test la rapidité de l'execution de gauss en fonction de la taille de la matrice
 */
void test_gauss(){
    double tab[1000000], a[1000], err; 
    int i,j;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for( j = 100; j < 1000; j++){
        for( i = 0; i < j; i++){
            a[i] = 1;
        }
        init_zero(tab,j);
        a_bord1(tab,j);
        if(make_valide_gauss(tab,a,j)){
            start=clock();
            gauss(tab, a, j);
            end=clock();
        }
        init_zero(tab,j);
        a_bord1(tab,j);
        err = error(tab, a, j);
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d;%f\n",extime, j, err);
        }
    }
}

/**
 * test la rapidité de l'execution de gauss en fonction de la taille de la matrice
 */
void test_cholesky(){
    double tab[1000000], a[1000]; 
    int i,j;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for( j = 1; j < 10; j++){
        for( i = 0; i < j; i++){
            a[i] = 1;
        }
        init_zero(tab,j);
        matrice_sym_pos(tab, j);
        start=clock();
        cholesky(tab, a, j);
        end=clock();
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%d ieme itération : %f;%d\n", i,extime, j);
        }
    }
}

/**
 * test la rapidité de l'execution de gauss en fonction de la taille de la matrice
 */
void test_gauss_Dyn(int maxDim){
    double *tab, *a, err; 
    tab = calloc(maxDim*maxDim, sizeof(double));
    a = calloc(maxDim, sizeof(double));
    if(tab == NULL || a == NULL){
        printf("PB malloc");
        exit(0);
    }
    int i,j;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for( j = 100; j < 1000; j++){
        for( i = 0; i < j; i++){
            a[i] = 1;
        }
        init_zero(tab,j);
        a_bord1(tab,j);
        if(make_valide_gauss(tab,a,j)){
            start=clock();
            gauss(tab, a, j);
            end=clock();
        }
        init_zero(tab,j);
        a_bord1(tab,j);
        err = error(tab, a, j);
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d;%f\n",extime, j, err);
        }
    }
    free(tab);
    free(a);
}

/**
 * test la rapidité de l'execution de gauss en fonction de la taille de la matrice
 */
void test_cholesky_Dyn(int maxDim){
    double *tab, *a, err; 
    tab = calloc(maxDim*maxDim, sizeof(double));
    a = calloc(maxDim, sizeof(double));
    if(tab == NULL || a == NULL){
        printf("PB malloc");
        exit(0);
    }
    int i,j;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for( j = 100; j < 1000; j++){
        for( i = 0; i < j; i++){
            a[i] = 1;
        }
        init_zero(tab,j);
        matrice_sym_pos(tab, j);
        start=clock();
       //display_tab(tab, j);
        cholesky(tab, a, j);
        //display_tab_res(a,j);
        end=clock();
        init_zero(tab,j);
        matrice_sym_pos(tab, j);
        err = error(tab, a, j);
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d;%f\n",extime, j, err);
        }
    }
    free(tab);
    free(a);
}
    
