
all: compile

compile:
	 gcc myselect.c -o myselect -Wall -Werror --pedantic -I../../include -L../../lib -lncurses

clean: 
	rm -f *.o

fclean:
	rm -f *.exe

re: fclean compile