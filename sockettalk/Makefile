all: compile

compile:
	 gcc server.c -o server -Wall -Werror --pedantic -I../../include -L../../lib -lmy -llist
	 gcc client.c -o client -Wall -Werror --pedantic -I../../include -L../../lib -lmy -llist

clean: 
	rm -f *.o

fclean:
	rm -f *.exe

re: fclean compile