#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
  
void mat_imprime (int m, int n, double** A)
{
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      printf("%.16g  ", A[i][j]);
    }
    printf("\n");
  }
}