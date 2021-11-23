#include <iostream>
#include <cmath>

int main() {

	long double a, b, d, xm, y, e = 2.71828;
	std::cout << "set area " << '\n'; std::cin >> a;

	while (std::cin.fail() || std::cin.peek() != '\n' || a <= 0 || a != (int)a) {
		std::cout << "incorrect number ";
		return 0;
	}

	d = 2 / a;
	xm = 1;
	y = acos(pow(e, -1) - sin(1));
	for (double i = 1 + d; i <= 3; i += d) {
		b = abs(pow(e, -i) - sin(i));

		if (y > b) {
			xm = i;
			y = b;
		}
	}
	std::cout << "step = " << d << '\n';
	std::cout << "x = " << xm;
}