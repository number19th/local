#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
/**
* Функция быстрой сортировки
* Принимает параметры 
* Указатель на массив
* Минимальный индекс массива
* Максимальный индекс массива
*/
void qSort (int *A, int low, int high) 
	int i = low; /// Минимальный индекс
	int j = high; /// Максимальный индекс
	int x = A [(low + high) / 2]; /// Определения х - элемента посередине 
	do
	{
		while (A [i] <x)
			++i; /// Поиск элемента для переноса в старшую часть
		while (A [j]> x)
			--j; /// Поиск элемента для переноса в младшую часть
		if (i <= j)
		{ /// Обмен элементов местами:
			int temp = A [i];
			A [i] = A [j];
			A [j] = temp; /// Переход к следующим элементам
			i++;
			j--;
		}
	}
	while (i < j);
	if (low < j) qSort (A, low, j);
	if (i < high) qSort (A, i, high);
};
void main ()
{
	srand (time (NULL));
	static int *Mas; /// Указатель на массив типа int
	int high; /// Число элементов в массиве
	printf ("high =");
	scanf ("%d", & high); /// Получения числа элементов в массиве
	Mas = new int [high]; /// Выделение памяти
	for (int i = 0; i <high; i++)
	{ /// Генерирование массива
		Mas [i] = rand ()% 100;
		printf ("%3d", Mas [i]);
	}
	qSort (Mas, 0, high-1); /// Вызов функции сортировки
	printf ("\n");
	for (int i = 0; i <high; i++) /// Вывод на печать отсортированного массива	
		printf ("%3d", Mas [i]);
	getch ();
}