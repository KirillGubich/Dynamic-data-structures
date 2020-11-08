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