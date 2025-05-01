#include "derivadaintegral.h"

#include <stdio.h>
#include <math.h>

double derivada (double (*f) (double x), double x, double h){

    return (f(x+h) - f(x-h))/(2*h);
}

double simpson(double (*f)(double), double a, double b, int n) {

    //h = b-a = x1 - x0 

    //tamanho do passo de cada sub intervalo
    double h = (b - a) / n;
    double soma = 0.0;

    //integrando em cada passo n
    for (int i = 0; i < n; i++) {
        
        //inicio do intervalo
        double x0 = a + i * h;
        
        //final do intervalo
        double x1 = x0 + h;

        //meio do intervalo
        double xm = (x0 + x1) / 2.0;

        soma += (h / 6.0) * (f(x0) + 4.0 * f(xm) + f(x1));
    }

    return soma;
}

double simpsonadaptativo (double (*f) (double), double a, double b, double tol){

    int tolerante = 0;
    double diferenca;

    double c = (a+b)/2.0,r;

    while (!tolerante){
        diferenca = fabs(simpson(f,a,b,1) - simpson(f,a,c,1) - simpson (f,c,b,1));

        if(diferenca < (15.0 * tol)){
            tolerante = 1;
            r = simpson(f,a,c,1) + simpson(f,c,b,1) - diferenca/15;
        }

        else{
            c /= 2.0;
            tol /= 2.0;
        }
    }

    return r;
}