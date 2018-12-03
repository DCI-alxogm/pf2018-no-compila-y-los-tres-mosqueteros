#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<proyectfmake.h>

int proyectfmain()
{

	FILE *inicial;

	int n=770,i;
	float rt,r1,r2,m,t,h:
	float x[n],y[n],z[n],vx[n],vy[n],vz[n],fx[n],fy[n],fz[n];
	float xp[n],yp[n],zp[n],vxp[n],vyp[n],vzp[n],fxp[n],fyp[n],fzp[n];


	inicial = fopen("inicial.txt","r");

	fscanf(inicial,"%f %f %f\n",&rt,&r1,&r2);
	fscanf(inicial,"%f",&m);
	fscanf(inicial,"%f",&t);
	fscanf(inicial,"%f",&h);

	fclose(inicial);

posiciones();
velocidades();

for (i=0;i<n;i++)
	{
		x[i]=xp[i]+h*vxp[i]+((1/2)*fxp[i]*(pow(h,2)));
		vx[i]=vxp[i]+((1/2)*(fxp[i]+fx[i]))*h);
		y[i]=yp[i]+h*vyp[i]+((1/2)*fyp[i]*(pow(h,2)));
		vy[i]=vyp[i]+((1/2)*(fyp[i]+fy[i]))*h);
		z[i]=zp[i]+h*vzp[i]+((1/2)*fzp[i]*(pow(h,2)));
		vz[i]=vzp[i]+((1/2)*(fzp[i]+fz[i]))*h);
		while(
)

	}



return 0;
}
