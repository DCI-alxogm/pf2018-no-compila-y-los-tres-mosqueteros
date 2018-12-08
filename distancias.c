/*FUNCIÓN PARA CALCULAR LAS DISTANCIAS DE CADA PARTÍCULA EN CADA COMPONENTE Y LA MAGNITUD DEL VECTOR A CADA LAPSO DE TIEMPO.*/

#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Distancia en un componete entre dos particulas.
long double distancia(long double x1,long double x2)
{

return x2-x1;
}

// x1 = posición de la partícula en un componete
// x2 = posición de la segunda partícula en el mismo componente que la primera.


// Distancia entre dos particulas.
long double distanciat(long double dx,long double dy,long double dz)
{

return sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));
}

// dx = distancia en el componente x entre las dos partículas.
// dz = distancia en el componente z entre las dos partículas.
// dy = distancia en el componente y entre las dos partículas.

