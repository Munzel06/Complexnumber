#include <stdio.h>
#include <math.h>
#include "complexnumbers.h"

int main(){
    
    cnum z = {1, 3};
    ecnum w = ctoe(z);

    eprint(w);

    eprint(ekonj(w));

    z = etoc(w);

    cprint(z);

    return 0;
}
