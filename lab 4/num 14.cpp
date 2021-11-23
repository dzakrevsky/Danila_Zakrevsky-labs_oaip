#include <iostream>

int main() {
    int n, m;

    std::cout << "set n & m ";

    std::cin >> n >> m;

    while (std::cin.fail() || n <= 0 || m <= 0 || n != (int)n || m != (int)m) {
        std::cout << "incorrect input data";
        return 0;
    }

    std::cout << '\n';

    char** a = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        a[i] = (char*)malloc(m * sizeof(char));
    }

    std::cout << "set mines\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = inputChar(i, j);
        }
    }

    std::cout << "\ngame zone\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }

        std::cout << '\n';
    }

    int k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            k = 0;
            if (a[i][j] == '.') {
                if (i - 1 > -1 && a[i - 1][j] == '*') k++;
                if (i + 1 < n && a[i + 1][j] == '*') k++;
                if (j - 1 > -1 && a[i][j - 1] == '*') k++;
                if (j + 1 < m && a[i][j + 1] == '*') k++;
                if (i - 1 > -1 && j - 1 > -1 && a[i - 1][j - 1] == '*') k++;
                if (i + 1 < n && j - 1 > -1 && a[i + 1][j - 1] == '*') k++;
                if (i - 1 > -1 && j + 1 < m && a[i - 1][j + 1] == '*') k++;
                if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '*') k++;
                a[i][j] = k + '0';
            }
        }
    }

    std::cout << "\nfull zone\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }

        std::cout << '\n';
    }

    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);

    return 0;
}

char inputChar(long long int i2, long long int j2) {
    char value;

    std::cin >> value;

    while (std::cin.fail() || (value != '.' && value != '*')) {
        std::cout << "incorrect input data";
        return 0;
    }

    return value;
}