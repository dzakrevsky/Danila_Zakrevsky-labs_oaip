#include<iostream>


using namespace std;

int inputInt(int minValue, int maxValue) {
    int a = 0;
    double x;
    while (true)
    {
        std::cin >> x;
        if (!std::cin.fail() && x <maxValue && x > minValue)
            return (int)x;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter corect value" << std::endl;
    }
    return a;
}

int amountIntrestingNumbers(int number) {
    int amount = number / 10;

    if (number % 10 == 9)
        ++amount;
    return amount;
}

std::string convertToRomanian(int number) {
    std::string num;
    std::string* units = new std::string[]{ "","I","II","III","IV","V","VI","VII","VIII","IX" };
    for (int i = 0; i < number / 1000; i++)
    {
        num.push_back('M');
    }
    number %= 1000;
    if ((number % 500) / 100 + 5 == 9)
    {
        num += "CM";
        number %= 900;
    }
    else if (number / 500 > 0)
    {
        num.push_back('D');
        number %= 500;
    }
    for (int i = 0; i < number / 100; i++)
    {
        num.push_back('C');
    }
    number %= 100;


    if ((number % 50) / 10 + 5 == 9)
    {
        num += "XC";
        number %= 90;
    }
    else if (number / 50 > 0)
    {
        num.push_back('L');
        number %= 50;
    }
    if (number % 10 == 4 && number != 34)
    {
        num += "XL";
        number %= 40;
    }

    for (int i = 0; i < number / 10; i++)
    {
        num.push_back('X');
    }
    number %= 10;
    num += units[number];
    return num;
}

int main() {
    cout << convertToRomanian(inputInt(0, 4000));
}