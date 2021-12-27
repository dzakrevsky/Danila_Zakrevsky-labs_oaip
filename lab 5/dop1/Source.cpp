#include<iostream>

int g(int p) {
	long t = p % 10;
	if (p == 0) return 0;
	return t * (1 + t) / 2 + p / 10 * 45 + g(p / 10);
}

int s(int p, int q) {
	return g(q) - g(p - 1);
}

int main() {
	int p, q ;
		
	while (true) {
		std::cout << "set p & q\n";
		std::cin >> p >> q;

		while (std::cin.fail() || p != (int)p ||q != (int)q) {
			std::cout << "incorrect input data";
			return 0;
		}

		if (p < 0 || q < 0)
			break;
		std::cout << s(p, q) << std::endl;
		std::cout << "g = " << g(p) << std::endl;
	}
}
