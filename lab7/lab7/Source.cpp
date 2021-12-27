#include <iostream> 
#include <cmath>
#include <cstdio>
#define DIG "0123456789ABCDEF"

using namespace std;

int Atoi(char* s, int p)
{
    int a = 0;
    for (int i = 0; s[i]; i++) // идем по всем символам числовой строки
    {
        int n = s[i]; // взяли очередной символ
        if (n >= '0' && n <= '9') // если это цифровой символ
            n -= '0'; // то уменьшаем его на код нуля (получим числа от 0 до 9)
        else
            n -= 'A' + 10; // если буквенный, то уменьшаем на код 'A' (получим числа от 10 до 15)
        a = a * p + n; // вычисляем значение полинома по схеме Горнера
    }
    return a;
}

int Itoa(int a, int p, char* s)
{
    static int i = 0, n;
    if (a)
    {
        ++i;
        Itoa(a / p, p, s);
        s[n - i--] = DIG[a % p];
    }
    else
        s[n = i] = '\0';
    int h = 0;
    return h;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a1, a2;
    char s[1024];
    cout << "Введите начальную систему счисления ";
    cin >> a1;
    cout << "Введите конечную систему счисления ";
    cin >> a2;
    cout << "Введите число ";
    cin >> s;
    Itoa(Atoi(s, a1), a2, s);
    cout << s << endl;
    return 0;
}