#include<iostream>
#include <iomanip>

int main(){
    int i = 0, j = 0, n, m, temp;

    std::cout << "set n & m" << '\n'; std::cin >> n >> m;

    while (std::cin.fail() || n <= 0 || n != (int)n || m <= 0 || m != (int)m) {
        std::cout << "incorrect input data";
        return 0;
    }

    int** a = new int* [n];       
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    int** b = new int* [n];      
    for (int i = 0; i < n; i++)
        b[i] = new int[m];

    for (i = 0; i < n; i++)       
        for (j = 0; j < m; j++) {
            std::cout << "set a[" << i << "][" << j << "] ";
            std::cin >> a[i][j];

        }

    std::cout << "array a\n";

    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) {
            std::cout << std::setw(6) << a[i][j] << "  ";
        }
    }

    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) {
            b[i][j] = a[i][j];

            if ((i == 0 && j != 0) && (a[i][j] < a[i][j - 1])) {
                temp = a[i][j - 1];
                a[i][j] = temp;
                b[i][j] = a[i][j];
            }
            else if ((i != 0 && j == 0) && (a[i][j] < a[i - 1][j])) {
                temp = a[i - 1][j];
                a[i][j] = temp;
                b[i][j] = a[i][j];
            }
            else if (i != 0 && j != 0) {
                if (a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j]) {

                }
                else if (a[i - 1][j] >= a[i][j - 1]) {
                    temp = a[i - 1][j];
                    a[i][j] = temp;
                    b[i][j] = a[i][j];
                }
                else if (a[i][j - 1] > a[i - 1][j]) {
                    temp = a[i][j - 1];
                    a[i][j] = temp;
                    b[i][j] = a[i][j];
                }
            }
        }
    }
    std::cout << "\narray b\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            std::cout << std::setw(6) << b[i][j] << "  ";
        }
        std::cout << '\n';
    }
    return 0;
}
