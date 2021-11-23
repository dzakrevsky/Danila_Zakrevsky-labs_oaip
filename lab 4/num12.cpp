#include <iostream>
using namespace std;
int co;

int main() {
	int length, i;

	cout << "length: "; cin>> length;

	while (std::cin.fail() || length <= 0 || length != (int)length) {
		std::cout << "incorrect input data";
		return 0;
	}

	int* arr = new int[length];
	srand(time(NULL));
	for (i = 0; i < length; i++)
	{
		arr[i] = rand() % 9;
		cout << arr[i] << " ";
	}
	cout << endl;
	
	arrayUnique(arr, length);
	return 0;
}

int arrayUnique(int* arr, int length) {
	int i, j, n;
	for (i = 0; i < length - 1; i++)
		for (j = i + 1; j < length; j++)
			if (arr[i] == arr[j])
			{
				for (n = j; n < length; n++)
					arr[n] = arr[n + 1];
				length--;
			}
	int* UniqueArr = new int[length];
	for (i = 0; i < length; i++)
	{
		UniqueArr[i] = arr[i];
		cout << UniqueArr[i] << " ";
		co++;
	}
	cout << endl;
	delete[] arr;
	cout << "Length of array = " << co << endl;
	return *UniqueArr;
}