#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


long double posicion(long double xp,long double h,long double vxp,long double fxp)
{
	return xp+(h*vxp)+((1/2)*fxp*(pow(h,2)));
}
