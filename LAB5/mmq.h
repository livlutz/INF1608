#ifndef MMQ_H
#define MMQ_H

double mmq (int m, int n, double** A, double* b, double* x);
double ajuste_parabola (int n, double* px, double* py, double* a, double* b, double* c);
double ajuste_cubica (int n, double* px, double* py, double* a, double* b, double* c, double* d);
double ajuste_exponencial_exp (int n, double* px, double* py, double* a, double* b);
double** mat_cria (int m, int n);
void mat_libera (int m, double** A);
void mat_transposta (int m, int n, double **A, double** T);
void mat_multv (int m, int n, double** A, double* v, double* w);
void mat_multm (int m, int n, int q, double** A, double** B, double** C);
double* vet_cria (int n);
void vet_libera (double* v);
double vet_escalar (int n, double* v, double* w);
double vet_norma2 (int n, double* v);
void gauss (int n, double** a, double* b, double* x);
#endif