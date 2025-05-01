#include "derivadaintegral.h"

#include <stdio.h>
#include <math.h>

double derivada (double (*f) (double x), double x, double h){

    return (f(x + h) - f(x - h))/(2 * h);
}

double simpson(double (*f)(double), double a, double b, int n) {

    //tamanho do passo de cada sub intervalo
    double h = (b - a) / n;
    double soma = 0.0;
    double x0,x1,xm,fa,fc,fb;

    //integrando em cada passo n
    for (int i = 0; i < n; i++) {
        
        //inicio do intervalo
        x0 = a + i * h;
        fa = f(x0);
        
        //final do intervalo
        x1 = x0 + h;
        fb = f(x1);

        //meio do intervalo
        xm = (x0 + x1) / 2.0;
        fc = f(xm);

        soma += (h / 6.0) * (fa + 4.0 * fc + fb);
    }

    return soma;
}

double simpsonadaptativo (double (*f) (double), double a, double b, double tol){

    double c = (a + b) / 2.0;

    /* ∆ = S[a,b] − S[a,c] − S[c,b] */
    
    double sab = simpson(f,a,b,1);
    double sac = simpson(f,a,c,1);
    double scb = simpson(f,c,b,1);

    double delta = sab-(sac+scb);

    /* se ∆ < 15*tol ent retorna  S[a,c] + S[c,b] - ∆/15 */
    if(fabs(delta) < (15.0 * tol)){
        return sac + scb - (delta/15.0);
    }

    /*intervalo e tolerancia sao divididos pela metade e o metodo se repete*/
    else {
        return simpsonadaptativo(f,a,c,tol/2.0) + simpsonadaptativo(f,c,b,tol/2.0);
    }
}