english : main.o file_manage.o word_matching.o
	gcc -o english main.o file_manage.o word_matching.o

main.o : main.c
	gcc -c main.c

file_manage.o : file_manage.c 
	gcc -c file_manage.c

word_matching.o : word_matching.c
	gcc -c word_matching.c
