#include<iostream>
using namespace std;
#pragma warning(disable : 4996)

int main() {
	int num, k = 0;
	cout << "set num: "; cin >> num;
	for (int i = 0; i <= num; i += 3) {
		if (i == num)
			k = 1;
	}
	if (k == 1)
		cout << "\ndel na 3";
	else
		cout << "\nne del na 3";

	k = 0;
	for (int i = 0; i <= num; i += 79) {
		if (i == num)
			k = 1;
	}
	if (k == 1)
		cout << "\ndel na 79";
	else
		cout << "\nne del na 79";

	k = 0;
	for (int i = 0; i <= num; i += 151) {
		if (i == num)
			k = 1;
	}
	if (k == 1)
		cout << "\ndel na 151";
	else
		cout << "\nne del na 151";
}