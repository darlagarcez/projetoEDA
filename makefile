all: main

main: menu.o main.o
	gcc -o main main.o menu.o 

main.o: main.c 
	gcc -c main.c 

menu.o: menu.c
	gcc -c menu.c 

clean:
	rm -rf *.o