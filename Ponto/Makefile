
main: main.o ponto.o
	gcc $(CFLAGS) -o main main.o ponto.o -lm
main.o: main.c ponto.h
	gcc $(CFLAGS) -c main.c -lm
fila.o: fila.c ponto.h -lm
	gcc $(CFLAGS) -c ponto.c
clean:
	rm -f *.o main 