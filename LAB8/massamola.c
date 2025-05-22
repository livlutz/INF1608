#include "massamola.h"
#include <math.h>
#include <stdlib.h>

double vet_norma2 (double x, double y)
{
  double s = pow(x,2) + pow(y,2);
  return sqrt(s);
}

void forca (double t, double x, double y, double* fx, double* fy){
    
    double k = 0.3;
    double r = 200.0;
    double m = 2.0;
    double g[2] = {0.0, 9.8};
    double w[2] = {10.0, 0.0};

    double fw = w[0]*exp(-t/20.0);
    double norma2p = vet_norma2(x,y);
    double fkx = (-k) *(norma2p - r) * (x/norma2p);
    double fky = (-k) *(norma2p - r) * (y/norma2p);
    double fg = m * g[1];
    
    *fx = fkx + fw;
    *fy = fky + fg;
}

double evolui (double t, double h, double x, double y, double xp, double yp, double* xn, double* yn){
    double sigma = 0.002;
    double m = 2.0;
    double fx,fy;
    forca(t,x,y,&fx,&fy);

    double pmais1x = x + (1-sigma)*(x-xp) + pow(h,2) * (fx/m);
    double pmais1y = y + (1-sigma)*(y-yp) + pow(h,2) * (fy/m);

    *xn = pmais1x;
    *yn = pmais1y;

    return (t+h);
}

void simula (double x0, double y0, double t, int n, double* x, double* y){

    double xp = x0,yp = y0;
    double h = t/n;
    t = 0.0;

    for(int i = 0;i < n;i++){
        t = evolui(t,h,xp,yp,x0,y0,&x[i],&y[i]);
        x0 = xp;
        y0 = yp;
        xp = x[i];
        yp = y[i];
    }
}