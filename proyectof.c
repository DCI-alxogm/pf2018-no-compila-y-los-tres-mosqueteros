#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<proyectfmake.h>

int proyectfmain()
{

	FILE *inicial;
	FILE *posiciones;
	FILE *velocidades; 

	int n=770,i,j;
	float rt,r1,r2,m,t,h,d,dx,dy,dz;
	float x[n],y[n],z[n],vx[n],vy[n],vz[n],fx[n],fy[n],fz[n];
	float xp[n],yp[n],zp[n],vxp[n],vyp[n],vzp[n],fxp[n],fyp[n],fzp[n];

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

	fscanf(inicial,"%f %f %f\n",&rt,&r1,&r2);
	fscanf(inicial,"%f",&m);
	fscanf(inicial,"%f",&t);
	fscanf(inicial,"%f",&h);

	fclose(inicial);

for (i=0;i<n;i++)
	{
	fxp[i]=0;
	fyp[i]=0;
	fzp[i]=0;
	}

for (j=0;j<n;j++)
	{
	for (i=0;i<n;i++)
		{
		while(i!=j) 
			{
			dx=distancia(xp[j],xp[i]);
			dy=distancia(yp[j],yp[i]);
			dz=distancia(zp[j],zp[i]);
			d=distanciat(dx,dy,dz);
			
			fx[i]=fuerza(d,dx);
			fy[i]=fuerza(d,dy);
			fz[i]=fuerza(d,dz);
			}
		}
	for (i=0;i<n;i++)
		{
		fxt=fxt+fx[i];
		fyt=fyt+fy[i];
		fzt=fzt+fz[i];
		}
	
	x[i]=posiciones(xp[i],h,vxp[i],fxt[i]);
	vx[i]=velocidades(vxp,fxt,h);

	y[i]=posiciones(yp[i],h,vyp[i],fyt[i]);
	vy[i]=velocidades(vyp,fyt,h);

	z[i]=posiciones(zp[i],h,vzp[i],fzt[i]);
	vz[i]=velocidades(vzp,fzt,h);

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

return 0;
}
