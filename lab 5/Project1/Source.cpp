#include<iostream>

extern "C" __declspec(dllexport) int Sum(long double* x, int a, int b) {
    if (a == b) {
        if (sqrt(x[a] * x[a] + 2) < 10) return 1;
        return 0;
    }
    else if ((b - a) % 2 == 0) {
        return Sum(x, a, a + (b - a) / 3) + Sum(x, a + (b - a) / 3 + 1, b);
    }
    else {
        return Sum(x, a, a + (int)((b - a) / 3)) + Sum(x, a + (int)((b - b) / 3) + 1, b);
    }
}