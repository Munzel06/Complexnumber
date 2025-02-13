#include <stdio.h>
#include <math.h>
#include "complexnumbers.h"

const double PI = 3.14159265358979323846;

cnum add(cnum z, cnum w){
    cnum res;
    res.rel = z.rel + w.rel;
    res.im = z.im + w.im;
    return res;
}

void cprint(cnum z){
    if (z.im >= 0){
        printf("%lf + i%lf", z.rel, z.im);
    }
    else {
        printf("%lf - i%lf", z.rel, fabs(z.im));
    }
}

cnum sub(cnum z, cnum w){
    cnum res = {z.rel - w.rel, z.im - w.im};
    return  res;
}

cnum mul(cnum z, cnum w){
    cnum res = {z.rel * w.rel - z.im * w.im, z.rel * w.im + z.im * w.rel};
    return res;
}

cnum div(cnum z, cnum w){
    if (w.rel == 0 && w.im == 0) {
        printf("Division by Zero");
        cnum res = {0, 0};
        return res;
    }
    else {
        cnum res = {(z.rel * w.rel + z.im * w.im)/(pow(w.rel, 2) + pow(w.im, 2)), (z.im * w.rel - z.rel * w.im)/(pow(w.rel, 2) + pow(w.im, 2))};
        return res;
    }
}

double cbet(cnum z){
    double res;
    res = sqrt(pow(z.rel, 2) + pow(z.im, 2));
    
    return res;
} 

cnum ckonj(cnum z){
    cnum res = {z.rel, -z.im};
    return res;
}

ecnum ctoe(cnum z){
    ecnum res;
    res.r = cbet(z);

    if (z.rel == 0){
        if (z.im >= 0){
            res.phi = PI/2;
        }
        else {
            res.phi = - PI/2;
        }
    }
    else if (z.rel > 0) {
        res.phi = atan(z.im/z.rel);
    }
    else if (z.rel < 0 && z.im >= 0) {
       res.phi = atan(z.im/z.rel) + PI;
    }
    else if (z.rel < 0 && z.im < 0) {
        res.phi = atan(z.im/z.rel) - PI;
    }

    return res;
}

int float_equal(double a, double b, double tolerance) {
    double diff = a - b;
    return (diff < tolerance && -diff < tolerance);
}

void eprint(ecnum z){

    double tolerance = 1e-6; // Toleranzwert für Vergleiche

    if (float_equal(z.phi, PI / 4.0, tolerance)) {
        printf("%lf * e^(i\u03C0/4)\n", z.r);
    } else if (float_equal(z.phi, PI / 2.0, tolerance)) {
        printf("%lf * e^(i\u03C0/2)\n", z.r);
    } else if (float_equal(z.phi, 3.0 * PI / 4.0, tolerance)) {
        printf("%lf * e^(i3\u03C0/4)\n", z.r);
    } else if (float_equal(z.phi, PI, tolerance)) {
        printf("%lf * e^(i\u03C0)\n", z.r);
    } else if (float_equal(z.phi, 5.0 * PI / 4.0, tolerance)) {
        printf("%lf * e^(i5\u03C0/4)\n", z.r);
    } else if (float_equal(z.phi, 3.0 * PI / 2.0, tolerance)) {
        printf("%lf * e^(i3\u03C0/2)\n", z.r);
    } else if (float_equal(z.phi, 7.0 * PI / 4.0, tolerance)) {
        printf("%lf * e^(i7\u03C0/4)\n", z.r);
    } else {
        if (z.phi >= 0){
            printf("%lf * e^(i%lf)\n", z.r, z.phi);
        }
        else {
            printf("%lf * e^(-i%lf)\n", z.r, fabs(z.phi));
        }
    }
}

cnum etoc(ecnum z){
    cnum res;
    res.rel = z.r * cos(z.phi);
    res.im = z.r * sin(z.phi);
    return res;
}

ecnum eadd(ecnum z, ecnum w){
    cnum tz = etoc(z);
    cnum tw = etoc(w);
    cnum tres = add(tz, tw);
    ecnum res = ctoe(tres);
    return res;
}

ecnum esub(ecnum z, ecnum w){
    cnum tz = etoc(z);
    cnum tw = etoc(w);
    cnum tres = sub(tz, tw);
    ecnum res = ctoe(tres);
    return res;
}

ecnum emul(ecnum z, ecnum w){
    ecnum res;
    res.r = z.r * w.r;
    res.phi = z.phi + w.phi;
    return res;
}

ecnum ediv(ecnum z, ecnum w){
    ecnum res;
    res.r = z.r/w.r;
    res.phi = z.phi - w.phi;
    return res;
}

double ebet(ecnum z){
    return z.r;
}

ecnum ekonj(ecnum z){
    z.phi = -z.phi;
    return z;
}
