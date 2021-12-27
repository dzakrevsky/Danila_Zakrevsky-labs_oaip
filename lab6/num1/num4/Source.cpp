#include<iostream>
#include<string>

using namespace std;

void addSymbol(const string& text, char sign, const int& index, string& updateText)
{
	if (!islower(text[index]))
		sign -= 32;
	updateText.push_back(sign);
}

string peredelivaetText(string text) {
	string NewText;
	for (int i = 0; i < text.length(); i++)
	{
		if ((char)tolower(text[i]) == 'c')
		{
			if ((char)tolower(text[i + 1]) == 'e' || (char)tolower(text[i + 1]) == 'i' || (char)tolower(text[i + 1]) == 'y')
			{
				addSymbol(text, 's', i, NewText);
			}
			else
			{
				addSymbol(text, 'k', i, NewText);
				++i;
			}
		}
		else if ((char)tolower(text[i]) == 'q')
		{
			addSymbol(text, 'k', i, NewText);

			if ((char)tolower(text[i + 1]) == 'u')
			{
				addSymbol(text, 'v', i + 1, NewText);
				++i;
			}
		}
		else if ((char)tolower(text[i]) == 'p' && (char)tolower(text[i + 1]) == 'h')
		{
			addSymbol(text, 'f', i, NewText);
			++i;
		}
		else if ((char)tolower(text[i]) == 't' && (char)tolower(text[i + 1]) == 'h')
		{
			addSymbol(text, 'z', i, NewText);
			++i;
		}
		else if ((char)tolower(text[i]) == 'x')
		{
			addSymbol(text, 'k', i, NewText);
			addSymbol(text, 's', i, NewText);
		}
		else if ((char)tolower(text[i]) == 'w')
		{
			addSymbol(text, 'v', i, NewText);
		}
		else if ((char)tolower(text[i]) == 'e' && (char)tolower(text[i + 1]) == 'e')
		{
			addSymbol(text, 'i', i, NewText);
			++i;
		}
		else if ((char)tolower(text[i]) == 'o' && (char)tolower(text[i + 1]) == 'o')
		{
			addSymbol(text, 'u', i, NewText);
			++i;
		}
		else if ((char)tolower(text[i]) == 'y' && (char)tolower(text[i + 1]) == 'o' && (char)tolower(text[i + 2]) == 'u')
		{
			addSymbol(text, 'u', i, NewText);
			i += 2;
		}
		else if (((char)tolower(text[i]) == (char)tolower(text[i + 1])))
		{
			addSymbol(text, text[i], i, NewText);
			++i;
		}
		else if (!NewText.empty() && NewText.back() == (char)tolower(text[i]))
		{
			++i;
		}
		else
		{
			NewText.push_back(text[i]);
		}
	}
	cout << NewText;
	return NewText;
}

int main() {
	string text;
	cout << "set text: ";
	getline(cin, text);
	peredelivaetText(text);
}