/*FUNCIÓN PARA CALCULAR LAS FUERZAS QUE ACTUAN SOBRE CADA PARTÍCULA EN CADA COMPONENTE A CADA LAPSO DE TIEMPO.*/

#include<proyectfmake.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long double fuerza(long double r,long double x,long double m)
{

if(r==0) 	// para que la fuerza no sea un valor nulo, si la distancia es igual a cero, igualamos la fuerza a cero. 
	{
	return 0;
	}

else 
	{
	return (4*3.141596235*3.141596235*x*m*m)/(r*r*r);
	}
}

// r = distancia entre las partículas.
// x = distancia entre las partículas en un un solo componente.
// m = masa de las partículas.

