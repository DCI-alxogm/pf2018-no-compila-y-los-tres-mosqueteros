#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float velocidad(float vxp,float fx,float h)
{
	float vx;

	vx=vxp+((1/2)*(fx)*h);

return vx;
}
