#include "ode.h"
#include <math.h>

static double calculaK(double t, double h, double y, double (*f) (double t, double x)){
    
    double k1,k2,k3,k4;
    k1 = h *f(t,y);
    k2 = h *f((t+(h/2.0)),(y+(k1/2.0)));
    k3 = h *f((t+(h/2.0)),(y+(k2/2.0)));
    k4 = h *f((t+h),(y+k3));

    return y + (1.0/6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);

    
}


double RungeKutta (double t0, double t1, double h, double y0, double (*f) (double t, double x)){
    /*k1 = hf (t, y(t))
    k2 = hf (t + h/2, y(t) + k1 /2)
    k3 = hf (t + h/2, y(t) + k2 /2)
    k4 = hf (t + h, y(t) + k3 )
    1
    y(t + h) = y(t) + (k1 + 2k2 + 2k3 + k4 )*/

    int passos = ceil((t1-t0)/h);
    double yth;


    for(int i = 0;i < (passos + 1);i++){

        h = fmin(t1-t0,h);
        yth = calculaK(t0,h,y0,f);
        t0 += h;
        y0 = yth;

    }

    return yth;

}
double RungeKuttaAdapt (double t0, double t1, double y0, double (*f) (double t, double y), double tol){

    double h = pow(10.0,-7.0);

    double y1,y2,delta,fator;

    while(t0 < t1){

        h = fmin(t1-t0,h);

        y1 = calculaK(t0,h,y0,f);

        y2 = calculaK(t0,h/2.0,y0,f);

        y2 = calculaK(t0 + h/2,h/2.0,y2,f);

        delta = (y2-y1)/15.0;

        fator = pow((tol/fabs(delta)),(1.0/5.0));

        if(fator >= 1.0){
            t0 += h;
            y2 += delta;
            y0 = y2;
            h *= fmin(1.2,fator);
        }

        else{
            h *= 0.8 * fator;
        }

    }

    return y0;
}