proyectfmake: distancias.c fuerzafunc.c posicionesfunc.c velocidadesfunc.c proyectof.c 
	gcc   distancias.c proyectof.c posicionesfunc.c velocidadesfunc.c fuerzafunc.c -o proyectof.o -lm -I ./libreria

clean: 
	rm proyectof.o
