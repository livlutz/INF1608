#include "raiz.h"
#include <math.h>
#include <stdio.h>

#define PI 3.1415926535897932384626433832795

// exemplo para contagem de avaliacoes da funcao
// defina N=0 antes de chamar o metodo da bissecao
int N;
static double f1 (double x)
{
  N++;
  return x*x*x + 2*x*x - 2;
}

static double f2 (double x)
{
  N++;
  return x*x*x*x + x + 1;
}

static double f3 (double m){
  N++;
  double g,c,v,t;
  g = 9.8;
  c = 15;
  v = 35;
  t = 9;

  return ((g*m)/c) * (1 - exp((-c/m) * t)) - v;

}
int main (void)
{
  N = 0;
  // adicione aqui os seus testes...
  double a,b,r;
  a = -3.0;
  b = 3.0;
  r = 0.0;
  int i1 = bissecao(a,b,f1,&r);
  printf("Q2 de %.1f a %.1f : c: %.12f it : %d av : %d\n",a,b,r,i1,N);

  
  a = -3.0;
  b = 3.0;
  r = 0.0;
  N = 0;
  int i2 = bissecao(a,b,f2,&r);
  if(i2 == -1){
    printf("Q3 de %.1f a %.1f : nao convergiu : it %d av : %d\n",a,b,i2,N);
  }

  a = -5.0;
  b = 5.0;
  r = 0.0;
  N = 0;
  int i3 = bissecao(a,b,f1,&r);
  printf("Q2 de %.1f a %.1f : c : %.12f : it %d av : %d\n",a,b,r,i3,N);


  a = 0.0;
  b = 150.0;
  r = 0.0;
  N = 0;
  int i4 = bissecao(a,b,f3,&r);
  printf("Q4 de %.1f a %.1f : c : %.12f : it %d av : %d\n",a,b,r,i4,N);

  a = 0.0;
  b = 250.0;
  r = 0.0;
  N = 0;
  int i5 = bissecao(a,b,f3,&r);
  printf("Q4 de %.1f a %.1f : c : %.12f : it %d av : %d\n",a,b,r,i5,N);

  a = 0.0;
  b = 50.0;
  r = 0.0;
  N = 0;
  int i6 = bissecao(a,b,f3,&r);

  if(i6 == -1){
    printf("Q4 de %.1f a %.1f : nao convergiu : it %d av : %d\n",a,b,i6,N);
  }

  return 0;
}

