#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long double velocidad(long double vxp,long double fxp,long double fxt,long double h)
{

return vxp+((1/2)*(fxp+fxt)*h);
}
