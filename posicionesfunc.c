/*FUNCIÓN PARA CALCULAR LAS VELOCIDADES DE CADA PARTICULA EN CADA COMPONENTE A CADA LAPSO DE TIEMPO.*/

#include"proyectfmake.h"	////libreria creada funciones declaradas.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


long double posicion(long double xp,long double h,long double vxp,long double fxp)
{
	return xp+(h*vxp)+((1/2)*fxp*(pow(h,2)));
}

// xp = posición anterior a la interacción.
// h = el paso de cada interacción.
// vxp = velocidad anterior a la interacción.
// fxp = fuerza anterior a la interacción.

