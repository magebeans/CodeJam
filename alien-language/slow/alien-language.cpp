#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <conio.h>

using namespace std;

class Transmission
{
private:
	string word;
	vector<vector <char> > words;
	vector<string> possible_words;
	int length;

	vector<string> multiply_helper(vector<vector<char> >::iterator beg, vector<vector<char> >::iterator end);
public:
	void input(istream& in, int word_len) {in >> word; length = word_len;}
	void split();
	void multiply();
	int match(set<string> &dictionary);
};

int main()
{
	int word_len, dict_size, num_cases, i;
	set<string> dictionary;
	string word;
	ifstream fin("A-small-practice.in");
	ofstream fout("alien-language.out");

	fin >> word_len >> dict_size >> num_cases;
	for(i = 0; i < dict_size; i++)
	{
		fin >> word;
		dictionary.insert(word);
	}
	
	for(i = 0; i < num_cases; i++)
	{
		Transmission t;
		t.input(fin, word_len);
		t.split();
		t.multiply();
		fout << "Case #" << i+1 << ": " << t.match(dictionary) << endl;
	}
}

void Transmission::split()
{
	string::iterator it;
	for(it = word.begin(); it != word.end(); it++)
	{
		vector<char> temp; //Store all possible letters in temp
		if(*it == '(')
		{
			it++; //Move to first letter
			
			while(*it != ')')
				temp.push_back(*it++);
		}
		else
			temp.push_back(*it);
		words.push_back(temp); //If not bracketed, only one possible letter, so add as singleton
	}
}

void Transmission::multiply()
{
	possible_words = multiply_helper(words.begin(), words.end());
}

//Returns a vector string containing all possible string multiplications of the character vectors stored between beg and end
vector<string> Transmission::multiply_helper(vector<vector<char> >::iterator beg, vector<vector<char> >::iterator end)
{
	vector<string> ret;
	if(beg == end-1)
	{
		//Last layer of the recursion; only possible string multiplications are the characters themselves
		vector<char>::iterator it;
		for(it = beg->begin(); it != beg->end(); it++)
			ret.push_back(string(1,*it));
		return ret;
	}

	else
	{
		vector<string> suffix = multiply_helper(beg+1, end);
		vector<char>::iterator i;
		vector<string>::iterator j; 
		
		//Prepend the characters in the current character array to each possible string multiplication 
		//of the characters that follow 
		
		for(i = beg->begin(); i != beg->end(); i++)
			for(j = suffix.begin(); j!= suffix.end(); j++)
			{
				cout << string(1,*i) + *j << endl;
				getch();
				ret.push_back(string(1,*i) + *j);
			}
		return ret;	
	}
}

int Transmission::match(set<string> &dictionary)
{
	vector<string>::iterator it;
	int count = 0;
	for(it = possible_words.begin(); it != possible_words.end(); it++)
		if(dictionary.find(*it) != dictionary.end())
			count ++;
	return count;

}