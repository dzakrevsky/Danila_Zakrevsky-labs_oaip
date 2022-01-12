#include <iostream> 
#include <cmath> 
#include<conio.h> 
#include<string> 
using namespace std;
int main() {
setlocale(LC_ALL, "Russian");
int c, o, t, u, v, n = 0;
int f = 0;
int b = 0;
int m = 0;
o = 0;
u = 0;
t = 0;
string sr; 
cout << "Введите строку" << endl;
getline(cin, sr); 
for (int i = 0; i < sr.length(); i++) {
    if (sr[i] == '.') { 
        if (!(isdigit(sr[i + 1])) || !(isdigit(sr[i - 1]))) { 
            continue;
        }
        else {
            for (v = i - 1; v > 0; v--) { 
                if (isdigit(sr[v])) {
                    b = v;
                }
                else {
                    if (sr[v] == '-') {
                        b = v;
                        break;
                    }
                    else break;
                }
            }
            for (f = b; f < sr.length(); f++) {
                if (sr[f] == '.') {
                    break;
                }
                if (sr[f] == '-') {
                    continue;
                }
                o++;
            }
        }
        f = 0;
        for (int n = i + 1; n < sr.length(); n++) {
            if (isdigit(sr[n])) {
                m = n;  
            }
            else break;
        }
        for (f = m; f > 0; f--) {  
            if (sr[f] == '.') {
                break;
            }
            u++;
        }
    }
}
if (o == u) {
    c = 0;
}
else {
    c = 1;
}
if (c == 0 && t == 0) {
    cout << "Число = ";
    for (int i = b; i <= m; i++) {
        cout << sr[i];
    }
}
else {
    cout << "такого числа нет";
}
cout << endl;

}
