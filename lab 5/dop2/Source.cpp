#include<iostream>

int PowMod(int x, int y, int n) {
    if (!y) return 1;
    if (y & 1) return (x * PowMod((x * x) % n, y / 2, n)) % n;
    return PowMod((x * x) % n, y / 2, n);
}

int main() {
    int k, n, t, m, i, res, cs = 1;

    while (true) {
        m = 1; 
        std::cout << "set k, n, t: "; std::cin >> k >> n >> t; std::cout << std::endl;

        while (std::cin.fail() || n <= 0 || n != (int)n || k <= 0 || k != (int)k || t <= 0 || k != (int)k) {
            std::cout << "incorrect input data";
            return 0;
        }

        if (k == 0 || t == 0 || n == 0)
            break;
        for (i = 0; i < t; i++) m *= 10;
        res = PowMod(k % m, n, m);
        std::cout << "case #" << cs++ << ": " << res << std::endl;
    }
}