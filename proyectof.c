/*PROGRAMA PRINCIPAL */

#include"proyectfmake.h"	//LIBRERI CREADA CONTIENE LA DECLARACIÓN DE LAS FUNCIONES.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	// Variables de control para abrir los archivos de texto.
	
	FILE *inicial;		
	FILE *posiciones;
	FILE *velocidades;
	FILE *p;
	FILE *v;
	
	// Declaración de las variables a usar.
	int n=408,i,j,t,c=0,cp=1,ch;
	long double m,h,d,dx,dy,dz;
	long double x[n],y[n],z[n],vx,vy,vz,fx[n],fy[n],fz[n];
	long double xp[n],yp[n],zp[n],vxp[n],vyp[n],vzp[n],fxp[n],fyp[n],fzp[n];
        long double fxt=0,fyt=0,fzt=0;
	// Vector de tipo caracter para modificar el nombre del archivo de texto a guardar.
	char nombre[20];

	// Lectura de las posiciónes iniciales.
	posiciones = fopen("posiciones.txt","r");
// n = el numero de partículas que interactuan.
for (i=0;i<n;i++) 
	{
		fscanf(posiciones,"%Lf %Lf %Lf",&xp[i],&yp[i],&zp[i]);
	}
fclose(posiciones);
// Lectura de las velocidades iniciales.
	velocidades = fopen("velocidades.txt","r");

for (i=0;i<n;i++)
	{
		fscanf(velocidades,"%Lf %Lf %Lf",&vxp[i],&vyp[i],&vzp[i]);
	}
fclose(velocidades);
// Lectura de valores iniciales.
	inicial = fopen("inicial.txt","r");

	fscanf(inicial,"%Lf %i %Lf",&m,&t,&h);

	fclose(inicial);
// Tiempo de interacciónes.
ch=t/h; 
	// Ciclo que repite el proceso hasta alcanzar el número de interacciones.
while (c<ch)
	{
		//contador que muestra en la pantalla cada 1000 el numero de interacciónes que ha realizado.
	if (c%1000==0)
	{
	printf("%i\n",c);
	}
		// for que contrala la partícula principal con la que esta interactuando.
	for (j=0;j<n;j++)
	{
			// for secundari que controla la partícula con la que esta interacctuando la partícula principal.
		for (i=0;i<n;i++)
			{
		// Se llama a la función distancia y se calculan las componentes de la distancia entre las dos partículas.
				dx=distancia(xp[j],xp[i]);
				dy=distancia(yp[j],yp[i]);
				dz=distancia(zp[j],zp[i]);
			// Se llama la funcion distanciat y se calcula la magnitud del vertor. 
				d=distanciat(dx,dy,dz);

			// Se llama la función fuerza y se calcula sus compontes en tre las dos particulas.
				fx[i]=fuerza(d,dx,m);
				fy[i]=fuerza(d,dy,m);
				fz[i]=fuerza(d,dz,m);
			}
		// for pra guardar la fuerzas que interactuan sobre una misma partícula.
		for (i=0;i<n;i++)
			{
				fxt=fxt+fx[i];
				fyt=fyt+fy[i];
				fzt=fzt+fz[i];
			}
		// Cálculo de la posición atraves de llamar la función posicion.
		// Calclo de la velocidad. guardada en la variable vx , vy , vz respectiva mente.
		x[j]=posicion(xp[j],h,vxp[j],fxt);
		vx=(vxp[j]+(((fxp[j]+fxt)*h)/2));

		y[j]=posicion(yp[j],h,vyp[j],fyt);
		vy=(vyp[j]+(((fyp[j]+fyt)*h)/2));

		z[j]=posicion(zp[j],h,vzp[j],fzt);
		vz=(vzp[j]+(((fzp[j]+fzt)*h)/2));

		// Igualación de las posiciones finales a las posicones anteriores.
		xp[j]=x[j];
		yp[j]=y[j];
		zp[j]=z[j];
		
		// Igualación de las velocidades nuevas a las anteriores.
		vxp[j]=vx;
		vyp[j]=vy;
		vzp[j]=vz;

		// Igualación de las fuerzas nuevas a las anteriores.
		fxp[j]=fxt;
		fyp[j]=fyt;
		fzp[j]=fzt;	

		fxt=0;		// Reinicio del valor de las fuerzas totales que actuan sobre una partícula.
		fyt=0;
		fzt=0;
	}
	// Variable que controla el nombre de las velocidades.
	sprintf(nombre,"%dvelocidades.txt",cp);

		if (c%(ch/500) == 0)
		{
			v=fopen(nombre,"w");

			for(i=0;i<n;i++)
			{
		
				fprintf(v,"%Lf\t%Lf\t%Lf\n",vxp[i],vyp[i],vzp[i]);
			}
		
			fclose(v);
		}
		// Variable que controla el nombre de las posiciones.
		sprintf(nombre, "%dposiciones.txt",cp);

		if (c%(ch/500) == 0)
		{
			cp++;
			p=fopen(nombre,"w");

			for(i=0;i<n;i++)
			{
				fprintf(p,"%Lf\t%Lf\t%Lf\n",xp[i],yp[i],zp[i]);
			}
			fclose(p);
		}
		c++;
	}
return 0;
}
