#include <stdio.h>
#include "stack.h"
#include "parse.h"
int isempty(char *s)
{
	if (s[0] == '\0')
	{
		puts("Error: Expected non-empty expression");
		return 1;
	}
	return 0;
}

int endofexpression( char *s, operand **num, operation **op, int *end )
{
	if(s[*end] == '\0')
	{
		while(!operationempty( *op ) )
		{
			int a = pop_num(num), b = pop_num(num);
			int y = operate( a, b , pop_operation(op) );
			push_num(y,num);
			(*end)++;
		}
		return 1;
	}
	return 0;
}
