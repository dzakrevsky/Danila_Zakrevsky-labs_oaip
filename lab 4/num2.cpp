#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void Opredel(int**, int);

int main() {
    int i, j, n, m;
    cout << "set rows (N): ";
    cin >> n;
    cout << "set colms (M): ";
    cin >> m;
    int** a = new int* [n];
    for (i = 0; i < n; i++)
        a[i] = new int[m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            cout << "Vvedite a[" << i << "][" << j << "]:";
            cin >> a[i][j];
        }
    Opredel(a, n);
    for (i = 0; i < n; i++)
        delete[]a[i];
    delete[]a;
    a = NULL;
    return 0;
}
void Opredel(int** a, int n) {
    int Iter = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)if (a[i][j] % 2 == 0)Iter++;
    for (int i = n; i > 0; i--)for (int j = n; j < 0; j++)if (a[i][j] % 2 == 0)Iter++;
    cout << "int array " << Iter << " 4ETHblX 4UCEJl.\n";
}