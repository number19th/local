#include <stdio.h>
#include <conio.h>
#include <locale.h>
struct List
{
	int value;
	void del (int index, List *p)
	{
		List *pF = p;
		for ( ; index - 1 > 1; pF = pF->pNext)
			index--;
		pF->pNext = pF->pNext->pNext;
	}
	List *pNext;
	void add(int index, int Value, List *p)
	{
		List *pF = p;
		for ( ; index - 1 > 1; pF = pF->pNext)
			index--;
		List *n_list = new List;
		n_list->value = Value;
		n_list->pNext = pF->pNext;
		pF->pNext = n_list;
	}
	int get_Value (int index, List *p)
	{
		List *pF = p;
		for ( ; index > 1; pF = pF->pNext)
			index--;
		return pF->value;
	}
};
void main ()
{
	setlocale(LC_ALL,".1251");
	List *list = new List;
	List *p = list;
	int add_index, del_index, get_index, Value, add_value, flag;
	for (int i = 0; i < 10; i++)
	{
		list->value = i+1; 
		list->pNext = new List;
		list = list->pNext;
	}
	list->pNext = 0;
	printf ("1 - добавить элемент\n2 - удалить элемент\n3 - получить значение элемента\n0 - выход\n");
	scanf ("%d", &flag);
	while (flag)
	{
		switch (flag)
		{
			case 1:
				printf ("¬ведите индекс элемента, на место которого вставить новый элемент : ");
				scanf ("%d", &add_index);
				printf ("¬ведите введите значение нового элемента : ");
				scanf ("%d", &add_value);
				list->add (add_index, add_value, p);
				list = p;
				while (list->pNext)
				{
					printf ("%d ", list->value);
					list = list->pNext;
				}
				break;
			case 2:
				printf ("\n¬ведите индекс элемента, который должен быть удалЄн : ");
				scanf ("%d", &del_index);
				list->del (del_index, p);
				list = p;
				while (list->pNext)
				{
					printf ("%d ", list->value);
					list = list->pNext;
				}
				break;
			case 3:
				printf ("\n¬ведите индекс элемента, значение которого нужно получить : ");
				scanf ("%d", &get_index);
				Value = list->get_Value(get_index, p);
				printf ("«начение элемента = %d", Value);
				break;
			default:
				break;
		}
		printf ("\n\n1 - добавить элемент\n2 - удалить элемент\n3 - получить значение элемента\n0 - выход\n");
		scanf ("%d", &flag);
	}
}