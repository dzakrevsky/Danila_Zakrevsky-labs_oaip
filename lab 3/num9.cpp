#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

int input()
{
    using namespace std;

    unsigned int x;
    while (true)
    {
        cin >> x;

        if (cin.fail() || cin.peek() != '\n')
        {
            cout << "\ntry again";
            cin.clear();
            cin.ignore(30000, '\n');
        }
        else
        {
            return x;
        }
    }
}

using namespace std;

int main() {
    srand(100);

    long long int n;
    long double a, value = 0.0;

    cout << "set n: ";

    n = input();
    if (n == 0)
    {
        main();
    }

    for (long long int i = 1; i < (n + 1); ++i)
    {
        a = rand()%2+1;
        value += pow(2, i - 1) * pow(-1, i - 1) * a;
    }

    cout << "\nf(x) = " << fixed << setprecision(0) << value;
}