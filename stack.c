#include<stdlib.h>
#include "stack.h"

int push_num(int x,operand **num)
{
	operand *temp = (operand*) malloc(sizeof(operand));
	if(temp==NULL) return 1;
	temp->number = x;
	temp->pervious = *num;
	*num = temp;
	return 0;
}

int pop_num(operand **num)
{
	int temp_num = (*num)->number;
	operand *temp = *num;
	*num = (*num)->pervious;
	free(temp);
	return temp_num;
}

int operandempty(operand *num)
{
	if (num == NULL )
	return 1;
	else return 0;
}
void mkoperandempty(operand **num)
{
	while(!operandempty(*num))
	{
		pop_num(num);
	}
}
int push_operation(char c, operation **op)
{
	operation *temp = (operation*) malloc(sizeof(operation));
	if(temp == NULL) return 1;
	temp->operation = c;
	temp->pervious = *op;
	*op = temp;
	return 0;
}
int pop_operation(operation **op)
{
	operation *temp_op = *op;
	char temp = temp_op->operation;
	*op = (*op)->pervious;
	free(temp_op);
	return temp;
}
int operationempty(operation *op)
{
	if (op == NULL ) return 1;
        else return 0;
}
void mkoperationemtpy(operation **op)
{
	while(!operationempty(*op))
	{
		pop_operation(op);
	}
}
