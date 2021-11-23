#include<iostream>

int main() {

	int i, n1, n2, s;

	for (i = 10; i <= 99; i++) {
		n1 = i / 10;  n2 = i % 10;  s = n1 + n2;
		if (s * s * s == i * i) 
			std::cout << i;
	}
}