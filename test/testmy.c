#include "my.h"

int main(){
	char* str = "Hello!";
	char testStr[] = "Hello!";
	char strCpyTstStr[] = "This is me.";
	char strCpyTstStr2[] = "This is me.";
	char strCpyTstStr3[] = "This is me.";
	char strCatTstStr[10] = "Hi";
	char strCatTst1[15] = "Hello";
	char strCatTst2[] = "World!";

	my_str(str);
	my_char('\n');
	my_int(421890);
	my_char('\n');
	my_int(-1002020);
	my_char('\n');
	my_int(-2147483648);
	my_char('\n');
	my_alpha();
	my_char('\n');
	my_digits();
	my_char('\n');
	my_int( my_strindex("Hello!", 'l') );
	my_char('\n');
	my_int( my_strindex("", 'a') );
	my_char('\n');
	my_int( my_strindex("Hello!", '\0') );
	my_char('\n');
	my_int( my_strindex(NULL, '1') );
	my_char('\n');
	my_str("my_Int: ");
	my_int( my_strlen("Hello!") );
	my_char('\n');
	my_str("my_strrindex: ");
	my_int( my_strrindex("Hello!", 'l') );
	my_char('\n');
	my_int( my_strrindex("", 'x') );
	my_char('\n');
	my_int( my_strrindex("\0", 'n') );
	my_char('\n');
	my_str("my_revstr: ");
	my_revstr(testStr);
	my_char('\n');
	my_num_base(19, "RTFM");
	my_char('\n');
	my_num_base(2, "A");
	my_char('\n');
	my_num_base(4, NULL);
	my_char('\n');
	my_num_base(3049, "ASDF");
	my_char('\n');
	my_num_base(21474367, "HI");
	my_char('\n');
	my_num_base(-2147483648, "0123456789ABCDEF");
	my_char('\n');
	my_num_base(2147483647, "0123456789ABCDEF");
	my_char('\n');
	my_char('\n');
	my_char('\n');


	my_str("Begin testing for Part 2: ");
	my_char('\n');


	my_str("------------------------ my_strfind tests ----------------------\n");
	my_str(my_strfind("Hello!", 'l'));
	my_char('\n');
	my_str(my_strfind("hello!", 'x'));
	my_char('\n');

	my_str("------------------------ my_strrfind tests ----------------------\n");
	my_str(my_strrfind("Hello!", 'l'));
	my_char('\n');

	my_str("------------------------ my_strcmp tests ------------------------\n");
	my_int(my_strcmp("Hello!", "A"));
	my_char('\n');
	my_int(my_strcmp("A", "Hello!"));
	my_char('\n');
	my_int(my_strcmp("Hello!", "Hello!"));
	my_char('\n');
	my_int(my_strcmp(NULL, NULL));
	my_char('\n');
	my_int(my_strcmp(NULL, "Hello!"));
	my_char('\n');
	my_int(my_strcmp("Hello!", "\0"));
	my_char('\n');
	my_int(my_strcmp("AAAAA", "HellA"));
	my_char('\n');
	my_char('\n');

	my_str("------------------------- my_strncmp tests ----------------------\n");
	my_int( my_strncmp("Hello!", "away", 3) );
	my_char('\n');
	my_int( my_strncmp("Hello!", "Hey!", 3));
	my_char('\n');
	my_char('\n');
	
	my_str("------------------------- my_strcpy tests -----------------------\n");
	my_str( my_strcpy(strCpyTstStr, "Hello!") );
	my_char('\n');
	
	my_str("------------------------- my_strncpy tests ----------------------\n");
	my_str( my_strncpy(strCpyTstStr2, "Hello!", 20));
	my_char('\n');
	my_str( my_strncpy(strCpyTstStr3, "Goodbye", 5));
	
	my_char('\n');
	my_str("------------------------- my_strcat tests ----------------------\n");
	my_str( my_strcat(strCatTstStr, "there."));
	my_char('\n');
	my_str( my_strcat(strCatTst1, "Bob"));
	my_char('\n');
	my_str( my_strcat(strCatTst2, " says hello."));

	my_char('\n');
	my_str("------------------------- my_strdup tests -----------------------\n");
	my_str( my_strdup("Goodbye"));
	my_char('\n');

	my_str("------------------------- my_strconcat tests -----------------------\n");
	my_str( my_strconcat("He", "llo!"));
	my_char('\n');
	my_str( my_strconcat(NULL, NULL));
	my_char('\n');
	my_str( my_strconcat("Hello", " "));
	my_char('\n');

	my_str("------------------------- my_strnconcat tests -----------------------\n");
	my_str( my_strnconcat("Hel", "lo there!", 5));
	my_char('\n');

	my_str("------------------------- my_atoi tests -----------------------------\n");	
	my_int(my_atoi("1bfd50"));
	my_char('\n');
	my_int(my_atoi("fbdsajk-303000fdsfdabhjkdal"));
	my_char('\n');
	my_int(my_atoi(""));
	my_char('\n');
	

	return 0;
}















