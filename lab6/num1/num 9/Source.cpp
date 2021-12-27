#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

int main() {
    long double buff, sum = 0;
    int fraction, ex;
    bool minus, exMinus;

    std::string input;

    std::cout << "set string: ";
    std::getline(std::cin, input);

    int count = 0;

    while (count < input.length()) {
        minus = false;

        if (isdigit(input[count])) {
            if (input[count - 1] == '-') {
                buff = input[count] - '0';

                minus = true;
            }
            else {
                buff = input[count] - '0';
            }

            ++count;

            while (isdigit(input[count])) {
                buff = buff * 10 + (input[count] - '0');

                ++count;
            }

            fraction = 1;

            if (input[count] == '.' && isdigit(input[count + 1])) {
                ++count;

                while (isdigit(input[count])) {
                    fraction *= 10;

                    buff = buff + (long double)(input[count] - '0') / fraction;

                    ++count;
                }
            }

            if ((input[count] == 'e' || input[count] == 'E') && (isdigit(input[count + 1]) || (input[count + 1] == '+' && isdigit(input[count + 2])) || (input[count + 1] == '-' && isdigit(input[count + 2])))) {
                exMinus = false;

                ++count;

                if (input[count] == '-') {
                    exMinus = true;
                    ++count;
                }
                else if (input[count] == '+') {
                    ++count;
                }

                ex = input[count] - '0';

                ++count;

                while (isdigit(input[count])) {
                    ex = ex * 10 + (input[count] - '0');

                    ++count;
                }

                if (exMinus) {
                    ex *= -1;
                }

                buff *= pow(10, ex);
            }

            if (minus) {
                buff *= -1;
            }

            std::cout << '\n' << buff;

            sum += buff;
        }

        ++count;
    }

    std::cout << "\nSum: " << sum;

    return 0;
}