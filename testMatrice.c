#include<stdio.h>
#include<math.h>


#define N 3

int min(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}

void init_zero(double tab[]){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 0;
        }
    }
}

void a_bord1(double tab[]){
    
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

void a_bord2(double tab[]){
    
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

void ding_dong(double tab[]){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 1.0/(2*(N-(i+1)-(j+1)+1.5));
        }
    }
}

void franc(double tab[]){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i >= j+2){
                tab[i*N+j] = 0;
            }
            else{
                tab[i*N+j] = min(i,j)+1;
            }
        }
    }
}

void hilbert(double tab[]){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 1.0/((i+1)+(j+1)-1);
        }
    }
}

void hilbert2(double tab[]){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = 1.0/((i+1)+(j+1)+1);
        }
    }
}

void kms(double tab[]){
    int i,j;
    double p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tab[i*N+j] = pow(p, fabs(i-j));
        }
    }
}

void lehmer(double tab[]){
    int i,j;
    double p = 0.5;
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

void lotkin(double tab[]){
    int i,j;
    double p = 0.5;
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

void moler(double tab[]){
    int i,j;
    double p = 0.5;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == j){
                tab[i*N+j] = i+1;
            }
            else{
                tab[i*N+j] = min(i,j)-1;
            }
        }
    }
}

void affiche_tab(double *tab){
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%.2f ",tab[i*N+j]);
        }
        printf("\n");
    }
}

void affiche_tab_res(double *tab){
    int i,j;
    for(i = 0; i < N; i++){
        printf("%.20f \n",tab[i]);
    }
}




