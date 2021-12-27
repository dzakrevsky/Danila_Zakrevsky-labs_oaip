#include <iostream>
#include <cmath>

using namespace std;
int compareString(string str)
{
    bool t;
    string s;
    for (int i = str.size() - 1; i >= 0; --i)
        s += str[i];
    if (s != str)
        t = 1;
    else
        t = 0;
    return t;

}
int main()
{
    int k = 0;
    string str, s, s1;
    cin >> str;
    bool t = false;
    if (compareString(str)) {
        cout << str;
    }
    else {
        str.erase(str.size() - 1);
        if (compareString(str)) {
            cout << str.length();
        }
        else
            cout << "NO SOLUTION";
    }
    return 0;
}