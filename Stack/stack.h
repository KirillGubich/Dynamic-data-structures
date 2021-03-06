#include <stdio.h>

typedef struct element* STACK;
typedef int T;

struct element
{
	T data;
	struct element* nextEl;
};

void push(STACK* stack, T data);
T pop(STACK* stack);
void printStack(STACK stack);
