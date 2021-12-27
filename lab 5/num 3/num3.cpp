
/*3. Дан двумерный динамический массив целых чисел. Значения элементов данного
массива ввести с клавиатуры. Создать динамический массив из элементов,
расположенных в четных столбцах данного массива и имеющих нечетное значение.
Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.
Использовать функции.*/

#include<iostream>
#include "num3.h"

int** matrix(int& n, int& k) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[k];

	int* newarr = new int[n];

	int i1 = 0, sum = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			std::cout << "set a[" << i << "][" << j << "]: ";
			std::cin >> arr[i][j];

			while (std::cin.fail() || arr[i][j] <= 0 || arr[i][j] != (int)arr[i][j]) {
				std::cout << "incorrect input data";
				return 0;
			}

			if(arr[i][j] % 2 != 0)
				if (j % 2 == 0) {
					newarr[i1] = arr[i][j];
					sum += newarr[i1];
					i1++;
				}
		}

	std::cout << "sum/count = " << sum / i1;

	return 0;
}

int main() {
	int n, k;

	std::cout << "set num of rows: "; std::cin >> n;
	std::cout << "set num of colms: "; std::cin >> k;

	while (std::cin.fail() || n <= 0 || n != (int)n || k <= 0 || k != (int)k) {
		std::cout << "incorrect input data";
		return 0;
	}

	int** pr = matrix(n, k);
}