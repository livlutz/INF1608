#include "vetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* vet_cria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}

void vet_libera (double* v)
{
  free(v);
}

void vet_mults (int n, double* v, double s, double* w)
{
  for (int i=0; i<n; ++i)
    w[i] = v[i]*s;
}

void vet_imprime (int n, double* v)
{
  for (int i=0; i<n; ++i)
    printf("%.16g  ",v[i]);
  printf("\n");
}
