#include<iostream>

int main() {
    int k, n, kn;

    std::cout << "set k: "; std::cin >> k;
    while (std::cin.fail() || k <= 0 || k != (int)k) {
        std::cout << "incorrect input data";
        return 0;
    }

    long int* arr1 = new long int[k];

    long int i = 0, num, ss = 0;

    for (i; i < k; i++) {
        std::cout << "set num: ";  std::cin >> num;
        while (std::cin.fail() || num <= 0 || num != (int)num) {
            std::cout << "incorrect input data";
            return 0;
        }
        arr1[i] = num;
    }

    std::cout << "set n: "; std::cin >> n;
    while (std::cin.fail() || n <= 0 || n != (int)n) {
        std::cout << "incorrect input data";
        return 0;
    }

    kn = k - n;
    ss = k - kn;

    long int* arr2 = new long int[kn];

    i = 0;

    for (i; i < kn; i++) {
        for (kn; kn > 0; kn--) {
            arr2[i] = arr1[ss];
            ss++;
            std::cout << arr2[i] << " ";
        }
    }
    return 0;
}