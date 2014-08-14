#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int cases,i;
	fstream fin("A-large-practice.in" , ios::in);
	fstream fout("store_credit.out" , ios::out);

	fin>> cases;
	for(i = 0; i < cases; i++)
	{
		map <int,vector<int> > indices;
		map <int,vector<int> >::iterator first;
		
		int credit, num_items, j, price;
		fin>> credit;
		fin>> num_items;

		for(j = 0 ; j < num_items; j++)
		{
			fin>> price;
			indices[price].push_back(j + 1);
		}

		for(first = indices.begin(); first!=indices.end(); first++)
		{
			map<int, vector<int> >::iterator second = indices.find(credit - first->first);
			int a,b;
			if(second != indices.end())
			{
				a = first->second[0];
				if(second == first)
					b = second->second[1];
				else
					b = second->second[0];

				int temp = (a < b)?(a):(b);
				b 		 = (a < b)?(b):(a);
				a		 = temp;
				
				fout << "Case #" << i + 1 << ": " << a << " " << b << endl;
				break;
			}
		}
	}

	getch();
}
