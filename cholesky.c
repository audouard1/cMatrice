#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"

//trouve la matrice triangualaire inférieure (la première dont on a besoin pour les calculs)
int decomp_cholesky(float *tab, float *decomp, int N){
    int i, j, s, k;
    float somme;
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

//equation avec matrice triangulaire inférieure
void equation1(float *tab, float *res, float *y, int N){
    int i, j;
    float somme;
    y[0] = res[0]/tab[0];
    for(i = 1; i < N; i++){
        somme = 0;
        for (j = 0; j < i; j++){
            somme += tab[i*N+j]*y[j];
        }
        y[i] = (res[i]-somme)/tab[i*N+i];
    }
}

//equation 1 dans l'autre sens (avec matrice triangulaire supérieure)
void equation2(float *tab, float *res, float *y, int N){
    int i, j;
    float somme;
    y[N-1] = res[N-1]/tab[(N-1)*N+N-1];
    for(i = N-2; i >= 0; i--){
        somme = 0;
        for (j = N-1; j > i; j--){
            somme += tab[i*N+j]*y[j];
        }
        y[i] = (res[i]-somme)/tab[i*N+i];
    }
}

int cholesky(float *tab, float *res, int N){
    float decomp[100], y[N];
    init_zero(decomp);
    decomp_cholesky(tab, decomp, N);
    //R * y = b
    equation1(decomp, res, y, N);
    transpose(decomp);
    //Rt * x = y
    equation2(decomp, y, res, N);
}