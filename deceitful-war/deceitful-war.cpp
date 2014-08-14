#include <iostream>
#include <algorithm>
#include <fstream>
#include <list>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		int npoints = 0;
		int npoints_d = 0;
		double temp;
		list<double> nblocks;
		list<double> kblocks;
		list<double> kbcopy;
		list<double>::iterator k, j;

		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			nblocks.push_back(temp);
		}

		for (int j = 0; j < N; ++j)
		{
			cin >> temp;
			kblocks.push_back(temp);
		}

		nblocks.sort();
		kblocks.sort();
		kbcopy = kblocks;

		//Ken perfect strategy = Choose smallest number greater than Naomi's, or smallest number if none greater.
		//Normal war
		for (k = nblocks.begin(); k != nblocks.end(); k++)
		{
			for (j = kblocks.begin(); j != kblocks.end() && (*j < *k); j++);

			if ( j == kblocks.end() )
				j = kblocks.begin();

			if (*j < *k)
				npoints++;
			kblocks.erase(j);
		}

		//Deceit
		// for (k = nblocks.begin(); k != nblocks.end(); k++)
		// {
		//  for (j = kblocks.begin(); j != kblocks.end(); j++)
		//  {
		//      if (*k > *j)
		//      {
		//          npoints_d ++;
		//          kblocks.erase(j);
		//          j = kblocks.end();
		//      }
		//  }
		// }

		kblocks = kbcopy; //Ascending
		while (nblocks.size() != 0)
		{
			kblocks.reverse(); //Descending
			k = nblocks.begin(); //Smallest of N
			j = kblocks.begin(); //Biggest of K

			while (k != nblocks.end() && j != kblocks.end() && nblocks.back() < *j)
			{
				k = nblocks.erase(k);
				j = kblocks.erase(j);
				// Ken defeats Naomi until Naomi's biggest is bigger than Ken's biggest
			}

			kblocks.reverse(); //Ascending
			nblocks.reverse(); //Descending now
			k = nblocks.begin(); //Biggest of N
			j = kblocks.begin(); //Smallest of K

			while (k != nblocks.end() && j != kblocks.end() && *k > kblocks.back())
			{
				npoints_d ++;
				k = nblocks.erase(k);
				j = kblocks.erase(j);
			}

		}

		// //Deceit
		// // Take any guaranteed wins
		// kblocks = kbcopy; //Ascending
		// nblocks.reverse(); //Descending now
		// k = nblocks.begin();
		// j = kblocks.begin();

		// while (k != nblocks.end() && j != kblocks.end() && *k > kblocks.back())
		// {
		//  npoints_d ++;
		//  k = nblocks.erase(k);
		//  j = kblocks.erase(j);
		// }

		// //Remove Ken's largest using Naomi's smallest
		// nblocks.reverse(); //Ascending now
		// kblocks.reverse(); //Descending now
		// k = nblocks.begin(); // Smallest of Naomi
		// j = kblocks.begin(); // Largest of Ken

		// while (k != nblocks.end() && j != kblocks.end() && *k < *j)
		// {
		//  k = nblocks.erase(k);
		//  j = kblocks.erase(j);
		//  // Ken defeats Naomi
		// }

		// nblocks.reverse(); //Descending now
		// k = nblocks.begin(); //Largest of Naomi
		// j = kblocks.begin(); //Largest of Ken

		// while (k != nblocks.end() && j != kblocks.end())
		// {
		//  if (*k > *j)
		//      npoints_d ++;
		//  k = nblocks.erase(k);
		//  j = kblocks.erase(j);
		// }

		// All of Naomi's blocks can now beat Ken's blocks
		// npoints_d += nblocks.size();
		cout << "Case #" << i + 1 << ": " << npoints_d << " " << npoints << " " << endl;
	}
}