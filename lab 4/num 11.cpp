#include <iostream>
#include <ctime>

int main() {
    int n, diagonal1 = 0, diagonal2 = 0, diagonal3 = 0, diagonal4 = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    std::cout << "set n: ";
    n = inputInt();

    int*** a = new int** [n];

    for (int i = 0; i < n; ++i) {
        a[i] = new int* [n];

        for (int j = 0; j < n; ++j) {
            a[i][j] = new int[n];
        }
    }

    for (int z = 0; z < n; ++z)
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; ++x)
                a[z][y][x] = rand() % 10;

    while (z < n) {
        diagonal1 += a[z][y][x];
        ++x;
        ++y;
        ++z;
    }

    x = 0;
    y = n - 1;
    z = 0;

    while (z < n) {
        diagonal2 += a[z][y][x];
        ++x;
        --y;
        ++z;
    }

    x = n - 1;
    y = 0;
    z = 0;

    while (z < n) {
        diagonal3 += a[z][y][x];
        --x;
        ++y;
        ++z;
    }

    x = n - 1;
    y = n - 1;
    z = 0;

    while (z < n) {
        diagonal4 += a[z][y][x];
        --x;
        --y;
        ++z;
    }

    std::cout << "\narray\n";

    for (int z = 0; z < n; ++z) {
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                std::cout << a[z][y][x] << "  ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    std::cout << "first diag" << diagonal1;
    std::cout << "\nsecond diag" << diagonal2;
    std::cout << "\nthird diag" << diagonal3;
    std::cout << "\nfourth diag" << diagonal4 << "\n\n";

    if (diagonal1 > diagonal2 && diagonal1 > diagonal3 && diagonal1 > diagonal4) {
        std::cout << "1 diag is longest = " << diagonal1 << '.';
    }
    else if (diagonal2 > diagonal1 && diagonal2 > diagonal3 && diagonal2 > diagonal4) {
        std::cout << "2 diag is longest = " << diagonal2 << '.';
    }
    else if (diagonal3 > diagonal2 && diagonal3 > diagonal1 && diagonal3 > diagonal4) {
        std::cout << "3 diag is longest = " << diagonal3 << '.';
    }
    else if (diagonal4 > diagonal2 && diagonal4 > diagonal3 && diagonal4 > diagonal1) {
        std::cout << "4 diag is longest = " << diagonal4 << '.';
    }
    else if (diagonal1 == diagonal2 && diagonal2 == diagonal3 && diagonal3 == diagonal4) {
        std::cout << "all diag are the same = " << diagonal1 << '.';
    }
    else if (diagonal1 == diagonal2 && diagonal2 == diagonal3) {
        std::cout << "1 and 2 diag are longest = " << diagonal1 << '.';
    }
    else if (diagonal2 == diagonal3 && diagonal3 == diagonal4) {
        std::cout << "2 and 3 diag are longest = " << diagonal2 << '.';
    }
    else if (diagonal1 == diagonal3 && diagonal3 == diagonal4) {
        std::cout << "1,2,3 diag are longest = " << diagonal1 << '.';
    }
    else if (diagonal1 == diagonal2 && diagonal2 == diagonal4) {
        std::cout << "1,2,4 diag are longest  " << diagonal1 << '.';
    }
    else if (diagonal1 == diagonal2) {
        std::cout << "1 diag = 2 diag = " << diagonal1 << '.';
    }
    else if (diagonal2 == diagonal3) {
        std::cout << "2 diag = 3 diag = " << diagonal2 << '.';
    }
    else if (diagonal3 == diagonal4) {
        std::cout << "3 diag = 4 diag " << diagonal3 << '.';
    }
    else if (diagonal1 == diagonal4) {
        std::cout << "1 diag = 4 diag = " << diagonal1 << '.';
    }
    else if (diagonal1 == diagonal3) {
        std::cout << "1 diag = 3 diag = " << diagonal1 << '.';
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) {
            delete[] a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] a[i];
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
        std::cout << "incorrect input data";
        return 0;
    }

    return value;
}