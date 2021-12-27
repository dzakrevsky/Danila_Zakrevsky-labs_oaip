#include<iostream>
using namespace std;
#pragma warning(disable : 4996)

char* removeSpaces(char* s) {
    char k[255];
    int i = 0;
    int n = 0;
    while (i < strlen(s)) {
        if (isalpha(*(s + i))) {
            k[n] = *(s + i);
            n++;
        }
        i++;
    }
    char* newarr = new char(n);
    strncpy(newarr, k, n);
    return newarr;
}

int main()
{
    int n = 0;
    char* newarr = new char(n);
    char s[255];
    cout << "Enter string:\n";
    cin.getline(s, 255, '\n');
    removeSpaces(s);
    cout << removeSpaces(newarr);
}
