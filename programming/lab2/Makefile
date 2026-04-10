.PHONY: clean

all: main

main: include/adds.h src/adds.c src/main.c
	gcc -c src/adds.c
	ar rcs libadds.a adds.o
	rm *.o
	gcc src/main.c -o main -L. -ladds

clean:
	rm main; rm *.a; rm *.o; rm *.so

run: all
	./main
