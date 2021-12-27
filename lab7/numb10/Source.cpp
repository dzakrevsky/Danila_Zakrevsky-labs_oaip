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
            std::cout << "������ �����!�������� ������ ��������: " << std::endl;
        }
    }

    void convert_to_10(short a) {
        short Value = 0;
        for (short i = 0; a != 0; ++i) {
            Value += (a % 10) * pow(3, i); a /= 10;
        }
        cout << "\n����� ����������� �����: " << Value;
    }

    int main() {
        setlocale(LC_ALL, "ru");
        std::cout << "������� ������� ����������� �����: " ;

        short barrel_of_poison = input(1, 240), i = 4; string POISON, WINE = "00000";

        convert_to_3(barrel_of_poison, POISON);

        if (POISON.length() < WINE.length()) {
            reverse(POISON.begin(), POISON.end());
            POISON.resize(5, '0');
            reverse(POISON.begin(), POISON.end());
        }
        std::cout << "\n��� 240 ����� ������� �� 6 ����� �� 40 ����� � ������.\n������ �� ����� ������ �� ����� 40 �����.\n����� ������ ��� ��������� ��� 8 ����� �� ������ ����� ������, ������� ����� 6 - �.\n����� ������ ����������� 40 ����� ����� � 32 ����� � 8 �� �����.\n1) ���� ���� 1 ���, �� ����������� ����� � ��� ������, ����� 8 �����, ������� ����� ����� ���� �� �������� � � 8 ������ �� ����� ������, �.�.������ ���� ����� �� 16 ����� 4 ������.\n2) ���� ������ 2 ����, �� ����� �� �����.����� 8 ���� ��� ����� 3 �����.\n\n������ ����.\n������� 1: 16 ����� 4 ����\n1 ��� - 1, 3, 4, 7, 8, 9, 10, 12\n2 ��� - 1, 5, 6, 7, 8, 10, 11, 13\n3 ��� - 2, 3, 5, 7, 8, 9, 11, 14\n4 ��� - 2, 4, 6, 7, 9, 10, 11, 15\n������� 2 : ���������� 8 ����� ����������� 3 ����.\n1 - � ���-- 1, 2, 3, 4 �����\n2 - � ���-- 1, 2, 5, 6 �����\n3 - � ���-- 1, 3, 5, 7 �����";

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