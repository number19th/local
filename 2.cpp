#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct Queue
{
	int n;
	Queue *pNext;
};

void add(Queue **pF, Queue **pE)
{
	Queue *r;
	int a;
	r = new (Queue);
	printf ("������� ����� = ");
	scanf ("%d", &a);
	r->n = a;
	r->pNext = 0;
	if (*pF == 0) // ����������� ������ �� �������
	{
		*pF = r; 	// ������� ����������� �� ������ �����
		*pE = r;
	}
	else
	{
		(*pE)->pNext = r;	// ������� ����������� � ����� �������
		*pE = r; 
	}
}

void del(Queue **pF, Queue **pE)
{
	Queue *p;
	if (*pF == 0)
		printf ("������� �����\n");
	else
	{
		p = *pF;
		printf ("�� ������� ������ ������� = %d\n", p->n);
		*pF = p->pNext; 
		delete p; 
	}
}

void main()
{
	setlocale(LC_ALL,"Russian");
	Queue *pFirst = 0,
			*pEnd = 0;
	char c;
	while(1)
	{
		printf ("1 - ���������� ��������\n2 - ����� ��������\n3 - �����\n");
		c = _getch();
		switch(c)
		{
		case '1':
			add(&pFirst, &pEnd);
			break;
		case '2':
			del(&pFirst, &pEnd);
			break;
		case '3':
			return;
		default:
			printf ("�� ���������� ����\n");
		}
	}
}