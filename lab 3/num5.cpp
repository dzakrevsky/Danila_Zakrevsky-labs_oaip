#include <iostream>

long double fact(long double m) {
    if (m == 0 || m == 1) {
        return 1;
    }
    else {
        return m * fact(m - 1);
    }
}

int main() {
    double n, x, sum = 0, y = 0, e = 2.71828;;

    std::cout << "set n: "; std::cin >> n;
    std::cout << "set x: "; std::cin >> x;

    while (std::cin.fail() || std::cin.peek() != '\n' || n != (double)n || x != (double)x) {
        std::cout << "incorrect input";
        return 0;
    }

    if ((n >= 1 && n <= 15) && (x >= 0.1 && x <= 1)) {
        for (double i = 1; i < n; i++) {
            y += pow(x, 2 * i + 1) / fact(2 * i + 1);
        }
        y = 1 - y;
    }
    else {
        std::cout << "try again";
        return 0;
    }

    std::cout << "Taylor row " << y << '\n';
    std::cout << "without Taylor row " << (pow(e, x) - pow(e, -x)) / 2 << '\n';
}