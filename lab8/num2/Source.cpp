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
        cout << k + 1 << ") " << "Дата выезда: " << a[k].dataviezd << "\nМесто прибытия: " << a[k].kyda << "\nВремя выезда: " << a[k].time << "\nКолличество мест: " << a[k].mesta << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Количество маршрутов: ";

    freopen("file.txt", "r+", stdout); 
    freopen("file.txt", "w+", stdout); 

    int n, m;
    n = inputInt(0, 10);
    cerr << "Введите количество нужных мест: " << endl;
    m = inputInt(0, 100);
    cerr << "Введите нужный город: " << endl;
    string city;
    cin >> city;
    cerr << "Введите нужный день недели: " << endl;
    string day;
    cin >> day;
    cerr << "Введите нужное время: " << endl;
    string timme;
    cin >> timme;

    a = new Mesta[n];
    char q;
    bool fl = 0;

    for (int i = 0; i < n; i++)
        {
            cerr << "Ты хочешь дальше? (Y/N)";
            cin >> q;
            if (q != 'Y' && q != 'N')
            {
                cout << "Неправильно ввел, малыш, пропускаешь ход" << endl;
                continue;
            }
            if (q == 'N')
            {
                n = i + 1;
                break;
            }
            cerr << "Дата выезда: ";
            cin >> a[i].dataviezd;
            cerr << "Пункт назначения: ";
            cin >> a[i].kyda;
            cerr << "Время отправления: ";
            cin >> a[i].time;
            cerr << "Колличество свободных мест ";
            cin >> a[i].mesta;
            if (!fl)
            {
                cerr << "Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять струкуры напиши (1)";
                cin >> q;
                if (q == 'Y')check(i);
                if (q == '1')fl = 1;
            }
        }

    for (int i = 0; i < n; i++)
    {
        if (!fl)
        {
            cerr << "Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять струкуры напиши (1)";
            cin >> q;
            if (q == 'Y')check(n - 1);
            if (q == '1')fl = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (m < a[i].mesta && city == a[i].kyda && day == a[i].dataviezd && timme > a[i].time)
        {
            cout << "Есть подходящие рейсы." << endl;
            cout << i + 1 << ") " << "Дата выезда: " << a[i].dataviezd << "\nМесто прибытия: " << a[i].kyda << "\nВремя выезда: " << a[i].time << "\nКолличество мест: " << a[i].mesta << endl;
        }
        else
        {
            cout << "Нет подходящих рейсов по данный номер (" << i + 1 << ")" << endl;
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