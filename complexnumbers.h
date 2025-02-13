#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

typedef struct {
    double rel;
    double im;
} cnum;

typedef struct {
    double r;
    double phi;
} ecnum;

cnum add(cnum z, cnum w);
cnum sub(cnum z, cnum w);
cnum mul(cnum z, cnum w);
cnum div(cnum z, cnum w);
double cbet(cnum z);
cnum ckonj(cnum z);

ecnum ctoe(cnum z);
cnum etoc(ecnum z);

ecnum eadd(ecnum z, ecnum w);
ecnum esub(ecnum z, ecnum w);
ecnum emul(ecnum z, ecnum w);
ecnum ediv(ecnum z, ecnum w);
double ebet(ecnum z);
ecnum ekonj(ecnum z);
void cprint(cnum z);
void eprint(ecnum z);

#endif
