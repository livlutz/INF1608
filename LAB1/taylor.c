#include "taylor.h"
#include <stdlib.h>

double avalia_taylor (int n, double* c, double x0, double x){
    
    if(n == 0){
        return 0;
    }
    
    double f = 1.0,d = 1.0;
    int i = 0;
    double soma = 0.0;

    while(i < n){
       soma += (c[i]/f) * d;
       i++;
       f *= i;
       d *= (x-x0);
    }

    return soma;
}



double avalia_seno (int n, double x){

    double x0 = 0.0;
    double v[] = {0,1,0,-1};
    double * c = (double*)malloc(n * sizeof(double));
    int id;

    for(int i = 0;i < n;i++){
       id = i % 4;
       c[i] = v[id];
    }

    double resultado = avalia_taylor(n,c,x0,x);
    free(c);

    return resultado;

}
