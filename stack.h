//stack for storing numbers 
typedef struct operand
{
   int number;
   struct operand *pervious;
} operand;
//stack for storing single characters 
typedef struct operation
{
	char operation;
	struct operation *pervious; 
} operation;
//all push funtion return 1 if malloc failed
//and 0 if malloc succeeded
// all pop functions make no empty stack checks
//all isXempty return 1 if stack is empty and 
// 0 otherwise 
int push_num(int x,operand **num);
int pop_num(operand **num);
int operandempty(operand *num);
void mkoperandempty(operand **num);

int push_operation(char c, operation **op);
int pop_operation(operation **op);
int operationempty(operation *op);
void mkoperationemtpy(operation **op);
