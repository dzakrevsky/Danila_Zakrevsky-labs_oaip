#include<iostream>

int g(int n) {

	int k = (n + 1) / 2;
	if (n == 0) return 0;
	return k * k + g(n / 2);
}

int main() {
	int n;

	while (true) {
		std::cout << "set n: "; std::cin >> n;

		while (std::cin.fail() || n <= 0 || n != (int)n
			) {
			std::cout << "incorrect input data";
			return 0;
		}

		std::cout << "\n" << g(n) << std::endl;
	}
}