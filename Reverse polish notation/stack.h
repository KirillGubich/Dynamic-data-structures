#include <stdio.h>

typedef struct element* STACK;
typedef char T;

struct element
{
	T data;
	struct element* nextEl;
};

void push(STACK* stack, T data);
T pop(STACK* stack);
int isEmpty(STACK stack);
T viewTop(STACK stack);
void printStack(STACK stack);
