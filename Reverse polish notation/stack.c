#include "stack.h"

// Adding an item to the stack
void push(STACK *stack, T data)
{
	struct element* pElement;

	pElement = (struct element*) malloc(sizeof (struct element));

	pElement->data = data;
	pElement->nextEl = *stack;

	*stack = pElement;
}

// Pop an item from stack. If stack is empty - NULL
T pop(STACK *stack)
{
	if (*stack == NULL)
	{
		return NULL;
	}

	struct element* pElement;
	pElement = *stack;

	*stack = pElement->nextEl;

	T res;
	res = pElement->data;

	free(pElement);
	return res;
}

// Is stack empty: Yes - 1/ No - 0
int isEmpty(STACK stack)
{
	return stack == NULL ? 1 : 0;
}

// view top element whithout pop
T viewTop(STACK stack)
{
	T data;
	data = pop(&stack);
	if (data != NULL)
	{
		push(&stack, data);
	}
	
	return data;
}

// Print stack
void printStack(STACK stack)
{
	struct element* pElement;
	pElement = stack;

	while (pElement != NULL)
	{
		printf("%d \n", pElement->data);
		pElement = pElement->nextEl;
	}
}