#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

	FILE *inicial;
	FILE *posiciones;
	FILE *velocidades;
	FILE *p;

	int n=408,i,j,t,c=0,cp=1,ch;
	double m,h,d,dx,dy,dz;
	double x[n],y[n],z[n],vx[n],vy[n],vz[n],fx[n],fy[n],fz[n];
	double xp[n],yp[n],zp[n],vxp[n],vyp[n],vzp[n],fxp[n],fyp[n],fzp[n];
        double fxt=0,fyt=0,fzt=0;
	char nombre[20];

	posiciones = fopen("posiciones.txt","r");

for (i=0;i<n;i++) 
	{
		fscanf(posiciones,"%lf %lf %lf",&xp[i],&yp[i],&zp[i]);
	}
fclose(posiciones);

	velocidades = fopen("velocidades.txt","r");

for (i=0;i<n;i++)
	{
		fscanf(velocidades,"%lf %lf %lf",&vxp[i],&vyp[i],&vzp[i]);
	}
fclose(velocidades);

	inicial = fopen("inicial.txt","r");

	fscanf(inicial,"%lf %i %lf",&m,&t,&h);

	fclose(inicial);

ch=t/h;
while (c<ch)
	{
	for (j=0;j<n;j++)
		{
		for (i=0;i<n;i++)
			{
				dx=distancia(xp[j],xp[i]);
				dy=distancia(yp[j],yp[i]);
				dz=distancia(zp[j],zp[i]);
				d=distanciat(dx,dy,dz);
				printf("%i-%i-%i\n",c,j,i);

				fx[i]=fuerza(d,dx,m);
				fy[i]=fuerza(d,dy,m);
				fz[i]=fuerza(d,dz,m);
			}
		for (i=0;i<n;i++)
			{
				fxt=fxt+fx[i];
				fyt=fyt+fy[i];
				fzt=fzt+fz[i];
			}

		x[j]=posicion(xp[j],h,vxp[j],fxt);
		vx[j]=velocidad(vxp[j],fxp[j],fxt,h);

		y[j]=posicion(yp[j],h,vyp[j],fyt);
		vy[j]=velocidad(vyp[j],fyp[j],fyt,h);

		z[j]=posicion(zp[j],h,vzp[j],fzt);
		vz[j]=velocidad(vzp[j],fzp[j],fzt,h);

		xp[j]=x[j];
		yp[j]=y[j];
		zp[j]=z[j];
		
		vxp[j]=vx[j];
		vyp[j]=vy[j];
		vzp[j]=vz[j];

		fxp[j]=fxt;
		fyp[j]=fyt;
		fzp[j]=fzt;	

		fxt=0;
		fyt=0;
		fzt=0;
		}

		sprintf(nombre, "%dposiciones.txt",cp);

		if (c%(ch/200) == 0)
		{
		cp++;
		p=fopen(nombre,"w");

		for(i=0;i<n;i++)
			{
			fprintf(p,"%lf\t%lf\t%lf\n",xp[i],yp[i],zp[i]);
			}
		fclose(p);
		}
		c++;
	}
return 0;
}
