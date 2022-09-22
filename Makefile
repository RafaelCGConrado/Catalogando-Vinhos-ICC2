all: funcoes.o main.o
	gcc funcoes.o main.o -o p_e_c -std=c99 -Wall

funcoes.o:
	gcc -c funcoes.c -o funcoes.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o p_e_c

run:
	./p_e_c


