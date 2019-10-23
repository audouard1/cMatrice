/**
 * \file cholesky.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme pour la résolution de matrice avec la methodes de cholesky.
 * \version 0.1
 * \date 21 octobre 2019
 *
 * Programme pour la résolution de matrice avec la methodes de cholesky.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"

/**
 * \fn int decomp_cholesky(double *tab, double *decomp, int N)
 * \brief Fonction pour obtenir la matrice triangulaire inférieure
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param decomp tableau contenant la matrice décomposé par cholesky
 * \param N dimention de la matrice.
 */
int decomp_cholesky(double *tab, double *decomp, int N){
    int i, j, k;
    double somme, s;
    for(i = 0; i < N; i++){
        somme = 0;
        for(j = 0; j <= i-1; j++){
            somme += pow(decomp[i*N + j], 2);
        }
        s = tab[i*N + i] - somme;
        if(s <= 0){
            printf("erreur cholesky : matrice non definie positive\n");
            return -1;
        }
        decomp[i*N + i] = sqrt(s);
        for(j = i+1; j < N; j++){
            somme = 0;
            for (k = 0; k <= i-1; k++)
            {
                somme += decomp[i*N + k] * decomp[j*N + k];
            }
            decomp[j*N + k] = (tab[j*N + i] - somme) / decomp[i*N + i];
        }
    }

}

/**
 * \fn void equation1(double *tab, double *res, double *y, int N)
 * \brief Fonction d'equation avec matrice triangulaire inférieure
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param res résultat voulu pour la matrice "tab"
 * \param y ?
 * \param N dimention de la matrice.
 */
void equation1(double *tab, double *res, double *y, int N){
    int i, j;
    double somme;
    y[0] = res[0]/tab[0];
    for(i = 1; i < N; i++){
        somme = 0;
        for (j = 0; j < i; j++){
            somme += tab[i*N+j]*y[j];
        }
        y[i] = (res[i]-somme)/tab[i*N+i];
    }
}

/**
 * \fn void equation1(double *tab, double *res, double *y, int N)
 * \brief Fonction qui réalise equation 1 dans l'autre sens (avec matrice triangulaire supérieure)
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param res résultat voulu pour la matrice "tab"
 * \param y ?
 * \param N dimention de la matrice.
 */
void equation2(double *tab, double *res, double *y, int N){
    int i, j;
    double somme;
    y[N-1] = res[N-1]/tab[(N-1)*N+N-1];
    for(i = N-2; i >= 0; i--){
        somme = 0;
        for (j = N-1; j > i; j--){
            somme += tab[i*N+j]*y[j];
        }
        y[i] = (res[i]-somme)/tab[i*N+i];
    }
}

/**
 * \fn void cholesky(double *tab, double *res, int N)
 * \brief Fonction pour calculer le résultat d'une matrice donnée avec la méthode de cholesky
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param res tableau contenant les résultats voulu pour la matrice "tab" donnée.
 * \param N dimention de la matrice.
 */
int cholesky(double *tab, double *res, int N){
    int err;
    double *decomp = calloc(N*N, sizeof(double)), y[10000];
    if(decomp == NULL){
        printf("PB malloc");
        exit(0);
    }
    init_zero(decomp, N);
    err = decomp_cholesky(tab, decomp, N);
    if(err == -1){exit(0);}
    //R * y = b
    equation1(decomp, res, y, N);
    transpose(decomp, N);
    //Rt * x = y
    equation2(decomp, y, res, N);
    free(decomp);
}