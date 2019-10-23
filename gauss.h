/**
 * \file gauss.h
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief fichier contenant le prototype des fonctions du programme gauss
 * \version 0.1
 * \date 21 octobre 2019
 *
 * fichier contenant le prototype des fonctions du programme gauss
 *
 */

#include <stdbool.h>

#ifndef H_GAUSS
#define H_GAUSS


void gauss(double *tab, double *res, int N);
void gauss_inff(double *tab, double *res, int N);
void gauss_res(double *tab, double *res, int N);
bool make_valide_gauss(double *tab, double *res, int N);
void gauss_supp(double *tab, double *res, int N);

#endif