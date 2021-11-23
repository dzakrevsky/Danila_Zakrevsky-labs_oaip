#include <iostream>

int main()
{
    long double d = 0, n = 0, sum = 0;

    do {
        n++;
        d = 1 / pow(2, n) + 1 / pow(3, n);
        sum += d;
    } while (d >= 0.0000001);
    std::cout << "Sum = " << sum;

    return 0;
}