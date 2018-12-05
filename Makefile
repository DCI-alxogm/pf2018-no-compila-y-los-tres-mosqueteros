proyectfmake: fuerzafunc.c posicionfunc.c velocidadesfunc.c proyectfmain.c 
	gcc   proyectfmain.c posicionfunc.c velocidadesfunc.c fuerzafunc.c -o proyectfomain.o -lm -I ./libreria
clean: 
	rm proyectf.o
