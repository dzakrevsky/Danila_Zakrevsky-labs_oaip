#include <iostream>
#include <algorithm>

using namespace std;

struct Reis
{
    int num;
    string type;
    string kyda;
    string otpr;
    string prib;
};

void sort(int a, int fri)
{
    int j = 0;

    swap(a, fri);
    cout << "\n ";
    swap(fri, j);
    cout << "\n ";
}

int main(string[]) {
    setlocale(LC_ALL, "ru");
    cerr << " Задай Количество маршрутов, Время сейчас, ты хочешь дальше? (Y/N), Номер маршрута, Тип маршрута, Куда едем? \nВремя отправления, Вреям прибытия, Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять \nструкуры напиши (1), Хочешь удалить элемент(ы) массива? (Y/N), Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять струкуры напиши (1).\n";
    int n, k = 0;
    cin >> n;
    string time;
    cin >> time;
    Reis* a;
    a = new Reis[n];
    char q;
    for (int i = 0; i < n; i++)
    {
        cout << "Ты хочешь дальше? (Y/N)";
        cin >> q;
        if (q == 'N')
        {
            break;
        }
        cerr << "Номер маршрута: ";
        cin >> a[i].num;
        cerr << "Тип маршрута: ";
        cin >> a[i].type;
        cerr << "Куда едем? ";
        cin >> a[i].kyda;
        cerr << "Время отправления: ";
        cin >> a[i].otpr;
        cerr << "Время прибытия: ";
        cin >> a[i].prib;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].otpr < a[j].otpr)
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (time < a[i].otpr)
        {
            cout << i + 1 << ") " << a[i].num << endl << a[i].type << endl << a[i].otpr << endl << a[i].prib << endl;
        }
    }
    sort(n, k);
}