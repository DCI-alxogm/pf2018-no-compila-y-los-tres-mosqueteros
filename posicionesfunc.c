#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


double posicion(double xp,double h,double vxp,double fxp)
{
	return xp+(h*vxp)+((1/2)*fxp*(pow(h,2)));
}
