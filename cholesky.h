/**
 * \file cholesky.h
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief fichier contenant le prototype des fonctions du programme cholesky 
 * \version 0.1
 * \date 21 octobre 2019
 *
 * fichier contenant le prototype des fonctions du programme cholesky
 *
 */

#ifndef H_CHOLES
#define H_CHOLES

int decomp_cholesky(double *tab, double decomp, int N);
void equation1(double *tab, double *res, int N);
void equation2(double *tab, double *res, int N);
int cholesky(double *tab, double *res, int N);
int cholesky_Dyn(double *tab, double *res, int N);

#endif