
all: compile

compile:
	 gcc minishell.c -o minishell -Wall -Werror --pedantic -I../../include -L../../lib -lmy

clean: 
	rm -f *.o

fclean:
	rm -f *.exe

re: fclean compile
