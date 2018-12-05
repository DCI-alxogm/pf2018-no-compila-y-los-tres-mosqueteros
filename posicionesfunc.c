#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


float posicion(float xp,float h,float vxp,float fxp)
{
float x;
		x=xp+(h*vxp)+((1/2)*fxp*(pow(h,2)));
return x;
}
