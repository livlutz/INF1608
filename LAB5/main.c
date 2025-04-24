#include "mmq.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

int main (void)
{
  {
    int m = 5;
    double** A = mat_cria(5,3);
    A[0][0] =  3; A[0][1] = -1; A[0][2] =  2;
    A[1][0] =  4; A[1][1] =  1; A[1][2] =  0;
    A[2][0] = -3; A[2][1] =  2; A[2][2] =  1;
    A[3][0] =  1; A[3][1] =  1; A[3][2] =  5;
    A[4][0] = -2; A[4][1] =  0; A[4][2] =  3;
    double b[] = { 10, 10, -5, 15, 0};
    double x[3];
    double erro;
    
    // TODO: chamar m�todo mmq
    erro = mmq(m, 3, A, b, x);

    printf("solucao:\n");

    for(int i = 0; i < 3; i++){
      printf("x[%d] = %g\n",i, x[i]);
    }

    printf("Ax:\n");

    double* Ax = vet_cria(m);
    mat_multv(m, 3, A, x, Ax);
    
    for(int i = 0; i < m; i++){
      printf("Ax[%d] = %g\n",i, Ax[i]);
    }

    printf("Erro : %g\n\n",erro);

    vet_libera(Ax);
    mat_libera(5, A);
  }
  printf("-------------------------\n");
  {
    double** A = mat_cria(5,4);
    A[0][0] =  4; A[0][1] = 2; A[0][2] =  3; A[0][3] =  0;
    A[1][0] = -2; A[1][1] = 3; A[1][2] = -1; A[1][3] =  1;
    A[2][0] =  1; A[2][1] = 3; A[2][2] = -4; A[2][3] =  2;
    A[3][0] =  1; A[3][1] = 0; A[3][2] =  1; A[3][3] = -1;
    A[4][0] =  3; A[4][1] = 1; A[4][2] =  3; A[4][3] = -2;
    double b[] = { 10, 0, 2, 0, 5};
    double x[4];
    double erro2;
    
    // TODO: chamar m�todo mmq
    erro2 = mmq(5, 4, A, b, x);

    printf("solucao:\n");
    for(int i = 0; i < 4; i++){
      printf("x[%d] = %g\n",i, x[i]);
    }

    printf("Ax:\n");
    double* Ax = vet_cria(5);
    mat_multv(5, 4, A, x, Ax);

    for(int i = 0; i < 5; i++){
      printf("Ax[%d] = %g\n",i, Ax[i]);
    }
    
    printf("Erro : %g\n\n",erro2);

    vet_libera(Ax);
    mat_libera(5, A);
  }
  printf("-------------------------\n");
  {
    double px[] = {-1,0,1,2};
    double py[] = {1,0,0,-2};
    double a, b, c, d,erroParabola,erroCubica;
	  // TODO: chamar ajuste de parabola
    erroParabola = ajuste_parabola(4, px, py, &a, &b, &c);
    
    printf("parabola:\n");
    printf("Erro: %g\n",erroParabola);
    printf("a = %g b = %g c = %g\n",a,b,c);

	  // TODO: chamar ajuste de cubica
    erroCubica = ajuste_cubica(4, px, py, &a, &b, &c, &d);

    printf("cubica:\n");
    printf("Erro: %g\n",erroCubica);
    printf("a = %g b = %g c = %g d = %g\n",a,b,c,d);

  }
  printf("-------------------------\n");
  {
    double px[] = {0,1,2,5};
    double py[] = {0,3,3,6};
    double a, b, c, d, erroParabola2, erroCubica2;
	  // TODO: chamar ajuste de parabola
    erroParabola2 = ajuste_parabola(4, px, py, &a, &b, &c);
    
    printf("parabola:\n");
    printf("Erro: %g\n",erroParabola2);
    printf("a = %g b = %g c = %g\n",a,b,c);

	  // TODO: chamar ajuste de cubica

    erroCubica2 = ajuste_cubica(4, px, py, &a, &b, &c, &d);

    printf("cubica:\n");
    printf("Erro: %g\n",erroCubica2);
    printf("a = %g b = %g c = %g d = %g\n",a,b,c,d);
  }
  printf("-------------------------\n");
  {
    double px[] = {1,3,4,6};
    double py[] = {2,2,1,3};
    double a, b, c, d, erroParabola3, erroCubica3;
	  // TODO: chamar ajuste de parabola

    erroParabola3 = ajuste_parabola(4, px, py, &a, &b, &c);
    
    printf("parabola:\n");
    printf("Erro: %g\n",erroParabola3);
    printf("a = %g b = %g c = %g\n",a,b,c);
	  
    // TODO: chamar ajuste de cubica

    erroCubica3 = ajuste_cubica(4, px, py, &a, &b, &c, &d);
    printf("cubica:\n");
    printf("Erro: %g\n",erroCubica3);
    printf("a = %g b = %g c = %g d = %g\n",a,b,c,d);
  }
  printf("-------------------------\n");
  {
    double px[] = { 1950,  1955,  1960,   1965,   1970,   1975,   1980};
    double py[] = {53.05, 73.04, 98.31, 139.78, 193.48, 260.20, 320.39};
    double a, b,erroExpenencial;

	  // TODO: chamar ajuste exponencial
    
    erroExpenencial = ajuste_exponencial_exp(7, px, py, &a, &b);
    printf("exponencial:\n");
    printf("Erroln: %g\n",erroExpenencial);
    printf("a = %g b = %g\n",a,b);
  }
  printf("-------------------------\n");
  {
    double px[] = { 0,  5, 10,   15,   20,   25,   30};
    double py[] = {53.05, 73.04, 98.31, 139.78, 193.48, 260.20, 320.39};
    double a, b,erroExpenencial2;
	  // TODO: chamar ajuste exponencial

    erroExpenencial2 = ajuste_exponencial_exp(7, px, py, &a, &b);
    printf("exponencial:\n");
    printf("Erroln: %g\n",erroExpenencial2);
    printf("a = %g b = %g\n",a,b);
  }
   	
  return 0; 
}

