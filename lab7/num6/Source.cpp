#include<iostream>
using namespace std;

int main() {
	int t, num;
	cout << "set t: "; cin >> t;
	for (int i = 0; i < t; i++) { cout << "\nset num: "; cin >> num;
		if (num < 10)  if (num == 9) cout << "1";
			else cout << "\n0";
		else cout << num / 10;
	}
}