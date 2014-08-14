#include <iostream>

using namespace std;

int main()
{
	int i, j, k;
	int T;
	int a, b;
	int grid1[4][4], grid2[4][4];
	int common, num_common;

	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> a;
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
				cin >> grid1[j][k];
		}

		cin >> b;
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
				cin >> grid2[j][k];
		}

		a--;
		b--;

		num_common = 0;
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				if (grid1[a][j] == grid2[b][k])
				{
					common = grid1[a][j];
					num_common++;
				}
			}
		}

		cout << "Case #" << i + 1 << ": ";
		if (num_common == 0)
			cout << "Volunteer cheated!";
		else if (num_common > 1)
			cout << "Bad magician!";
		else
			cout << common;
		cout << endl;
	}
}