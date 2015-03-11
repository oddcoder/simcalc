#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "parse.h"
#include "handle.h"
// this function give the periority to each group of operators
int priority(char op)
{
	switch (op)
	{
		case '+':
		case '-': return 0;
		case '*':
		case '/':
		case '%': return 1;
		case '^': return 2;
		default : return -1;
	}
}

//this function tests which of two fuctions have high priority
int tpriority(char op1 , char op2 )
{
	int p1 = priority(op1), p2 = priority(op2);
	if(p1 == -1 || p2 == -1) return -1;
	else if(p1>p2) return 1;
	else if(p2>p1) return 2;
	else return 0;
}
// this function converts string number of defined length
//into int intiger
int stoi(char *number, int len)
{
	int i;
	char temp[len];
	for(i=0;i<len;i++) temp[i] = number[i];
	return atoi(temp);
}

//this function takes 2 integers and operation and perform it
int operate (int y, int x, int z)
{
	switch (z)
	{
	case '+': return x+y;
	case '-': return x-y;
	case '*': return x*y;
	case '/': return x/y;
	case '%': return x%y;
	case '^': return pow(x,y);
	default : return 0;
	};
}

int parse( char *inst, int *sol )
{
	//define the 2 stacks one for operators and one for operand
	operation *op = NULL;
	operand *num = NULL;
	int len = strlen(inst), start = 0, end = 0;
	// test for empy expression, or expression ends with operator,
	// or begin with operator, this is only done once during parsing 
	if(priority(inst[len-1])!=-1)
	{
		printf("Error: Unexpected operator \'%c\'\n",inst[len-1]);
		mkoperandempty(&num);
		mkoperationemtpy(&op);
		return 1;
	}
	if(priority(inst[0])>0)
	{
	   printf("Error: Unexpected operator \'%c\'\n",inst[0]);
		mkoperandempty(&num);
		mkoperationemtpy(&op);
		return 1;
		}
	if(isempty(inst)) return 1;
	while(end<=len)
	{
		//handles brackets
		if(inst[end] == ')')
		{
			puts("Error: Unbalanced or unexpected parenthesis or bracket");
			mkoperandempty(&num);
			mkoperationemtpy(&op);
			return 1;
		}
		if(inst[end] =='(')
		{
			start=end+1;
			int bracketcounter =1;
			while(bracketcounter != 0)
			{
				end++;
				if(inst[end] == '(') bracketcounter++;
				else if(inst[end] == ')' ) bracketcounter--;
				if(end ==len)
				{
					puts("Error: Unbalanced or unexpected parenthesis or bracket");
					mkoperandempty(&num);
		         mkoperationemtpy(&op);
					return 1;
				}
			}	
			inst[end] ='\0';
			int temp;
			if(parse(&inst[start],&temp)!=0)
			{
				mkoperandempty(&num);
            mkoperationemtpy(&op);
				return 1 ;
			}
			push_num( temp ,&num);
			start=end;
			end++;
			continue;
		}
	//handles end of expression
	if( endofexpression( inst, &num, &op, &end ) ==1 ) break;
	//handle digits
	else if( isdigit(inst[end]) )
	{
		start =end;
		while( isdigit( inst[end] ) ) end++;
		push_num( stoi(&inst[start] , end-start) , &num );
	}
	/***********************************************************************/
	else
	{
		//check if the operator is invalid
		if( priority(inst[end]) == -1 )
		{
			printf("Error: Undefined function or variable \'%c\'\n",inst[end] );
			mkoperandempty(&num);
         mkoperationemtpy(&op);
			return 1;
		}
		// unary positive and plus overriding 
		if(inst[end] == '+' &&(end ==0 || priority(inst[end-1]) !=-1 ) )
		{
			end++;
			start =end;
			if( priority( inst[end] )!= -1 )
         {
            printf("Error: Unexpected operator \'%c\'\n",inst[end]);
            mkoperandempty(&num);
            mkoperationemtpy(&op);
            return 1;
         }
			while( isdigit( inst[end] ) ) end++;
			push_num( stoi(&inst[start] , end-start) , &num );
			continue;
		}
		// unary negative and minus overriding
		else if(inst[end] == '-' &&(end ==0 || priority(inst[end-1]) !=-1 ) )
		{
			end++;
			start =	end;
			if( priority( inst[end] )!= -1 )
         {
            printf("Error: Unexpected operator \'%c\'\n",inst[end]);
            mkoperandempty(&num);
            mkoperationemtpy(&op);
            return 1;
         }
			while( isdigit( inst[end] ) ) end++;
			push_num( -1*stoi(&inst[start] , end-start) , &num );
			continue;
		}
		
		else if( operationempty( op ) ) push_operation ( inst[end] , &op );
		else
		{ 
			if( priority( inst[end-1] )!= -1 )
			{
				printf("Error: Unexpected operator \'%c\'\n",inst[end]);
				mkoperandempty(&num);
	         mkoperationemtpy(&op);
				return 1;
			}
			while(!operationempty( op ))
			{
				if( tpriority( op->operation, inst[end] )>1 ) break;
				int a = pop_num(&num), b = pop_num(&num);
				int y = operate( a, b , pop_operation(&op) );
				push_num(y,&num);			
			}
			push_operation(inst[end], &op);
		}
		end++;
	}
}
	*sol = pop_num(&num);
	return 0;
}
