#include<proyectfmake.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long double fuerza(long double r,long double x,long double m)
{

if(r==0) 
	{
	return 0;
	}

else 
	{
	return (4300*x*m*m)/(r*r*r);
	}
}
