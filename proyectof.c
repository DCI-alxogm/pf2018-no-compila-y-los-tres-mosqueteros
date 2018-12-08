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
	FILE *v;

	int n=408,i,j,t,c=0,cp=1,ch;
	long double m,h,d,dx,dy,dz;
	long double x[n],y[n],z[n],vx,vy,vz,fx[n],fy[n],fz[n];
	long double xp[n],yp[n],zp[n],vxp[n],vyp[n],vzp[n],fxp[n],fyp[n],fzp[n];
        long double fxt=0,fyt=0,fzt=0;
	char nombre[20];

	posiciones = fopen("posiciones.txt","r");

for (i=0;i<n;i++) 
	{
		fscanf(posiciones,"%Lf %Lf %Lf",&xp[i],&yp[i],&zp[i]);
	}
fclose(posiciones);

	velocidades = fopen("velocidades.txt","r");

for (i=0;i<n;i++)
	{
		fscanf(velocidades,"%Lf %Lf %Lf",&vxp[i],&vyp[i],&vzp[i]);
	}
fclose(velocidades);

	inicial = fopen("inicial.txt","r");

	fscanf(inicial,"%Lf %i %Lf",&m,&t,&h);

	fclose(inicial);

ch=t/h;
while (c<ch)
	{
	printf("%i\n",c);
	for (j=0;j<n;j++)
		{
		for (i=0;i<n;i++)
			{
				dx=distancia(xp[j],xp[i]);
				dy=distancia(yp[j],yp[i]);
				dz=distancia(zp[j],zp[i]);
				d=distanciat(dx,dy,dz);

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
		vx=(vxp[j]+(((fxp[j]+fxt)*h)/2));

		y[j]=posicion(yp[j],h,vyp[j],fyt);
		vy=(vyp[j]+(((fyp[j]+fyt)*h)/2));

		z[j]=posicion(zp[j],h,vzp[j],fzt);
		vz=(vzp[j]+(((fzp[j]+fzt)*h)/2));

		xp[j]=x[j];
		yp[j]=y[j];
		zp[j]=z[j];
		
		vxp[j]=vx;
		vyp[j]=vy;
		vzp[j]=vz;

		fxp[j]=fxt;
		fyp[j]=fyt;
		fzp[j]=fzt;	

		fxt=0;
		fyt=0;
		fzt=0;
		}

	sprintf(nombre,"%dvelocidades.txt",cp);

		if (c%(ch/200) == 0)
		{
		v=fopen(nombre,"w");

		for(i=0;i<n;i++)
			{
		fprintf(v,"%Lf\t%Lf\t%Lf\n",vxp[i],vyp[i],vzp[i]);
		}
		fclose(v);
		}

		sprintf(nombre, "%dposiciones.txt",cp);

		if (c%(ch/200) == 0)
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
