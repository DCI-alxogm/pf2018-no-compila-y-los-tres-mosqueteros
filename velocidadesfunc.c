#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float velocidad(float vxp,float fxp,float fx,float h)
{
	float vx;

	vx=vxp+((1/2)*(fxp+fx)*h);

return vx;
}
