all: compile

compile:
	 gcc testmy.c -o testmy -Wall -Werror --pedantic -I../include -L../lib -lmy

clean: 
	rm -f *.o

fclean:
	rm -f *.exe

re: fclean compile