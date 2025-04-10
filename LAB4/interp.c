#include "interp.h"
#include <math.h>
#include <stdio.h>

#define PI 3.141592653589793

static double F (int i, int j, double*xi,double (*f) (double)){

    if(i == j){
        return f(xi[i]);
    }

    return (F(i+1,j,xi,f)-F(i,j-1,xi,f))/(xi[j] - xi[i]);
}

void regular (int n, double a, double b, double* xi){

    xi[0] = a;

    double d = (b-a)/(n-1);

    for(int i = 1;i < n;i++){
       xi[i] = xi[i-1] + d;
    }
}


void chebyshev (int n, double a, double b, double* xi){

    double beta = 1;
    for(int i = 0;i < n;i++){
       xi[i] = ((b-a)/2) * cos((beta * PI)/(2*n)) + ((a+b)/2);
       beta += 2;
    }
}


void coeficientes (int n, double* xi, double (*f) (double), double* bi){

    for(int i = 0;i < n;i++){
        bi[i] = F(0,i,xi,f);
    }

}


double avalia (int n, double* xi, double* bi, double x){

    double P = bi[0];
    double mult = (x - xi[0]);
    for(int i = 1;i < n;i++){
        P += bi[i] * mult;
        mult *= (x-xi[i]);
    }

    return P;
}

