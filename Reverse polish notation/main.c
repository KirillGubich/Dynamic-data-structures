#include <stdio.h>
#include "revPlNotation.h";

int main()
{
	char expression[50] = {'\0'};
	gets_s(expression, 50);

	char *res;
	int rang;

	res = transformExpression(expression);
	rang = getRang(res);

	printf("\nResult: %s \n", res);
	printf("Rang =  %d \n", rang);

	getchar();
	return 0;
}
