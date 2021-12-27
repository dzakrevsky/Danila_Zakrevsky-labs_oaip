#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

struct Mesta
{
    string dataviezd;
    string kyda;
    string time;
    int mesta;
};
Mesta* a;
int n;

void cValue() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

int inputInt(int minValue, int maxValue) {
    double x;
    while (true)
    {
        cin >> x;
        if (!cin.fail() && x > minValue && x < maxValue) {
            cValue();
            return x;
        }
        cValue();
        cout << "Enter correct value! " << endl;
    }
}

void del(Mesta arr[], int position)
{
    if (position >= n)return;
    Mesta* temp = new Mesta[n];
    for (int i = 0; i < n; i++)temp[i] = arr[i];
    delete[] arr;
    arr = new Mesta[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != position)
        {
            arr[j] = temp[i];
            j++;
        }
    }
}
void check(int i)
{
    cout << "check: ";
    for (int k = 0; k <= i; k++)
    {
        cout << k + 1 << ") " << "���� ������: " << a[k].dataviezd << "\n����� ��������: " << a[k].kyda << "\n����� ������: " << a[k].time << "\n����������� ����: " << a[k].mesta << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "���������� ���������: ";

    freopen("file.txt", "r+", stdout); 
    freopen("file.txt", "w+", stdout); 

    int n, m;
    n = inputInt(0, 10);
    cerr << "������� ���������� ������ ����: " << endl;
    m = inputInt(0, 100);
    cerr << "������� ������ �����: " << endl;
    string city;
    cin >> city;
    cerr << "������� ������ ���� ������: " << endl;
    string day;
    cin >> day;
    cerr << "������� ������ �����: " << endl;
    string timme;
    cin >> timme;

    a = new Mesta[n];
    char q;
    bool fl = 0;

    for (int i = 0; i < n; i++)
        {
            cerr << "�� ������ ������? (Y/N)";
            cin >> q;
            if (q != 'Y' && q != 'N')
            {
                cout << "����������� ����, �����, ����������� ���" << endl;
                continue;
            }
            if (q == 'N')
            {
                n = i + 1;
                break;
            }
            cerr << "���� ������: ";
            cin >> a[i].dataviezd;
            cerr << "����� ����������: ";
            cin >> a[i].kyda;
            cerr << "����� �����������: ";
            cin >> a[i].time;
            cerr << "����������� ��������� ���� ";
            cin >> a[i].mesta;
            if (!fl)
            {
                cerr << "����� �� ������ ��������� ������ ��������? (Y/N), ���� �� ������ ������ ��������� �������� ������ (1)";
                cin >> q;
                if (q == 'Y')check(i);
                if (q == '1')fl = 1;
            }
        }

    for (int i = 0; i < n; i++)
    {
        if (!fl)
        {
            cerr << "����� �� ������ ��������� ������ ��������? (Y/N), ���� �� ������ ������ ��������� �������� ������ (1)";
            cin >> q;
            if (q == 'Y')check(n - 1);
            if (q == '1')fl = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (m < a[i].mesta && city == a[i].kyda && day == a[i].dataviezd && timme > a[i].time)
        {
            cout << "���� ���������� �����." << endl;
            cout << i + 1 << ") " << "���� ������: " << a[i].dataviezd << "\n����� ��������: " << a[i].kyda << "\n����� ������: " << a[i].time << "\n����������� ����: " << a[i].mesta << endl;
        }
        else
        {
            cout << "��� ���������� ������ �� ������ ����� (" << i + 1 << ")" << endl;
        }
    }
}
/*
 2
 50
 MINSK
 PONEDELNIK
 16:00
 Y
 VTORNIK
 MOZYR
17:00
 99
 Y
 PONEDELNIK
 MINSK
 15:30
 100
 Y
*/