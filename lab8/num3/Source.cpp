#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

struct Team
{
    string country;
    string teamName;
    string lastName;
    int number;
    int age;
    int height;
    int weight;
};

class  Participant {
public:
    string num;
    string type;
    string kyda;
    int otpr;
    int prib;
private:
    string x;

    Participant(string c, string t, string l, int n, int a, double h, int w)
    {
        num = c;
        type = t;
        kyda = l;
        otpr = n;
        prib = a;
    }
};

void ShellSort(int n, Team mass[])
{
    int i, j, step, tmp, tr = 0;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i].age;
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step].age)
                    mass[j].age = mass[j - step].age;
                else
                    break;
            }
            mass[j].age = tmp;
        }
    cerr << endl;

    for (int i = 0; i < n; i++) {
        if (mass[i].age > 20) {
            cerr << mass[i].lastName << " " << mass[i].age << " let";
            for (int j = 0; j < n - 1; j++)
                cerr << ", ";
            tr++;
        }
    }
    if (tr == 0)
        cout << "ti pedofil:)";
};

int main() {
    //int* Participant  = new int ();
    int numb, k;
    string s;
    cerr << "set numb of participants: "; cin >> numb;
    getline(cin, s);
    Team* a;
    a = new Team[numb];
    for (int i = 0; i < numb; i++) {
        cerr << "\nset country of " << i + 1 << " participant: ";
        while (std::cin.fail()) {
            std::cerr << "incorrect input data";
            return 0;
        }
        getline(cin, a[i].country);
    }
    for (int i = 0; i < numb; i++) {
        cerr << "\nset TeamName of " << i + 1 << " participant: ";
        while (std::cin.fail()) {
            std::cerr << "incorrect input data";
            return 0;
        }
        getline(cin, a[i].teamName);
    }
    for (int i = 0; i < numb; i++) {
        cerr << "\nset LastName of " << i + 1 << " participant: ";
        while (std::cin.fail()) {
            std::cout << "incorrect input data";
            return 0;
        }
        getline(cin, a[i].lastName);
    }
    for (int i = 0; i < numb; i++) {
        cerr << "\nset Number of " << i + 1 << " participant: ";
        while (std::cin.fail()) {
            std::cout << "incorrect input data";
            return 0;
        }
        cin >> a[i].number;
    }
    cout << "stop?(1(y),2(n))"; cin >> k;
    if (k == 1)
        return 0;

    for (int i = 0; i < a[i].number; i++) {
        cerr << "\nset Age of " << i + 1 << " participant: ";
        while (std::cin.fail()) {
            std::cout << "incorrect input data";
            return 0;
        }
        cin >> a[i].age;
    }
    for (int i = 0; i < a[i].number; i++) {
        cerr << "\nset Height of " << i + 1 << " participant: ";
        while (std::cin.fail()) {
            std::cout << "incorrect input data";
            return 0;
        }
        cin >> a[i].height;
    }
    for (int i = 0; i < a[i].number; i++) {
        cerr << "\nset Weight of " << i + 1 << " participant: ";
        while (std::cin.fail()) {
            std::cout << "incorrect input data";
            return 0;
        }
        cin >> a[i].weight;
    }
    getline(cin, s);
    cerr << "vivesti massiv?(1(y),2(n))"; cin >> k;
    if (k == 1)
        for (int i = 0; i < numb; i++)
            cerr << a[i].teamName;
    ShellSort(numb, a);
}