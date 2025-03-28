#include "raiz.h"
#include <math.h>

int bissecao (double a, double b, double (*f) (double x), double* r){

    double fa = f(a),fb = f(b);

    if((fa * fb) >= 0){
        return -1;
    }

    int i = 0;
    double emax = 0.5 * pow(10,-8);
    double e = (b-a)/2;
    double fc; 

    while(e > emax){
        *r = (a+b)/2;
        fc = f(*r);

        if(fabs(fc) < pow(10,-12)){
            break;
        }

        if((fa * fc) < 0){
            b = *r;
        }

        else{
            a = *r;
            fa = fc;
        }

        e = (b-a)/2;
        i++;
    }

    return i;

}