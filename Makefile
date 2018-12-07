proyectfmake: fuerzafunc.c posicionesfunc.c velocidadesfunc.c distancias.c proyectof.c 
	gcc   proyectof.c posicionesfunc.c velocidadesfunc.c fuerzafunc.c distancias.c -o proyectof.o -lm -I ./libreria
clean: 
	rm proyectof.o
