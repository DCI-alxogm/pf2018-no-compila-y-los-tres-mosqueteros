<<<<<<< HEAD
proyectfmake: fuerzafunc.c posicionesfunc.c velocidadesfunc.c distancias.c proyectof.c 
	gcc   proyectof.c posicionesfunc.c velocidadesfunc.c fuerzafunc.c distancias.c -o proyectof.o -lm -I ./libreria
=======
proyectfmake: distancias.c fuerzafunc.c posicionesfunc.c velocidadesfunc.c proyectof.c 
	gcc   distancias.c proyectof.c posicionesfunc.c velocidadesfunc.c fuerzafunc.c -o proyectof.o -lm -I ./libreria
>>>>>>> 4236cd80d0f7d895eb8ce9679abb045f9343d611
clean: 
	rm proyectof.o
