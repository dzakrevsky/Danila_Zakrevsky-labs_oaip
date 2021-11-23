#include <iostream>
#include <iomanip>

double inputDouble(int i2, int j2) {
    double value;

    std::cin >> value;

    while (std::cin.fail()) {
        std::cout << "incorrect input";
        return 0;
    }

    return value;
}

int main()
{
    setlocale(LC_ALL, "ru");
    double n, m, sum, k;


    std::cout << "Введите n и m: \n";

    std::cin >> n >> m;

    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');

    while (std::cin.fail() || std::cin.peek() != '\n' || n <= 0 || m <= 0 || n != (int)n || m != (int)m) {
        std::cout << "Введены некоректные данные =( ";

        std::cin.clear();
        std::cin.ignore(3256, '\n');

        std::cin >> n >> m;
        while (std::cin.peek() == ' ')
            std::cin.ignore(1, ' ');
    }

    std::cout << '\n';

    double** a1 = new double* [n];
    double** a2 = new double* [n];
    for (long long int i = 0; i < n; ++i) {
        a1[i] = new double[m];
        a2[i] = new double[m];
    }

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a1[i][j] = inputDouble(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            k = 0;
            sum = 0;

            if (i - 1 > -1) {
                ++k;
                sum += a1[i - 1][j];
            }
            if (j - 1 > -1) {
                ++k;
                sum += a1[i][j - 1];
            }
            if (i + 1 < n) {
                ++k;
                sum += a1[i + 1][j];
            }
            if (j + 1 < m) {
                ++k;
                sum += a1[i][j + 1];
            }

            if (!k) {
                a2[i][j] = a2[i][j];
            }
            else {
                a2[i][j] = sum / k;
            }
        }
    }

    std::cout << "\nМассив, до проведения операции сглаживания:\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setw(4) << std::setprecision(2) << a1[i][j] << " ";
        }

        std::cout << '\n';
    }

    for (int i = 0; i < n; ++i) {
        delete[] a1[i];
    }
    delete[] a1;

    std::cout << "\nМассив, после проведённой операции сглаживания:\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setw(4) << std::setprecision(2) << a2[i][j] << " ";
        }

        std::cout << '\n';
    }

    for (int i = 0; i < n; ++i) {
        delete[] a2[i];
    }
    delete[] a2;

    return 0;
}