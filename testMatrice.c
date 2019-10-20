#include<stdio.h>
#include<math.h>

void init_zero(float tab[], int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 0;
        }
    }
}

void transpose(float tab[], int N){
    int i, j, sauv;
    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){
            sauv = tab[i*N+j];
            tab[i*N+j] = tab[j*N+i];
            tab[j*N+i] = sauv;
        }
    }
}

void a_bord1(float tab[], int N){
    
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i+1 == j+1){
                tab[i*N+j] = 1;
            }
            else{
                if(i == 0){
                    tab[i*N+j] = pow(2, -j);
                    tab[j*N] = pow(2, -j);
                }               
            }
        }
    }
}

void a_bord2(float tab[], int N){
    
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i+1 == j+1){
                tab[i*N+j] = 1;
            }
            else{
                if(i+1 == N){
                    tab[i*N+j] = pow(2, N-(j+1));
                    tab[j*N+N-1] = pow(2, N-(j+1));
                }
                
            }  
        }
    }
}

void ding_dong(float tab[], int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 1.0/(2*(N-(i+1)-(j+1)+1.5));
        }
    }
}

void franc(float tab[], int N){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i >= j+2){
                tab[i*N+j] = 0;
            }
            else{
                tab[i*N+j] = fmin(i,j)+1;
            }
        }
    }
}

void hilbertPlus(float tab[], int N, int plus){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 1.0/((i+1)+(j+1)+plus);
        }
    }
}

void hilbert(float tab[], int N){
    hilbertPlus(tab, N, 1);
}

void hilbert2(float tab[], int N){
    hilbertPlus(tab, N, -1);
}

void kms(float tab[], int N){
    int i,j;
    float p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = pow(p, fabs(i-j));
        }
    }
}

void lehmer(float tab[], int N){
    int i,j;
    float p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i <= j){
                tab[i*N+j] = (i+1.0)/(j+1.0);
            }
            else{
                tab[i*N+j] = (j+1.0)/(i+1.0);
            }
        }
    }
}

void lotkin(float tab[], int N){
    int i,j;
    float p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == 0){
                tab[i*N+j] = 1;
            }
            else{
                tab[i*N+j] = 1.0/((i+1)+(j+1)-1);
            }
        }
    }
}

void moler(float tab[], int N){
    int i,j;
    float p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == j){
                tab[i*N+j] = i+1;
            }
            else{
                tab[i*N+j] = fmin(i,j)-1;
            }
        }
    }
}

void matrice_creuse(float tab[], int N, int pourcent){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(rand()%100+1 <= pourcent){
                tab[i*N+j] = 0;
            }
            else{
                tab[i*N+j] = 1;
            }
            
        }
    }
}






