#include "derivadaintegral.h"

#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

double derivada (double (*f) (double x), double x, double h){

    return (f(x+h) - f(x-h))/(2*h);
}

double simpson (double (*f) (double), double a, double b, int n){

    double h = (b-a)/n;

    double i = (h/6.0) * (f(a) + 4.0*f(a+(h/2.0)) + f(a+h));

    return i;
}

double simpsonadaptativo (double (*f) (double), double a, double b, double tol){

    int tolerante = 0;
    double diferenca;

    double c = (a+b)/2.0,r;

    while (!tolerante){
        diferenca = fabs(simpson(f,a,b,1) - simpson(f,a,c,1) - simpson (f,c,b,1));

        if(diferenca < (15.0 * tol)){
            tolerante = 1;
            r = simpson(f,a,c,1) + simpson(f,c,b,1) - tol/15;
        }

        else{
            c /= 2.0;
            tol /= 2.0;
        }
    }

    return r;
}