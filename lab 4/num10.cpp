#include <iostream>
#include <iomanip>

int main() {

    int n, i, j, m = 1, t, y, x, buff;

    std::cout << "set poryadok \n";
    n = inputInt();

    int** magicSquare;

    magicSquare = (int**)calloc(n, sizeof(*magicSquare));

    for (int i = 0; i < n; ++i) {
        magicSquare[i] = (int*)calloc(n, sizeof(*magicSquare[i]));
    }

    if (n == 2) {
        std::cout << "\nno sqrt";
    }
    else if (n == 1) {
        std::cout << "\nmagical sqr " << std::setw(3) << 1 << '\n';
    }
    else if (n % 2 == 1) {
        i = 0;
        j = static_cast<int>(n / 2); 

        magicSquare[i][j] = 1;

        for (int k = 2; k < n * n + 1; ++k) {
            if (i - 1 >= 0 && j - 1 >= 0 && magicSquare[i - 1][j - 1] == 0) {
                magicSquare[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && magicSquare[i - 1][j - 1] != 0) {
                magicSquare[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                magicSquare[n - 1][j - 1] = k;
                i = n - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                magicSquare[i - 1][n - 1] = k;
                --i;
                j = n - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && magicSquare[n - 1][n - 1] != 0) {
                magicSquare[i + 1][j] = k;
                ++i;
            }
        }
    }
    else if (n % 4 == 0) {
        int** secondarySquare;

        secondarySquare = (int**)malloc(n * sizeof(int*));

        for (long long int i = 0; i < n; ++i) {
            secondarySquare[i] = (int*)malloc(n * sizeof(int));
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                magicSquare[i][j] = m;
                ++m;
            }
        }

        m = n * n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                secondarySquare[i][j] = m;
                --m;
            }
        }

        m = (n / 4) * (n / 4);

        t = 1;
        i = 0;
        j = 0;

        while (t < m + 1) {
            ++t;

            y = i;
            x = j;

            while (y < i + 4) {
                magicSquare[y][x] = secondarySquare[y][x];
                ++y;
                ++x;
            }

            y = i + 3;
            x = j;

            while (x < i + 4) {
                magicSquare[y][x] = secondarySquare[y][x];
                --y;
                ++x;
            }

            if (j + 4 < n) {
                j += 4;
            }
            else if (j + 4 >= n) {
                j = 0;
                i += 4;
            }
        }

        for (long long int i = 0; i < n; ++i) {
            free(secondarySquare[i]);
        }
        free(secondarySquare);

    }
    else {
        int length4 = n / 2;

        int** _arr1;
        _arr1 = (int**)calloc(length4, sizeof(*_arr1));
        int** _arr2;
        _arr2 = (int**)calloc(length4, sizeof(*_arr2));
        int** _arr3;
        _arr3 = (int**)calloc(length4, sizeof(*_arr3));
        int** _arr4;
        _arr4 = (int**)calloc(length4, sizeof(*_arr4));

        for (int i = 0; i < length4; ++i) {
            _arr1[i] = (int*)calloc(length4, sizeof(*_arr1[i]));
        }
        for (int i = 0; i < length4; ++i) {
            _arr2[i] = (int*)calloc(length4, sizeof(*_arr2[i]));
        }
        for (int i = 0; i < length4; ++i) {
            _arr3[i] = (int*)calloc(length4, sizeof(*_arr3[i]));
        }
        for (int i = 0; i < length4; ++i) {
            _arr4[i] = (int*)calloc(length4, sizeof(*_arr4[i]));
        }

        int pred1 = n * n / 4;
        int pred2 = n * n / 2;
        int pred3 = n * n / 4 * 3;
        int pred4 = n * n;

        int k = 1;

        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr1[i][j] = 1;
        ++k;

        while (k < pred1 + 1) {
            if (i - 1 > -1 && j - 1 > -1 && _arr1[i - 1][j - 1] == 0) {
                _arr1[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 > -1 && j - 1 > -1 && _arr1[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr1[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr1[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr1[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr1[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr1[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr4[i][j] = k;

        ++k;

        while (k < pred2 + 1) {
            if (i - 1 > -1 && j - 1 >= 0 && _arr4[i - 1][j - 1] == 0) {
                _arr4[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && _arr4[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr4[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr4[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr4[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr4[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr4[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr2[i][j] = k;

        ++k;

        while (k < pred3 + 1) {
            if (i - 1 >= 0 && j - 1 >= 0 && _arr2[i - 1][j - 1] == 0) {
                _arr2[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && _arr2[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr2[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr2[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr2[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr2[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr2[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        i = 0;
        j = static_cast<int>(length4 / 2);
        _arr3[i][j] = k;

        ++k;

        while (k < pred4 + 1) {
            if (i - 1 >= 0 && j - 1 >= 0 && _arr3[i - 1][j - 1] == 0) {
                _arr3[i - 1][j - 1] = k;
                --i;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 >= 0 && _arr3[i - 1][j - 1] != 0 && i + 1 < length4) {
                _arr3[i + 1][j] = k;
                ++i;
            }
            else if (i - 1 < 0 && j - 1 >= 0) {
                _arr3[length4 - 1][j - 1] = k;
                i = length4 - 1;
                --j;
            }
            else if (i - 1 >= 0 && j - 1 < 0) {
                _arr3[i - 1][length4 - 1] = k;
                --i;
                j = length4 - 1;
            }
            else if (i - 1 < 0 && j - 1 < 0 && _arr3[length4 - 1][length4 - 1] != 0 && i + 1 < length4) {
                _arr3[i + 1][j] = k;
                ++i;
            }

            ++k;
        }

        buff = _arr1[0][0];
        _arr1[0][0] = _arr3[0][0];
        _arr3[0][0] = buff;

        buff = _arr1[length4 - 1][0];
        _arr1[length4 - 1][0] = _arr3[length4 - 1][0];
        _arr3[length4 - 1][0] = buff;

        y = 1; 

        while (y < length4 - 1) {
            buff = _arr1[y][1];
            _arr1[y][1] = _arr3[y][1];
            _arr3[y][1] = buff;

            ++y;
        }

        k = (n - 2) / 4 - 1; 

        if (k > 0) {
            while (k > 0) {
                for (int i = 0; i < length4; ++i) {
                    buff = _arr1[i][length4 - k];
                    _arr1[i][length4 - k] = _arr3[i][length4 - k];
                    _arr3[i][length4 - k] = buff;

                    buff = _arr2[i][k - 1];
                    _arr2[i][k - 1] = _arr4[i][k - 1];
                    _arr4[i][k - 1] = buff;
                }

                --k;
            }
        }

        for (int i = 0; i < length4; ++i) {
            for (int j = 0; j < length4; ++j) {
                magicSquare[i][j] = _arr1[i][j];
                magicSquare[i][j + length4] = _arr2[i][j];
                magicSquare[i + length4][j] = _arr3[i][j];
                magicSquare[i + length4][j + length4] = _arr4[i][j];
            }
        }

        for (long long int i = 0; i < length4; ++i) {
            free(_arr1[i]);
        }
        free(_arr1);

        for (long long int i = 0; i < length4; ++i) {
            free(_arr2[i]);
        }
        free(_arr2);

        for (long long int i = 0; i < length4; ++i) {
            free(_arr3[i]);
        }
        free(_arr3);

        for (long long int i = 0; i < length4; ++i) {
            free(_arr4[i]);
        }
        free(_arr4);
    }

    if (n > 2) {
        std::cout << "\nmagic sqr\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (n < 100) {
                    std::cout << std::setw(4) << magicSquare[i][j] << " ";
                }
                else {
                    std::cout << std::setw(10) << magicSquare[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    for (long long int i = 0; i < n; ++i) {
        free(magicSquare[i]);
    }
    free(magicSquare);
}

long long int inputInt() {
    long double value;

    std::cin >> value;

    while (std::cin.fail() || value <= 0 || value != (long long int)value) {
        std::cout << "incorrect input data";
        return 0;
    }

    return value;
}