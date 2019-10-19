#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"

int decomp_cholesky(float *tab, float *decomp, int N){
    int i, j, s, k;
    float somme;
    for(i = 0; i < N; i++){
        somme = 0;
        for(j = 0; j <= i-1; j++){
            somme += pow(decomp[j*N + i], 2);
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
                somme += decomp[k*N + i] * decomp[k*N + j];
            }
            decomp[i*N + j] = (tab[i*N + j] - somme) / decomp[i*N + i];
        }
    }

}




int cholesky(float *tab, float *res, int N){
    float decomp[100];
    init_zero(decomp);
    decomp_cholesky(tab, decomp, N);
    printf("decomposition Cholesky :\n");
    affiche_tab(decomp);

}