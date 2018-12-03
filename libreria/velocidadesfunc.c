#include<proyectfmake.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void velocidades(); {
int n=1155,i;
float vx[n],vy[n],vz[n];
velocidades = fopen("velocidades.txt","r");
for (i=0;i<n;i++) {
fscanf(velocidades,"%f\n",&vx[i]);
fscanf(velocidades,"%f\n",&vy[i]);
fscanf(velocidades,"%f\n",&vz[i]);
}
fclose(velocidades);
}
