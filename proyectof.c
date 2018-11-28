#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (){
FILE *inicial;
FILE *final; 
int n=5,i;
float rt,r1,r2,m,t,h;
float posicion[n],velocidad[n];
inicial = fopen("inicial.txt","r");
fscanf(inicial,"%f %f %f\n",&rt,&r1,&r2);
fscanf(inicial,"%f",&m);
fscanf(inicial,"%f",&t);
fscanf(inicial,"%f",&h);
for (i=0;i<n;i++) {
fscanf(inicial,"%f\n",&posicion[i]);
fscanf(inicial,"%f \n",&velocidad[i]);
}
fclose(inicial);
final = fopen("final.txt","w");
fprintf(final,"%f %f %f\n",rt,r1,r2);
for (i=0;i<n;i++) {
fprintf(final,"%f \n",posicion[i]);
fprintf(final,"%f\n",velocidad[i]);
}
fclose (final);



return 0;
}
