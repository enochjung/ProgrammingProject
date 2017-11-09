english : main.o file_manage.o
	gcc -o english main.o

main.o : main.c file_manage.h
	gcc -c main.c

file_manage.o : file_manage.c 
	gcc -c file_manage.c
