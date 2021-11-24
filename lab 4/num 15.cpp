#include <iostream>
#include <iomanip>

int main(){
    int n, max = 0, k = 1;
    std::cout << "set N: ";
    std::cin >> n;

    double** a = new double* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    for (int j = 0; j < n; ++j) {  
        for (int i = 0; i <= max; ++i) {
            if (i == max) {
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
        ++max;
    }

    std::cout << "mattrix:\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(4) << a[i][j] << " ";
        }
        std::cout << '\n';
    }
    return 0;
}
