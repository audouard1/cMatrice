#include <stdio.h>
#include <stdlib.h>

void gauss(double *tab, double *res, int N){
    double coeff;
    int i,j, n;
    for (i = 0; i < N; i++){
        for(n = 0; n < N-(i+1); n++){
            coeff = tab[(i+1+n)*N + i]/tab[i*N + i];
            printf("coef %f i:%d n:%d tab1:%f tab2:%f  \n", coeff, i, n, tab[i*N + i], tab[(i+1+n)*N + i]);
            for ( j = 0; j < N; j++){
                tab[(i+1+n)*N+j] = tab[(i+1+n)*N+j] - coeff*tab[i*N+j];
            }
            res[(i+1+n)] = res[(i+1+n)] - coeff*res[i];
        }
    }
    for (i = N-1; i >= 0; i--){
        for(n = 0; n < N-i; n++){
            res[i] = res[i]/tab[i*N+i];
        }
    }
}