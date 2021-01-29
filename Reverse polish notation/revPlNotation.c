#include "revPlNotation.h";
#include "stack.h";

// ������������� ���������
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

// �������� ���������
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

// �������������� ��������� � �������� �������� ������
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
		if (isEmpty(st) || getRelativePriority(exp[i]) > getStackPriority(viewTop(st))) // ���� ��������� ����, ��� �� ������� �����
		{
			push(&st, exp[i]);
		}
		else if (exp[i] == ')') // ���� ����������� ������
		{
			while (viewTop(st) != '(')
			{
				result[pos] = pop(&st);
				pos++;
			}
			pop(&st);
		}
		else // ���� ��������� ������ ��� ����� ������� �����
		{
			while (!isEmpty(st) && getRelativePriority(exp[i]) <= getStackPriority(viewTop(st)))
			{				
				result[pos] = pop(&st);
				pos++;		
			}

			push(&st, exp[i]);
		}
	}

	// ���������� ���������, ���������� � �����
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

// ���������� �����
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