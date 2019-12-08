#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// https://github.com/Rbeck200/Projects
// http://www.cplusplus.com/doc/tutorial/control/

// Problem 4
string flipText(string text)
{
	if (text.size() == 0)
	{
		return "";
	}
	else
	{
		string result;
		int current;

		for (int i = text.length(); i > 0; i--)
		{
			current = text.at(i - 1);
			result.push_back(current);
		}
		return result;
	}
}

// Problem 6
vector<int> difference(vector<int> first, vector<int> second)
{
	vector<int> result;
	bool same = false;
	for (int i = 0; i < first.size(); i++)
	{
		for (int j = 0; j < second.size(); j++)
		{
			if (second[j] == first[i])
			{
				same = true;
			}
		}
		if (same != true)
		{
			result.push_back(first[i]);
		}
		else
		{
			same = false;
		}
	}
	return result;
}

// Problem 7
char toUpper(char ch)
{
	if (ch < 123 && ch > 96)
	{
		ch = ch - 32;
	}
	return ch;
}

// Problem 8
int findMode(string input_file)
{
	int mode;
	int value;
	int instances;
	int most_instances = 0;
	vector<int> numbers;
	ifstream fin{ input_file };
	while (fin.good())
	{
		fin >> value;
		numbers.push_back(value);
	}
	mode = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		instances = 0;
		for (int j = (i + 1); j < numbers.size(); j++)
		{
			if (numbers[i] == numbers[j])
			{
				instances++;
			}
		}
		if (instances > most_instances)
		{
			most_instances = instances;
			mode = numbers[i];
		}
	}
	return mode;
}

// Problem 9 DOESN'T WORK
void findLongSentences(string input_file, int sentence_length)
{
	ifstream fin{ input_file };
	vector<string> sentences;
	vector<string> words;
	string current;
	char punct;
	while (fin.good() == true)
	{
		getline(fin, current, '.');
		fin >> punct;
		current.push_back(punct);
		cout << "Current @ Top: " << current << endl;
		sentences.push_back(current);
	}
	fin.close();

	current = "";
	for (int i = 0; i < sentences.size(); i++)
	{
		for (int j = 0; j < sentences[i].length(); j++)
		{
			if (sentences[i].at(j) == ' ' && current != "")
			{
				words.push_back(current);
				current = "";
			}
			else
			{
				current.push_back(sentences[i].at(j));
			}
		}
		if (words.size() > sentence_length)
		{
			cout << sentences[i] << endl;
		}
		words = {};
	}
}

int main() 
{
	cout << boolalpha;
	// Testing ***flipText***
	string testy = "candle";
	string testy_2 = "Cane Blah Sick";
	cout << (flipText(testy)) << endl;
	cout << (flipText(testy_2)) << endl;

	// Testing ***difference***
	vector<int> first = { 1, 2, 3 };
	vector<int> second = { 1, 3, 5 };
	vector<int> result = { 2 };
	cout << (difference(first, second) == result) << endl;

	// Testing ***toUpper***
	char ch = 'a';
	cout << toUpper(ch) << endl;

	// Testing ***findMode***
	cout << findMode("Text.txt") << endl;

	// Testing ***findLongSentences***
	findLongSentences("Text_2.txt", 5);

	return 0;
}