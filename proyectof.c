#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<proyectfmake.h>
int proyectfmain (){
FILE *inicial;
int n=5,i;
float rt,r1,r2,m,t,h;
inicial = fopen("inicial.txt","r");
fscanf(inicial,"%f %f %f\n",&rt,&r1,&r2);
fscanf(inicial,"%f",&m);
fscanf(inicial,"%f",&t);
fscanf(inicial,"%f",&h);
fclose(inicial);

posiciones();
velocidades();

for (i=0;i<n;i++) {
x[i+h]=x[i]+h*vx[i]+((1/2)*fx*(pow(h,2)));
vx[i+h]=vx[i]+((1/2)*(fx[i]+fx[i+h]))*h);
y[i+h]=y[i]+h*vy[i]+((1/2)*fy*(pow(h,2)));
vy[i+h]=vy[i]+((1/2)*(fy[i]+fy[i+h]))*h);
z[i+h]=z[i]+h*vz[i]+((1/2)*fz*(pow(h,2)));
vz[i+h]=vz[i]+((1/2)*(fz[i]+fz[i+h]))*h);
}



return 0;
}
