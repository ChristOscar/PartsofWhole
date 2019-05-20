#include <iostream>
#include <cstring>

using namespace std;

string convertPigLatin(char*);

int main()
{
	char str[100] = "Welcome. Test Sequence!";

	cout << "**********************************************************\n";

	cout << "\t\t= Info = \n";
	cout << "This program converts the format of a sentence to Pig Latin.\n";

	cout << "**********************************************************\n";

	cout << "\t\t= Example = \n";
	cout << "Sentence : \"" << str <<"\"\n";
	string result = convertPigLatin(str);
	cout << "   Result: \"" << result << "\"\n";

	cout << "**********************************************************\n";

	cout << "Please enter your sentence.\n";
	cout << "Sentence : ";
	cin.getline(str, 100);

	cout << "**********************************************************\n";

	cout << "\t\t = Coversion =\n";
	result = convertPigLatin(str);
	cout << " Result : \"" << result << "\"\n";

	return 0;
}

string convertPigLatin(char* str)
{
	//holds result
	string res = " ";
	bool wordWait = true;
	//used to hold the first letter of a word

	char firstLetter;
	for (unsigned i = 0; i < strlen(str); i++)
	{
		if (wordWait && isalpha(str[i]))
		{
			firstLetter = str[i];
			wordWait = false;
		}
		else if (!wordWait && isalpha(str[i]))
		{
			res += str[i];
		}
		else if (!wordWait && !isalpha(str[i])) 
		{
			res += firstLetter;
			res += "ay";
			wordWait = true;
			res += str[i];
		}
		else
		{
			res += str[i];
		}
	}
	return res;
}