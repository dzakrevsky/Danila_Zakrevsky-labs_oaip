#include <iostream>

int reversCode(int n)
{
    int number = 0, k = 1;
    while (n)
    {
        number += (9 - n % 10) * k;
        k *= 10;
        n /= 10;
    }
    return number;
}

int main()
{
    std::cout << "Number: ";
    int number;
    std::cin >> number;

    std::cout << reversCode(number) << std::endl;

    return 0;
}