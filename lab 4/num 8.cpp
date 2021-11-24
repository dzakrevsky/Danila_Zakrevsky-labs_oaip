#include <iostream>
#include <ctime>

int main() {
    int n, j, temp, min = n + 1, min1 = -1, max1 = -1, max = -1, k = 0;

    std::cout << "set n "; std::cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        j = rand() % n;
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }

    std::cout << "\narray: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "  ";
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] > max) {
            max1 = i;
            max = a[i];
        }
        if (a[i] < min) {
            min1 = i;
            min = a[i];
        }
    }

    if (min1 < max1) {
        for (int i = min1 + 1; i < max1; ++i) {
            a[i] = 0;
            ++k;
        }
    }
    else if (min1 > max1) {
        for (int i = min1 - 1; i > max1; --i) {
            a[i] = 0;
            ++k;
        }
    }

    if (k + 1 > n / 2) {
        if (min1 < max1) {
            for (int i = min1; i < max1; ++i) {
                a[i] = a[i + k + 1];
                --n;
            }
        }
        else if (min1 > max1) {
            for (int i = max1 + 1; i < min1 + 1; ++i) {
                a[i] = a[i + k + 1];
                --n;
            }
        }
    }

    std::cout << "\nnew array ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "  ";
    }

    delete[] a;

    return 0;
}

long long int inputInt() {
    long double value;

    std::cin >> value;

    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');

    while (std::cin.fail() || value <= 0 || value != (long long int)value) {
        std::cout << "incorrect input";
        return 0;
    }

    return value;
}
