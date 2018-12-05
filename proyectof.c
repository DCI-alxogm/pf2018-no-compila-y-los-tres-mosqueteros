#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

	FILE *inicial;
	FILE *posiciones;
	FILE *velocidades; 

	int n=770,i,j,t,c=0,cp=1;
	float m,h,ch,d,dx,dy,dz;
	float x[n],y[n],z[n],vx[n],vy[n],vz[n],fx[n],fy[n],fz[n];
	float xp[n],yp[n],zp[n],vxp[n],vyp[n],vzp[n],fxp[n],fyp[n],fzp[n];
        float fxt,fyt,fzt;
	char nombre[20];

	posiciones = fopen("posiciones.txt","r");

for (i=0;i<n;i++) 
	{
		fscanf(posiciones,"%f\n",&xp[i]);
		fscanf(posiciones,"%f\n",&yp[i]);
		fscanf(posiciones,"%f\n",&zp[i]);
	}

fclose(posiciones);

	velocidades = fopen("velocidades.txt","r");

for (i=0;i<n;i++)
	{
		fscanf(velocidades,"%f\n",&vxp[i]);
		fscanf(velocidades,"%f\n",&vyp[i]);
		fscanf(velocidades,"%f\n",&vzp[i]);
	}
fclose(velocidades);

	inicial = fopen("inicial.txt","r");
	fscanf(inicial,"%f\n",&m);
	fscanf(inicial,"%i\n",&t);
	fscanf(inicial,"%f\n",&h);

	fclose(inicial);

for (i=0;i<n;i++)
	{
	fxp[i]=0;
	fyp[i]=0;
	fzp[i]=0;
	}
ch=t/h;
while (c<1000000){

for (j=0;j<n;j++)
	{
	for (i=0;i<n;i++)
		{
		if(i!=j) 
			{
			dx=distancia(xp[j],xp[i]);
			dy=distancia(yp[j],yp[i]);
			dz=distancia(zp[j],zp[i]);
			d=distanciat(dx,dy,dz);
			
			fx[i]=fuerza(d,dx,m);
			fy[i]=fuerza(d,dy,m);
			fz[i]=fuerza(d,dz,m);
			}
		}
	for (i=0;i<n;i++)
		{
		fxt=fxt+fx[i];
		fyt=fyt+fy[i];
		fzt=fzt+fz[i];
		}
	
	x[i]=posicion(xp[i],h,vxp[i],fxt);
	vx[i]=velocidad(vxp[i],fxt,h);

	y[i]=posicion(yp[i],h,vyp[i],fyt);
	vy[i]=velocidad(vyp[i],fyt,h);

	z[i]=posicion(zp[i],h,vzp[i],fzt);
	vz[i]=velocidad(vzp[i],fzt,h);

	xp[i]=x[i];
	yp[i]=y[i];
	zp[i]=z[i];

	vxp[i]=vx[i];
	vyp[i]=vy[i];
	vzp[i]=vz[i];
	
	fxp[i]=fxt;
	fyp[i]=fyt;
	fzp[i]=fzt;
	}
		sprintf(nombre, "%dposiciones.txt",cp);
			FILE *df;
		if (c%5000 == 0)
	{
	df=fopen(nombre,"w");
	cp++;
	}
	for(i=0;i<n;i++)
		{
		fprintf(df,"%f\t%f\t%f\n",xp[i],yp[i],zp[i]);
		}
	fclose(df);
	c++;
}
return 0;
}
