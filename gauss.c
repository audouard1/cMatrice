/**
 * \file gauss.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme pour la résolution de matrice avec la methodes de gauss.
 * \version 0.1
 * \date 21 octobre 2019
 *
 * Programme pour la résolution de matrice avec la methodes de gauss.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * \fn void gauss_supp(double *tab, double *res, int N)
 * \brief Fonction pour obtenir une matrice triangulaire suppérieur avec la méthode de gausse
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param res tableau contenant les résultats voulu pour la matrice "tab" donnée.
 * \param N dimention de la matrice.
 */
void gauss_supp(double *tab, double *res, int N){
    double coeff;
    int i,j, n, l,li;
    for (i = 0; i < N-1; i++){
        for(n = i+1; n < N; n++){
            coeff = tab[n*N + i]/tab[i*N + i];
            for (j = i+1; j < N; j++){
                tab[n*N+j] = tab[n*N+j] - coeff*tab[i*N+j];
            }
            res[n] = res[n] - coeff*res[i];
        }
    }
}

/**
 * \fn void gauss_inff(double *tab, double *res, int N)
 * \brief Fonction pour obtenir une matrice diagonale avec la méthode de gausse
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param res tableau contenant les résultats voulu pour la matrice "tab" donnée.
 * \param N dimention de la matrice.
 */
void gauss_inff(double *tab, double *res, int N){
    double coeff;
    int i, n, l,li;
    for (i = N-1; i > 0; i--){
        for(n = i-1; n >= 0; n--){
            coeff = tab[n*N + i]/tab[i*N + i];
            tab[n*N+i] = tab[n*N+i] - coeff*tab[i*N+i];
            res[n] = res[n] - coeff*res[i];
        }
    }
}

/**
 * \fn void gauss_res(double *tab, double *res, int N)
 * \brief Fonction pour obtenir les résultat de la matrice en fonction d'une matrice diagonale avec ses résultats.
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param res tableau contenant les résultats voulu pour la matrice "tab" donnée.
 * \param N dimention de la matrice.
 */
void gauss_res(double *tab, double *res, int N){
    int i;
    for(i = 0; i<N; i++){
        res[i]= res[i]/tab[i*N+i];
    }
}

/**
 * \fn void gauss(double *tab, double *res, int N)
 * \brief Fonction pour calculer le résultat d'une matrice donnée avec la méthode de gauss
 *
 * \param tab tableau contenant la matrice a résoudre.
 * \param res tableau contenant les résultats voulu pour la matrice "tab" donnée.
 * \param N dimention de la matrice.
 */
void gauss(double *tab, double *res, int N){
    gauss_supp(tab, res, N);
    gauss_inff(tab, res, N);
    gauss_res(tab, res, N);

}

/**
 * \fn bool make_valide_gauss(double *tab, double *res, int N)
 * \brief Fonction pour obtenir des pivots différent de zero pour réaliser la méthode de gauss
 *
 * \param tab tableau contenant la matrice a transformer.
 * \param res tableau contenant les résultats voulu pour la matrice "tab" donnée.
 * \param N dimention de la matrice.
 * \return renvoi vrai si l'agorithme a fonctionné, sinon renvoi faux
 */
bool make_valide_gauss(double *tab, double *res, int N){
    int i,j,n;
    double tmp, tmpres;
    for(i = 0; i<N; i++){
        if(tab[i*N+i]==0){
            for(n = 0; n < N-i;n++){
                if(tab[n*N+i]!=0){
                    for(j = 0; j <N; j++){
                        tmp = tab[i*N+j];
                        tab[i*N+j]=tab[n*N+j];
                        tab[n*N+j] = tmp;
                    }
                    tmpres = res[i];
                    res[i]= res[n];
                    res[n]= res[i];
                }
                else{
                    return false;
                }
            }
        }
    }
    return true;
}