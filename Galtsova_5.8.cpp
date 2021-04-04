#include <iostream>
#include <string>

using namespace std;

string compute(string text);

int main()
{
    cout << "** This program encodes text according to the 'Supplement' principle: **"
         << "\n** in English text, the letter 'a' is replaced by 'z', 'b' by 'y', etc.   "
         << "\n** Enter the source text for encoding: ";

	string text;
	getline(cin, text);
    
    text = compute(text);
    
    cout << "\n** The result of the program: " << text << endl;

	return 0;
}

string compute(string text)
{
    for (int i = 0, size = text.length(); i < size; i++)
    {
        char letter = text[i];

        if (letter >= 'a' && letter <= 'z')
        {
            text[i] = 'z' - (text[i] - 'a');
        }
        else if (letter >= 'A' && letter <= 'Z')
        {
            text[i] = 'Z' - (text[i] - 'A');
        }
        else continue;
    }
    return text;
}