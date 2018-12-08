/*FUNCIÓN PARA CALCULAR LAS VELOCIDADES DE CADA PARTICULA EN CADA COMPONENTE A CADA LAPSO DE TIEMPO.*/

#include"proyectfmake.h" //libreria creada funciones declaradas.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


  long double velocidad(long double vxp,long double fxp,long double fxt,long double h)      
  {
    return vxp+((1/2)*(fxp+fxt)*h);
  }

// vxp = velocidad anterior a la interacción.
// fxp = fuerza anterior a la interacción.
// fxt = fuerza tutal de la particula despues de cada interacción.
// h = el paso de cada interacción. 

