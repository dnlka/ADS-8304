#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

bool isbracketsequence(string);
bool issquare(string);
bool iscircle(string);
bool isfigure(string);

bool isbracketsequence(string str)
{
	return issquare(str) || iscircle(str) || isfigure(str);
}

bool issquare(string str)
{
	if (str == "+")
		return true;

	if (str.size() < 4) return false; // По условию кв.ск. = [ab], при этом не менее 4 символов

	int cnt = 0;

	for (int i = 1; i <= str.size() - 2; i++) // не учитываем первую скобку и последнюю
	{
		if (str[i] == '(') //по условию круглые скобки
			cnt++;
		if (str[i] == ')')
			cnt--;
		if (!cnt)
		{
			cnt = i;
			break;
		}
	}

	if (cnt == str.size() - 2)
		return false; // в строке нет места для других скобок

	string substr1 = "";
	string substr2 = "";

	for (int i = 1; i <= cnt; i++)
		substr1 += str[i]; // записываю первые скобки
	for (int i = cnt + 1; i <= str.size() - 2; i++)
		substr2 += str[i]; // вторые скобки

	cout << "Analyzing issquare : " << str << std::endl;

	return ((str[0] == '[') && (str[str.size() - 1] == ']') && iscircle(substr1) && isfigure(substr2));
}

bool iscircle(string str)
{
	if (str == "-")
		return true;

	if (str.size() < 4) return false;

	int cnt = 0;

	for (int i = 1; i <= str.size() - 2; i++)
	{
		if (str[i] == '{')
			cnt++;
		if (str[i] == '}')
			cnt--;
		if (!cnt)
		{
			cnt = i;
			break;
		}
	}

	if (cnt == str.size() - 2)
		return false;

	string substr1 = "";
	string substr2 = "";

	for (int i = 1; i <= cnt; i++)
		substr1 += str[i];
	for (int i = cnt + 1; i <= str.size() - 2; i++)
		substr2 += str[i];


	cout << "Analyzing iscircle : " << str << std::endl;


	return  ((str[0] == '(') && (str[str.size() - 1] == ')') && isfigure(substr1) && issquare(substr2));
}
//
bool isfigure(string str) {

	if (str == "0")
		return true;

	if (str.size() < 4) return false;

	int cnt = 0;

	for (int i = 1; i <= str.size() - 2; i++)
	{
		if (str[i] == '[')
			cnt++;
		if (str[i] == ']')
			cnt--;
		if (!cnt)
		{
			cnt = i;
			break;
		}
	}

	if (cnt == str.size() - 2)
		return false;

	string substr1 = "";
	string substr2 = "";

	for (int i = 1; i <= cnt; i++)
		substr1 += str[i];
	for (int i = cnt + 1; i <= str.size() - 2; i++)
		substr2 += str[i];



	cout << "Analyzing isfigure: " << str << std::endl;


	return ((str[0] == '{') && (str[str.size() - 1] == '}') && issquare(substr1) && iscircle(substr2));
}


int main()
{
        std ::string str;
        std::ifstream input;
		char tmp;
		string proc_str = "";
            	input.open("test.txt");
		if (!input)
        {
            std::cout << "Couldnt open file";
            }
            while(input.get(tmp)){
                if (tmp != '\n')
                {
                str +=tmp;

                }



                else
                {
                if (isbracketsequence(str)) cout << str << " == Its bracket" <<endl <<endl;
                else cout << str << " == Its not bracket" <<endl<<endl;
                str = "";
                }
            }

}

