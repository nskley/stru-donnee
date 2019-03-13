exec: bin/main
	./bin/main

lib/tp5.o: src/tp5.c include/maLibMath.h
	gcc -c src/tp5.c -o lib/tp5.o

#lib/libtp5.so: lib/tp5.o #include/maLibMath.h
#	gcc -o lib/libtp5.so -shared lib/tp5.o

#	gcc -o libtoto.so -shared toto.o 

lib/libtp5.a: lib/tp5.o
	ar rcs lib/libtp5.a lib/tp5.o

bin/main: lib/libtp5.a include/maLibMath.h
	gcc -o bin/main src/main.c -I include -L  lib -ltp5 -lm

