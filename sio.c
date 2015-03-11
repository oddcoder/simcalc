#include <stdio.h>
#include <ctype.h>
#include "sio.h"

// get_s is a fuction that takes adress to char array and
// fill it character by character the maximum number of
// character can be determined by the macro MAX

int get_s(char *s)
{
        int i=0;
        do
	{
		while( ( s[i] = getchar() ) != '\n' ) // stop reading if new line is reached
    		{
			if(isspace(s[i]) ) continue;
	                if(i == MAX)
        	        {
                	        puts("Expression too long\ntype \"help\" to get help");
                        	neglect_input();
	                        return 1;
        	        }
			
                	i++;
		} 
        	s[i] ='\0'; // terminate the string
	} while(s[0] =='\0');
        return 0;
}
//neglect_input is a fuction that reads input from
//user until '\n' and store it in no where.
void neglect_input()
{
	while( getchar() != '\n' );
}
