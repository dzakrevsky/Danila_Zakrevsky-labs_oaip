#include<iostream>

int main() {
    int n, tmp, sum = 1;
    std::cout << "Number of extension cords: "; std::cin >> n;

    while (std::cin.fail() || n <= 0 || n != (int)n) {
        std::cout << "incorrect input data";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << "set i-" << i << ": "; std::cin >> tmp;

        while (std::cin.fail() || tmp <= 0 || tmp != (int)tmp) {
            std::cout << "incorrect input data";
            return 0;
        }
        sum += tmp - 1;
    }
    std::cout << "sockets: " << sum;
}