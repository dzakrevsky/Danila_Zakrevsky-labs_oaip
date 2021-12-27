#include<iostream>


int main() {
	int hex1, hex2, znak;

	std::cout << "Enter first hex number:" << std::endl;
	std::cin >> std::hex >> hex1;

	std::cout << "Enter a second hex number:" << std::endl;
	std::cin >> std::hex >> hex2;

	std::cout << "+ or -?(1 or 2)"; std::cin >> znak;
	if(znak == 1)
		std::cout << std::hex << hex1 + hex2 << std::endl;
	else
		std::cout << std::hex << hex1 - hex2 << std::endl;
}