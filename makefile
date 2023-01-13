all: main

main: menu.o main.o arvoresbinarias.o funcoesextras.o
	gcc -o main main.o menu.o arvoresbinarias.o funcoesextras.o

main.o: main.c 
	gcc -c main.c 

menu.o: menu.c
	gcc -c menu.c 

arvoresbinarias.o: arvoresbinarias.c
	gcc -c arvoresbinarias.c

funcoesextras.o: funcoesextras.c
	gcc -c funcoesextras.c

clean:
	rm -rf *.o