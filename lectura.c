#include<proyectfmake.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void lectura()
{

	FILE *posiciones;
	FILE *velocidades; 

	int n=770,i;
	float x[n],y[n],z[n];
	float vx[n],vy[n],vz[n];

	posiciones = fopen("posiciones.txt","r");

for (i=0;i<n;i++) 
	{
		fscanf(posiciones,"%f\n",&x[i]);
		fscanf(posiciones,"%f\n",&y[i]);
		fscanf(posiciones,"%f\n",&z[i]);
	}

fclose(posiciones);

	velocidades = fopen("velocidades.txt","r");

for (i=0;i<n;i++)
	{
		fscanf(velocidades,"%f\n",&vx[i]);
		fscanf(velocidades,"%f\n",&vy[i]);
		fscanf(velocidades,"%f\n",&vz[i]);
	}
fclose(velocidades);
}
