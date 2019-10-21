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
    float tab[1000000], a[1000], err; 
    int i,j;
    clock_t start, end;
    printf("time(ms);dim;error\n");
    for( j = 3; j < 4; j++){
        for( i = 0; i < j; i++){
            a[i] = 1;
        }
        init_zero(tab,j);
        a_bord2(tab,j);
        if(make_valide_gauss(tab,a,j)){
            start=clock();
            display_tab(tab, j);
            gauss(tab, a, j);
            display_tab(tab, j);
            display_tab_res(a,j);
            end=clock();
        }
        init_zero(tab,j);
        a_bord2(tab,j);
        err = error(tab, a, j);
        double extime=(double) (end-start)*1000.0/CLOCKS_PER_SEC;
        if(extime != 0){
            printf("%f;%d;%f\n",extime, j, err);
        }
    }

    
}