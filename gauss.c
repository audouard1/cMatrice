#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gauss_supp(double *tab, double *res, int N){
    double coeff;
    int i,j, n, l,li;
    for (i = 0; i < N-1; i++){
        for(n = i+1; n < N; n++){
            coeff = tab[n*N + i]/tab[i*N + i];
            //printf("coef %f i:%d n:%d tab1:%f tab2:%f  \n", coeff, i, n, tab[i*N + i], tab[(i+1+n)*N + i]);
            for (j = i+1; j < N; j++){//todo i+1
                tab[n*N+j] = tab[n*N+j] - coeff*tab[i*N+j];
            }
            res[n] = res[n] - coeff*res[i];
        }
    }
}

void gauss_inff(double *tab, double *res, int N){
    double coeff;
    int i, n, l,li;
    for (i = N-1; i > 0; i--){
        for(n = i-1; n >= 0; n--){
            coeff = tab[n*N + i]/tab[i*N + i];
            //printf("coef %f i:%d n:%d tab1:%f tab2:%f  res:n %f\t%f\t%f\n", coeff, i, n, tab[i*N + i], tab[n*N + i],res[0], res[1], res[2]);
            tab[n*N+i] = tab[n*N+i] - coeff*tab[i*N+i];
            res[n] = res[n] - coeff*res[i];
        }
    }
}

void gauss_res(double *tab, double *res, int N){
    int i;
    for(i = 0; i<N; i++){
        res[i]= res[i]/tab[i*N+i];
    }
}

void gauss(double *tab, double *res, int N){
    gauss_supp(tab, res, N);
    gauss_inff(tab, res, N);
    gauss_res(tab, res, N);

}

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