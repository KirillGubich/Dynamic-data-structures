#include "revPlNotation.h";
#include "stack.h";

// Относительный приоритет
int getRelativePriority(char ch)
{
	switch (ch)
	{
	case '+':
		return 1;

	case '-':
		return 1;

	case '*':
		return 3;

	case '/':
		return 3;

	case '^':
		return 6;

	case '(':
		return 9;

	case ')':
		return 0;

	default:
		return 7;
	}
}

// Стековый приоритет
int getStackPriority(char ch)
{
	switch (ch)
	{
	case '+':
		return 2;

	case '-':
		return 2;

	case '*':
		return 4;

	case '/':
		return 4;

	case '^':
		return 5;

	case '(':
		return 0;

	default:
		return 8;
	}
}

// Преобразование выражения в обратную польскую запись
char* transformExpression(char* exp)
{
	STACK st = NULL;

	int len;
	len = strlen(exp);

	char *result;
	result = (char*)malloc((len + 1) * sizeof(char));

	int pos = 0;

	for (int i = 0; i < len; i++)
	{
		if (isEmpty(st) || getRelativePriority(exp[i]) > getStackPriority(viewTop(st))) // Если приоритет выше, чем на вершине стека
		{
			push(&st, exp[i]);
		}
		else if (exp[i] == ')') // Если закрывающая скобка
		{
			while (viewTop(st) != '(')
			{
				result[pos] = pop(&st);
				pos++;
			}
			pop(&st);
		}
		else // Если приоритет меньше или равен вершине стека
		{
			while (!isEmpty(st) && getRelativePriority(exp[i]) <= getStackPriority(viewTop(st)))
			{				
				result[pos] = pop(&st);
				pos++;		
			}

			push(&st, exp[i]);
		}
	}

	// Извлечение элементов, оставшихся в стеке
	while (!isEmpty(st))
	{
		if (viewTop(st) != '(' && viewTop(st) != ')')
		{
			result[pos] = pop(&st);
			pos++;
		}
		else
		{
			pop(&st);
		}
	}
	result[pos] = '\0';

	return result;
}

// Вычисление ранга
int getRang(char *exp)
{
	int rang = 0;
	for (int i = 0; i < strlen(exp); i++)
	{
		if (getRelativePriority(exp[i]) == 7)
		{
			rang++;
		}
		else
		{
			rang--;
		}
	}

	return rang;
}