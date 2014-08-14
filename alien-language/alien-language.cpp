#include <iostream>
#include "topcoder.h"
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
void display(ofstream &fout, bool a[15][26], int l);

void display(ofstream &fout, bool a[15][26], int l)
{
	int i, j;
	for (i = 0; i < 26; i++)
		fout << static_cast<char>('a' + i) << " ";
	fout << endl;

	for (i = 0; i < l; i++)
	{
		for (j = 0; j < 26; j++)
			fout << a[i][j] << " ";
		fout << endl;
	}

	fout << endl;
}

void clear(bool a[15][26]);
void clear(bool a[15][26])
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 26; j++)
			a[i][j] = 0;
	}
}


int main()
{
	ifstream fin("A-large-practice.in");
	ofstream fout("alien-language.out");
	int k, l, count;
	unsigned int i, n, j, d;
	vector<string> dictionary;

	fin >> l >> d >> n;

	for (i = 0; i < d; i++)
	{
		string temp;
		fin >> temp;
		dictionary.push_back(temp);
	}

	for (i = 0; i < n; i++)
	{
		bool pattern[15][26];
		clear(pattern);

		string temp;
		fin >> temp;
		// fout << temp << endl;

		k = 0;
		for (j = 0; j < temp.size(); j++)
		{

			if (temp[j] == '(')
			{
				j++;
				while (temp[j] != ')')
					pattern[k][static_cast<int>(temp[j++] - ('a'))] = 1;
				k++; //At end of brackets, new letter of word (new set of possible letters)
			}
			else
				pattern[k++][static_cast<int>(temp[j] - 'a')] = 1;

		}

		// display(fout, pattern, l);

		count = 0;
		bool match = 1;
		for (j = 0; j < dictionary.size(); j++) //Loop over dictionary words
		{
			match = 1; //Assume the word is possible
			for (k = 0; (k < l) && match; k++) //Loop over letter in each word
			{
				if (!pattern[k][static_cast<int>(dictionary[j][k] - 'a')]) //If letter is not in the correct position
				{
					// fout << dictionary[j][k] << " doesn't match" << endl;
					match = 0; //Word not possible as letter is not in the right place
				}
			}
			if (match)
				count++;
		}

		// fout << count << endl;
		fout << "Case #" << i + 1 << ": " << count << endl;
	}
}