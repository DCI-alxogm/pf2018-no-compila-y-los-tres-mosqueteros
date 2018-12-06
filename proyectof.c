#include"proyectfmake.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

	FILE *inicial;
	FILE *posiciones;
	FILE *velocidades; 

	int n=408,i,j,t,c=0,cp=1,ch;
	float m,h,d,dx,dy,dz;
	float x[n],y[n],z[n],vx[n],vy[n],vz[n],fx[n],fy[n],fz[n];
	float xp[n],yp[n],zp[n],vxp[n],vyp[n],vzp[n],fxp[n],fyp[n],fzp[n];
        float fxt=0,fyt=0,fzt=0;
	char nombre[20];

	posiciones = fopen("posiciones.txt","r");

for (i=0;i<n;i++) 
	{
		fscanf(posiciones,"%f\n",&xp[i]);
		fscanf(posiciones,"%f\n",&yp[i]);
		fscanf(posiciones,"%f\n",&zp[i]);
	}
printf("1\n");
fclose(posiciones);

	velocidades = fopen("velocidades.txt","r");

for (i=0;i<n;i++)
	{
		fscanf(velocidades,"%f\n",&vxp[i]);
		fscanf(velocidades,"%f\n",&vyp[i]);
		fscanf(velocidades,"%f\n",&vzp[i]);
	}
printf("2\n");
fclose(velocidades);

	inicial = fopen("inicial.txt","r");
	fscanf(inicial,"%f\n",&m);
	fscanf(inicial,"%i\n",&t);
	fscanf(inicial,"%f\n",&h);

	fclose(inicial);

ch=t/h;
while (c<ch){
for (i=0;i<n;i++)
	{
	vx[i]=0;
	vy[i]=0;
	vz[i]=0;
	x[i]=0;
	y[i]=0;
	z[i]=0;
	fx[i]=0;
	fy[i]=0;
	fz[i]=0;
	}
printf("4");
for (j=0;j<n;j++)
	{
printf("4-%i\n",j);
	for (i=0;i<n;i++)
printf("4-%i,1-%i-%i\n",c,j,i);
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
		if(i!=j) 
			{
printf("4-%i,2-%i-%i\n",c,j,i);
			fxt=fxt+fx[i];
			fyt=fyt+fy[i];
			fzt=fzt+fz[i];
			}
		}
	
	x[i]=posicion(xp[i],h,vxp[i],fxt);
	vx[i]=velocidad(vxp[i],fxp[i],fxt,h);

	y[i]=posicion(yp[i],h,vyp[i],fyt);
	vy[i]=velocidad(vyp[i],fyp[i],fyt,h);

	z[i]=posicion(zp[i],h,vzp[i],fzt);
	vz[i]=velocidad(vzp[i],fzp[i],fzt,h);

	xp[i]=x[i];
	yp[i]=y[i];
	zp[i]=z[i];

	vxp[i]=vx[i];
	vyp[i]=vy[i];
	vzp[i]=vz[i];
	
	fxp[i]=fxt;
	fyp[i]=fyt;
	fzp[i]=fzt;	

	fxt=0;
	fyt=0;
	fzt=0;
	}
		sprintf(nombre, "%dposiciones.txt",cp);
			FILE *p;
		if (c%(ch/200) == 0)
	{
	p=fopen(nombre,"w");

	
	for(i=0;i<n;i++)
		{
		fprintf(p,"%f\t%f\t%f\t\t%f\t%f\t%f\n",x[i],y[i],z[i],xp[i],yp[i],zp[i]);
printf("4-%i,3-%i-%i\n",c,j,i);
		}
	fclose(p);
	}


	sprintf(nombre, "%dvelocidades.txt",cp);
			FILE *v;
		if (c%(ch/200) == 0)
	{
	v=fopen(nombre,"w");

	
	for(i=0;i<n;i++)
		{
		fprintf(v,"%f\t%f\t%f\t\t%f\t%f\t%f\n",vx[i],vy[i],vz[i],vxp[i],vyp[i],vzp[i]);

		}
	fclose(v);
	}

	sprintf(nombre, "%dfuerzas.txt",cp);
			FILE *f;
		if (c%(ch/200) == 0)
	{
	f=fopen(nombre,"w");
	cp++;
	
	for(i=0;i<n;i++)
		{
		fprintf(f,"%f\t%f\t%f\n",fxp[i],fyp[i],fzp[i]);

		}
	fclose(f);
	}
	c++;
}
return 0;
}
