#include "matriz.h"
#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void gauss (int n, double** a, double* b, double* x){

    double f;
    double s;
    double tempa,tempb;
    int p;

    //eliminação com pivotamento
    for(int j = 0;j < (n - 1);j++){

        // antes da eliminação da coluna j - pivotamento
        p = j;
        for(int k = (j+1);k < n;k++){
            // busca linha k com maior pivô
            if(fabs(a[k][j]) > fabs(a[p][j])){
                p = k;
            }
        }

        if(p != j){
            for(int k = j;k < n;k++){
                tempa = a[j][k];
                a[j][k] = a[p][k];
                a[p][k] = tempa;
            }

            tempb = b[j];
            b[j] = b[p];
            b[p] = tempb;
        }
        

        //elimina coluna j
        for(int i = (j+1);i < n;i++){
            //calcula fator de eliminacao da coluna j na linha Li
            f = (a[i][j])/(a[j][j]);
            
            for(int k = j; k < n;k++){
                //Atualiza linha Li, em cada a[i][k] para todo k >=j
                a[i][k] -= a[j][k] * f;
            }

            b[i] -= b[j] * f;
        }
    }


    //retrosubstituição

    for(int i = (n - 1); i >= 0; i--){
        //calcula cada xi
        s = 0;
        for(int j = (i+1); j < n;j++){
            //calcula somatorio com xi ja calculados
            s  += a[i][j] * x[j];
        }
        //após for
        x[i] = (b[i] - s)/(a[i][i]);
    }

    return;
}