#include <iostream>

int main() {

    int** a1;
    int** a2;
    int** a3;

    std::cout << "set 2 matrix length(M x N è N x K): ";

    int n, m, k;


    std::cin >> m >> n >> k;

    while (std::cin.peek() == ' ')
        std::cin.ignore(1, ' ');

    while (std::cin.fail() || k <= 0 || n <= 0 || m <= 0 || n != (int)n || m != (int)m || k != (int)k) {
        std::cout << "incorrect input";
        return 0;
    }

    std::cout << '\n';

    a1 = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; ++i) {
        a1[i] = (int*)malloc(n * sizeof(int));
    }

    a2 = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; ++i) {
        a2[i] = (int*)malloc(k * sizeof(int));
    }

    a3 = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; ++i) {
        a3[i] = (int*)malloc(k * sizeof(int));
    }

    std::cout << "set element array1 (" << m << " x " << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a1[i][j] = inputArrInt(i, j);
        }
    }

    std::cout << "\nset element array2 (" << n << " x " << k << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            a2[i][j] = inputArrInt(i, j);
        }
    }

    int sum;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a1[i][k] * a2[k][j];
                a3[i][j] = sum;
            }
        }
    }

    std::cout << "\nmatrix1*matrix2 = \n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << a3[i][j] << "  ";
        }
        std::cout << '\n';
    }

    for (int i = 0; i < m; i++) {
        free(a1[i]);
    }
    free(a1);

    for (int i = 0; i < n; i++) {
        free(a2[i]);
    }
    free(a2);

    for (int i = 0; i < m; i++) {
        free(a3[i]);
    }
    free(a3);

    return 0;
}

int inputArrInt(int i2, int j2) {
    double value;

    std::cin >> value;

    while (std::cin.fail() || value != (int)value) {
        std::cout << "incorrect input";
        return 0;
    }

    return value;
}