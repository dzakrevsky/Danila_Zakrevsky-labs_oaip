#include<iostream>

int main() {

    for (int i = 10; i <= pow(10,6); i++) {
        int k = i, z = 1, s = 0, n = i;
        while ((k /= 10) > 0) z++;
        for (int t = z; t; t--, n /= 10) {
            s += pow(n % 10, z);
        }
        if (i == s)
            std::cout << i << "\n";
    }
}