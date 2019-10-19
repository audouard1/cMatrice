#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"


void decomp_cholesky(float *tab, float *decomp, int N){
    int i, j;
    for(i = 0; i < N; i++){
        decomp[i*N + i] = sqrt(tab[i*N + i]);
        for (j = i+1; j < N; j++)
        {
            decomp[i*N + j] = tab[i*N + j]/decomp[i*N + i];
        }
        
    }
}






int cholesky(float *tab, float *res, int N){
    float decomp[100];
    decomp_cholesky(tab, decomp, N);
    affiche_tab(decomp);

}