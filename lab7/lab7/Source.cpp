#include <iostream> 
#include <cmath>
#include <cstdio>
#define DIG "0123456789ABCDEF"

using namespace std;

int Atoi(char* s, int p)
{
    int a = 0;
    for (int i = 0; s[i]; i++) // ���� �� ���� �������� �������� ������
    {
        int n = s[i]; // ����� ��������� ������
        if (n >= '0' && n <= '9') // ���� ��� �������� ������
            n -= '0'; // �� ��������� ��� �� ��� ���� (������� ����� �� 0 �� 9)
        else
            n -= 'A' + 10; // ���� ���������, �� ��������� �� ��� 'A' (������� ����� �� 10 �� 15)
        a = a * p + n; // ��������� �������� �������� �� ����� �������
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
    cout << "������� ��������� ������� ��������� ";
    cin >> a1;
    cout << "������� �������� ������� ��������� ";
    cin >> a2;
    cout << "������� ����� ";
    cin >> s;
    Itoa(Atoi(s, a1), a2, s);
    cout << s << endl;
    return 0;
}