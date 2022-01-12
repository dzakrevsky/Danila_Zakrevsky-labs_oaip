#include<iostream>

int** matrix(int& n, int& k) {

	int count = 0, m = n * k, f = 0;

	double** arr = new double* [n]; //first array
	for (int i = 0; i < n; i++)
		arr[i] = new double[k];

	double* zeroarr = new double[m]; //second array(0)
	double* zeroarr2 = new double[m];

	m = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			std::cout << "set a[" << i << "][" << j << "]: ";
			std::cin >> arr[i][j];

			while (std::cin.fail() || arr[i][j] != (int)arr[i][j]) {
				std::cout << "incorrect input data";
				return 0;
			}

			if (arr[i][j] == 0) {
				count++;
				zeroarr[m] = i;
				zeroarr2[m] = j;
				m++;
			}

		}

	std::cout << "there are " << count << " '0'\n";
	if(count > 0)
		std::cout << "\nthey index: \n";
	for (m = 0; m < count; m++) {
		std::cout << "[i][j] = [" << zeroarr[m] << "]" << "[" << zeroarr2[m] << "]\n";
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j = k-1; j >= 0; j--) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
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
