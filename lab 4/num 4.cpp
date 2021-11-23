#include <iostream>
#include <cstdlib>

int main() {

    const int n = 5;
    long int a[n][n];
    

    std::cout << "array :" << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100 - 10;
            std::cout << a[i][j] << "  ";
        }
    }

    int locMin = 0;
    std::cout << "\n";
    for (long int i = 0; i < n; i++) {
        for (long int j = 0; j < n; j++) {
            if ((i == 0 && j == 0) && (a[0][0] < a[0][1]) && (a[0][0] < a[1][0])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((i == 0 && j == n - 1) && (a[0][j] < a[0][j - 1]) && (a[0][j] < a[1][j])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((i == n - 1 && j == 0) && (a[i][0] < a[i][1]) && (a[i][0] < a[i - 1][0])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((i == n - 1 && j == n - 1) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i - 1][j])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((i == 0 && j != 0 && j != n - 1) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i + 1][j])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((i == n - 1 && j != 0 && j != n - 1) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i - 1][j])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((j == 0 && i != 0 && i != n - 1) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i + 1][j]) && (a[i][j] < a[i - 1][j])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((j == n - 1 && i != 0 && i != n - 1) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i + 1][j]) && (a[i][j] < a[i - 1][j])) {
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
            else if ((a[i][j] < a[i][j - 1]) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i + 1][j]) && (a[i][j] < a[i - 1][j])) {  
                std::cout << "row " << i << " colm " << j << " min = " << a[i][j] << '\n';
                locMin++;}
        }
    }
    std::cout << "numb of mins = " << locMin;
}