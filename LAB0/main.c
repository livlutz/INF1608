#include "vetor.h"
#include "matriz.h"
#include <stdio.h>
#include <math.h>

int main (void)
{
  /* Exemplo de construção de vetor dinâmico */
  double* v = vet_cria(2);
  v[0] = 1.0;
  v[1] = 2.0;

  /* Exemplo de construção de vetor estático */
  double w[] = {1.0,2.0f};

  /* Imprime vetores (são iguais em conteúdo) */

  printf("Vetor v :\n");
  vet_imprime(2,v);

  printf("Vetor w :\n");
  vet_imprime(2,w);

  /*testando o produto escalar entre os vetores*/

  double produto_escalar = vet_escalar(2,v,w);

  if(produto_escalar != 5){
    printf("Erro no produto escalar! Valor encontrado = %f\n",produto_escalar);
  }

  else{
    printf("Produto escalar correto = %f\n",produto_escalar);
  }

  /*Testando a norma 2 do vetor v*/
  double norma2 = vet_norma2(2,v);

  if(norma2 != sqrt(5)){
    printf("Erro na norma 2! Valor encontrado = %f\n",norma2);
  }

  else{
    printf("Norma 2 certa = %f\n",norma2);
  }

  /*testando se os vetores sao iguais*/
  int igual = vet_iguais(2,v,w,0.0);

  if(igual){
    printf("vetores iguais\n");
  }

  else{
    printf("Vetores diferentes\n");
  }

  /* Exemplo de construção de matriz dinâmica */
  double** A = mat_cria(3,2);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 3.0;
  A[1][1] = 4.0;
  A[2][0] = 5.0;
  A[2][1] = 6.0;

  /* Exemplo de construção de matriz estática no formato ponteiro para ponteiro */
  double linha1[] = {1.0,2.0};
  double linha2[] = {3.0,4.0};
  double linha3[] = {5.0,6.0};
  double* B[] = {linha1,linha2,linha3};

  /* Imprime matrizes (são iguais em conteúdo) */

  printf("Matriz A :\n");
  mat_imprime(3,2,A);

  printf("Matriz B :\n");
  mat_imprime(3,2,B);

  double** T = mat_cria(2,3);
  double** C = mat_cria(3,2);

  /*testando matriz transposta*/

  mat_transposta(3,2,A,T);

  printf("Matriz T :\n");

  mat_imprime(2,3,T);

  /*testando mat_multv*/

  double* W = vet_cria(3);
  mat_multv(3,2,A,v,W);

  printf("Vetor W :\n");

  vet_imprime(3,W);

  /*testando mat_multm*/

  mat_multm(3,2,2,A,B,C);

  printf("Matriz C :\n");

  mat_imprime(3,2,C);

  /* Apenas objetos dinâmicos podem ser liberados */
  vet_libera(v);
  vet_libera(W);
  mat_libera(3,A);
  mat_libera(2,T);
  mat_libera(3,C);

  return 0; 
} 