#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float distancia(float x1,float x2)
{
float x;
	x=x1-x2;
return x;
}
float distanciat(float dx,float dy,float dz)
{
float r;
	r=sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));
return r;
}
