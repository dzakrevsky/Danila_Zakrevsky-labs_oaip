#include <iostream>
#include <string>
using namespace std; 

    void convert_to_3(short a, string& Digit) {
        if (a / 3) convert_to_3(a / 3, Digit);
        string temp = to_string(a % 3);
        Digit.push_back(temp[0]);
    }

    long double input(double min, double max) {
        long double x;
        while (true) {
            std::cin >> x;
            if (!std::cin.fail() && std::cin.peek() == '\n' && x <= max && x >= min)
                return x;
            std::cin.clear();
            std::cin.ignore(99999, '\n');
            std::cout << "Ошибка ввода!Введдите другое значение: " << std::endl;
        }
    }

    void convert_to_10(short a) {
        short Value = 0;
        for (short i = 0; a != 0; ++i) {
            Value += (a % 10) * pow(3, i); a /= 10;
        }
        cout << "\nНомер отравленной бочки: " << Value;
    }

    int main() {
        setlocale(LC_ALL, "ru");
        std::cout << "Введите позицию отравленной бочки: " ;

        short barrel_of_poison = input(1, 240), i = 4; string POISON, WINE = "00000";

        convert_to_3(barrel_of_poison, POISON);

        if (POISON.length() < WINE.length()) {
            reverse(POISON.begin(), POISON.end());
            POISON.resize(5, '0');
            reverse(POISON.begin(), POISON.end());
        }
        std::cout << "\nВсе 240 бочек поделим на 6 групп по 40 бочек в каждой.\nКаждый из рабов выпьет из своих 40 бочек.\nЗатем каждый раб попробует еще 8 бочек из каждой чужой группы, включая общую 6 - ю.\nИтого каждый дегустирует 40 своих бочек и 32 чужих и 8 из общей.\n1) Если умер 1 раб, то отравленная бочка в его группе, среди 8 бочек, которые никто кроме него не пробовал и в 8 бочках из общей группы, т.е.второй этап выбор из 16 бочек 4 рабами.\n2) Если умерли 2 раба, то бочка из общая.Таких 8 штук при живых 3 рабах.\n\nВторой день.\nВариант 1: 16 бочек 4 раба\n1 раб - 1, 3, 4, 7, 8, 9, 10, 12\n2 раб - 1, 5, 6, 7, 8, 10, 11, 13\n3 раб - 2, 3, 5, 7, 8, 9, 11, 14\n4 раб - 2, 4, 6, 7, 9, 10, 11, 15\nВариант 2 : оставшиеся 8 бочек дегустируют 3 раба.\n1 - й раб-- 1, 2, 3, 4 бочки\n2 - й раб-- 1, 2, 5, 6 бочки\n3 - й раб-- 1, 3, 5, 7 бочки";

        bool slaves[] = { 1, 1, 1, 1, 1 };
        char burrels[][6] = { "....0", "...0.", "..0..", ".0...", "0...." };

        for (short i = 0; i < 5; ++i) {
            if (burrels[i][4 - i] == POISON[4 - i]) WINE[4 - i] = burrels[i][4 - i];
            else WINE[4 - i] = '1';
        }
        if (WINE == POISON) { convert_to_10(atoi(WINE.c_str())); return (0); }

        for (short i = 0; i < 5; ++i)
            if (WINE[4 - i] != burrels[i][4 - i]) burrels[i][4 - i] = '1';

        for (short i = 0; i < 5; ++i) {
            if (burrels[i][4 - i] == POISON[4 - i]) WINE[4 - i] = burrels[i][4 - i];
            else WINE[4 - i] = '2';
        }

        convert_to_10(atoi(WINE.c_str()));

        putchar('\n');

        return 0;
    }