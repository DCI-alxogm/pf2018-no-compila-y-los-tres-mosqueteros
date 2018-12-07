#include<proyectfmake.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float fuerza(float r,float x,float m)
{ 
        float f;

	f=(4300*x*m*m)/(r*r*r);

return f;
}
