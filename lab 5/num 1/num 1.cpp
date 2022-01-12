
#include<iostream>

int** matrix(int& n, int& k) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[k];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			std::cout << "set a[" << i << "][" << j << "]: ";
			std::cin >> arr[i][j];

			while (std::cin.fail() || arr[i][j] <= 0 || arr[i][j] != (int)arr[i][j]) {
				std::cout << "incorrect input data";
				return 0;
			}
		}
	return arr;
}

int newarr(int** arr, int n, int k) {
	int product = 1;
	int min = std::min(n, k);
	int* newarr = new int[min];
	std::cout << "[";
	for (int i = 0; i < min; i++) {
		if (arr[i][i] % 2 == 0) {
			newarr[i] = arr[i][i];
			product *= newarr[i];
			std::cout << newarr[i] << ", ";
		}
	}
	std::cout << "]" << "\n";
	std::cout << "product = " << product;
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
	newarr(pr, n, k);
}
