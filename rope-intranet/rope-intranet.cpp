#include <iostream>
#include <fstream>
#include <list>

using namespace std;
typedef list<pair <int, int> > pl;
int main()
{
	int n, t, i, intersections;
	ifstream fin("A-large-practice.in");
	fin >> t;

	for (int j = 0; j < t; j++)
	{
		fin >> n;
		pl ropes;
		for (i = 0; i < n; i++)
		{
			pair<int, int> temp;
			fin >> temp.first >> temp.second;
			ropes.push_back(temp);
		}

		intersections = 0;
		for (pl::iterator it = ropes.begin(); it != ropes.end(); it++)
		{
			for (pl::iterator other = it; other != ropes.end(); other++)
			{
				if ((other->first < it->first && other->second > it->second) ||
				        (other->first > it->first && other->second < it->second))
				{
					intersections++;
				}
			}
		}

		cout << "Case #" << j + 1 << ": " << intersections << endl;
	}
}