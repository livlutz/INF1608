#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mmq.h"

double** mat_cria (int m, int n)
{
  double** A = (double**) malloc(m*sizeof(double*));
  for (int i=0; i<m; ++i)
    A[i] = (double*) malloc(n*sizeof(double));
  return A;
}

void mat_libera (int m, double** A)
{
  for (int i=0; i<m; ++i)
    free(A[i]);
  free(A);
}

void mat_transposta (int m, int n, double **A, double** T)
{
  for (int i=0; i<m; ++i)
    for (int j=0; j<n; ++j)
      T[j][i] = A[i][j];
}
  
void mat_multv (int m, int n, double** A, double* v, double* w)
{
  for (int i=0; i<m; ++i) {
    w[i] = 0.0;
    for (int j=0; j<n; ++j)
      w[i] += A[i][j] * v[j];
  }
}
  
void mat_multm (int m, int n, int q, double** A, double** B, double** C)
{
  for (int i=0; i<m; ++i) {
    for (int k=0; k<q; ++k) {
      C[i][k] = 0.0;
      for (int j=0; j<n; ++j) 
        C[i][k] += A[i][j] * B[j][k];
    }
  }
}
  

double* vet_cria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}

void vet_libera (double* v)
{
  free(v);
}

double vet_escalar (int n, double* v, double* w)
{
  double s = 0;
  for (int i=0; i<n; ++i)
    s += v[i]*w[i];
  return s;
}

double vet_norma2 (int n, double* v)
{
  double s = vet_escalar(n,v,v);
  return sqrt(s);
}

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

double mmq (int m, int n, double** A, double* b, double* x){
    double **AT = mat_cria(n,m);
    double **ATA = mat_cria(n,n);
    double *ATb = vet_cria(n);
    double *r = vet_cria(m);
    double *Ax = vet_cria(m);
    double norma2 = 0.0;
    
    //calcula transposta de A
    mat_transposta(m,n,A,AT);
    
    //multiplica AT*A
    mat_multm(n,m,n, AT, A, ATA);
    
    //mltiplica AT*b
    mat_multv(n,m, AT, b, ATb); 

    //resolve ATAx = ATb
    gauss(n, ATA, ATb, x);

    //multiplica A*x
    mat_multv(m,n,A,x,Ax);

    //r = b-Ax
    for(int i = 0;i < m;i++){
        r[i] = b[i] - Ax[i];
    }

    //calcula norma2 de r
    norma2 = vet_norma2(m,r);

    //libera memoria
    mat_libera(n,ATA);
    mat_libera(n,AT);
    vet_libera(ATb);
    vet_libera(r);
    vet_libera(Ax);

    return norma2;
}

double ajuste_parabola (int n, double* px, double* py, double* a, double* b, double* c){
    double** A = mat_cria(n,3);
    double* Y = vet_cria(n);
    double coef[3];
    double norma2;
    
    for (int i = 0; i < n; i++) {
        A[i][0] = 1;
        A[i][1] = px[i];
        A[i][2] = px[i] * px[i];
        Y[i] = py[i];
    }
    
    norma2 = mmq(n,3,A,Y,coef);
    
    *a = coef[0];
    *b = coef[1];
    *c = coef[2];
    
    mat_libera(n,A);
    vet_libera(Y);
    
    return norma2;
}
double ajuste_cubica (int n, double* px, double* py, double* a, double* b, double* c, double* d){
    double** A = mat_cria(n,4);
    double* Y = vet_cria(n);
    double coef[4];
    double norma2;
    
    for (int i = 0; i < n; i++) {
        A[i][0] = 1;
        A[i][1] = px[i];
        A[i][2] = px[i] * px[i];
        A[i][3] = px[i] * px[i] * px[i];
        Y[i] = py[i];
    }
    
    norma2 = mmq(n,4,A,Y,coef);
    
    *a = coef[0];
    *b = coef[1];
    *c = coef[2];
    *d = coef[3];
    
    mat_libera(n,A);
    vet_libera(Y);
    
    return norma2;
}

double ajuste_exponencial_exp (int n, double* px, double* py, double* a, double* b){
    double** A = mat_cria(n,2);
    double* lny = vet_cria(n);
    double coef[2];
    double norma2;
    
    for (int i = 0; i < n; i++) {
        A[i][0] = 1;
        A[i][1] = px[i];
        lny[i] = log(py[i]);
    }
    
    norma2 = mmq(n,2,A,lny,coef);
    
    *a = exp(coef[0]);
    *b = coef[1];
    
    mat_libera(n,A);
    vet_libera(lny);
    
    return norma2;
}