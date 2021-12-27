#include<iostream>
#include<Windows.h>
int main() {
    HINSTANCE load;
    load = LoadLibrary(L"Project1.dll");
    typedef int (*sum) (long double*, int, int);
    sum Sum;
    Sum = (sum)GetProcAddress(load, "Sum");

    int n;

    std::cout << "set n: "; std::cin >> n;

    while (std::cin.fail() || n <= 0 || n != (int)n) {
        std::cout << "incorrect input data";
        return 0;
    }

    long double* x = new long double[n];

    std::cout << "\nset elements of array: ";

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    std::cout << "sum =  " << Sum(x, 0, n - 1);
    FreeLibrary(load);
    return 0;
}