#include "taylor.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793

//nao esquecer -lm pra compilar!!

int main (void)
{
  // escreva seu teste aqui

  double x[] = {PI/12,PI/9,PI/7,PI/4,PI/3};
  double r;

  for(int i = 0;i < 5;i++){
    r = avalia_seno(10,x[i]);
    printf("Test: x: %.10f esperado = %.10f Resultado = %.10f\n",x[i],sin(x[i]),r);
  }


  return 0;
}
