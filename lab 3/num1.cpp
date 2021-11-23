#include<iostream>
#include<iomanip>

int main() {
	int i = 1;
	long double n = 0, a = 0, b = 0;
	while (i <= 30) {
		if (i % 2 == 0) {
			a = i / 2;
			b = pow(i, 3);
		}
		else {
			a = i;
			b = pow(i, 2);
		}
		n += pow((a - b), 2);
		i++;
	}
	std::cout << std::fixed;
	std::cout << "N = " << std::setprecision(0) << n;
}