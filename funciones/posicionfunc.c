#include<proyectfmake.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void posiciones() 
{

	FILE *posiciones; 

	int n=770,i;
	float x[n],y[n],z[n];

	posiciones = fopen("posiciones.txt","r");

for (i=0;i<n;i++) 
	{
		fscanf(posiciones,"%f\n",&x[i]);
		fscanf(posiciones,"%f\n",&y[i]);
		fscanf(posiciones,"%f\n",&z[i]);
	}

fclose(posiciones);
}
