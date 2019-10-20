#include <stdio.h>
#include <stdlib.h>

void display_tab(float *tab, int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%.2f ",tab[i*N+j]);
        }
        printf("\n");
    }
}

void display_tab_res(float *tab, int N){
    int i,j;
    for(i = 0; i < N; i++){
        printf("%.20f \n",tab[i]);
    }
}