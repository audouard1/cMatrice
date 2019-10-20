#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gauss.h"
#include "cholesky.h"
#include "testMatrice.h"
#include "display.h"

float error(float tab[], float res[], int N){
    int i,j;
    float tmp;
    float error;
    for(i =0; i<N; i++){
        tmp = 0;
        for(j =0; j < N; j++){
            tmp = tmp + tab[i*N+j] * res[j];
        }
        error =  1.0-tmp;
    }
    return error;
}

void test_gauss(){
    float tab[10000], a[100], err; 
    int i,j;
    
    for( j = 3; j < 100; j++){
        for( i = 0; i < j; i++){
            a[i] = 1;
        }
        init_zero(tab,j);
        a_bord1(tab,j);
        clock_t start=clock();
        gauss(tab, a, j);
        clock_t end=clock();
        init_zero(tab,j);
        a_bord1(tab,j);
        err = error(tab, a, j);
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        printf("time(ms) : %f dim : %d error : %f\n",extime, j, err);
    }
}