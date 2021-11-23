#include <iostream>
#include <iomanip>

int main()
{
    setlocale(LC_ALL, "ru");

    int n, maxl = 0, k = 1;
    std::cout << "Введите размер таблицы N x N: ";
    std::cin >> n;

    double** a = new double* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    for (int j = 0; j < n; ++j) {  //Логика
        for (int i = 0; i <= maxl; ++i) {
            if (i == maxl) {
                for (int z = j; z > -1; --z) {
                    a[i][z] = k;
                    ++k;
                }
            }
            else {
                a[i][j] = k;
                ++k;
            }
        }
        ++maxl;
    }

    std::cout << "Заполненная таблица:\n";

    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < n; ++j) {
            std::cout << std::setw(4) << a[i][j] << " ";
        }
        std::cout << '\n';
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] a[i];
    }

    delete[] a;

    return 0;
}