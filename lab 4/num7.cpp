#include<iostream>
#include <stdlib.h>

int main() {
	int n, k = 0, m;
	std::cout << "set n & m\n"; std::cin >> n >> m;

    while (n)
    {   
        if (k == m) {
            std::cout << "num = " << n % 10 << std::endl;
        }
        if(n !=0)
        k++;
        n /= 10;
    }
    std::cout << k << std::endl;
}