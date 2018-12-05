#include<proyectfmake.h>
#include<stdio.h>
#include<math.h>

float posiciones(xp,h,vxp,fxp)
{
float x;
		x=xp+(h*vxp)+((1/2)*fxp*(pow(h,2)));
return x;
}
