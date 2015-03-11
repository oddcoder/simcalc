#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parse.h"
#include "sio.h"
#include "aux.h"
int main()
{
	banner();
	char *exp = (char*) malloc (sizeof(char) * MAX );

	//exp stands for expression

	while(1)
	{
		printf(">>");
		//getting input
		if(get_s( exp ) == 1 ) continue;

		//handling basic commands
		if(strcmp(exp, "q")==0)	return 0;
		else if(strcmp(exp, "banner")==0) banner();
		else if(strcmp(exp,"help")==0) help();
		else if(strcmp(exp, "credits")==0) credits();
		else if(strcmp(exp,"clear")==0) system("clear");
		else
		{
			int sol;
			if(parse(exp, &sol ) ==0) printf( "%i\n" , sol );
		}
	}
}

