#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (){
FILE *data;
int n=5,i;
float rt,r1,r2;
float posicion[n],velocidad[n];
data = fopen("datos.txt","r");
fscanf(data,"%f %f %f\n",&rt,&r1,&r2);
for (i=0;i<n;i++) {
fscanf(data,"%f\n",&posicion[i]);
fscanf(data,"%f \n",&velocidad[i]);
}
fclose(data);
printf("%f %f %f\n",rt,r1,r2);
for (i=0;i<n;i++) {
printf("%f \n",posicion[i]);
printf("%f\n",velocidad[i]);
}



return 0;
}
