#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct Stack
{
	int n;
	Stack *pNext;
};

void add(Stack **pF)
{
	Stack *r;
	int a;
	r = new (Stack);
	printf ("������� ����� = ");
	scanf ("%d", &a);
	r->n = a;
	r->pNext = *pF;
	*pF = r; // ���������� �������� � ����
}

void del(Stack **pF)
{
	Stack *p;
	if (*pF == 0) // �������� ����� �� ������� ���������
		printf ("���� ����\n");
	else
	{
		p = *pF; // �������� �������� �� �����
		printf ("�� ����� ������ ������� = %d\n", p->n);
		*pF = p->pNext; 
		delete p; 
	}
}

void main()
{
	setlocale(LC_ALL,"Russian");
	Stack *pFirst = 0,
			*pEnd = 0;
	char c;
	while(1)
	{
		printf ("1 - ���������� ��������\n2 - ����� ��������\n3 - �����\n");
		c = _getch();
		switch(c)
		{
		case '1':
			add(&pFirst);
			break;
		case '2':
			del(&pFirst);
			break;
		case '3':
			return;
		default:
			printf ("�� ���������� ����\n");
		}
	}
}