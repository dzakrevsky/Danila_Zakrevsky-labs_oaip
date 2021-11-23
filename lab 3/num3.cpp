#include<iostream>

int main() {
	double b, h, x=0, pi = 3.141592, i = 0;
	int a = 0, m = 20;

	b = pi / 2;
	h = (b - a) / m;

	for (i; x <= b && x >= 0; i ++)
	{
		x = a + i * h;
		std::cout << "\nsin(x) - cos(x) = " << sin(x) - cos(x);
	}
}