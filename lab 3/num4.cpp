#include <iostream>

int main() {
	int n, i = 1, m;

	std::cout << "choose 1 or 2: "; std::cin >> n;
	std::cout << "Enter a number that ends interval: "; std::cin >> m;

	while (std::cin.fail() || std::cin.peek() != '\n' || m <= 0 || m != (int)m) {
		std::cout << "incorrect number ";
		return 0;
	}
	int sum;

	sum = 0;

	switch (n) {
	case 1:
		for (i = 0; i <= abs(m); i++) {
			if (i % 2 == 0)
				sum += i;
		}
		std::cout << "sum = " << sum;
		break;
	case 2:
		if (m % 2 == 0) {
			n = m / 2;
			sum = (m + 2) * n / 2;
			std::cout << "sum = " << sum;
		}
		else {
			n = (m - 1) / 2;
			sum = (1 + m) * n / 2;
			std::cout << "sum = " << sum;
		}
	}
}