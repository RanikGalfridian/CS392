all: compile

compile:
	gcc -c *.c -Wall -Werror --pedantic -I../../include
	ar -rc liblist.a *.o
	ranlib liblist.a
	mv liblist.a ../../lib

clean: 
	rm -f *.o

fclean:
	rm -f *.exe

re: fclean compile