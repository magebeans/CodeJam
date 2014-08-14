#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

class Board
{
private:
	char board[20][20];
	int r, c, n;
public:
	Board (int x, int y, int z = 0): r(x), c(y), n(z) {};
	void fill(int x = 0);
	void mine_spiral(int n = 0);
	void display();
	void click(int x, int y);
};

void Board::display()
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Board::click(int x, int y)
{
	if (board[x][y] == '*' || isdigit(board[x][y]))
		return;

	int dx[] = { -1, 0, 1};
	int dy[] = { -1, 0, 1};
	int i, j;

	int count = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (board[x + dx[i]][y + dy[j]] == '*' &&
			        x + dx[i] >= 0 && x + dx[i] < r &&
			        y + dy[j] >= 0 && y + dy[j] < c)

			{
				count++;
			}
		}

	board[x][y] = (char)('0' + count);
	if (count == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (x + dx[i] >= 0 && x + dx[i] < r &&
				        y + dy[j] >= 0 && y + dy[j] < c)
				{
					click(x + dx[i], y + dy[j]);
				}
			}
		}
	}
}

void Board::fill(int x)
{
	n = r * c - x;
	int i, j, num = 0;

	for (i = 0; i < r; i++)
		for (j = 0; j < c ; j++)
			board[i][j] = '*';

	for (i = 0; i < r; i++)
		for (j = 0; j < c && num < n; j++, num++)
			board[i][j] = '.';

	//Diagonal
	// for (i = 0; i < r; i++)
	// {
	//  for (j = 0; j < (r - i) && num < n; j++, num++)
	//      board[i][j] = '.';
	// }

	// for ( j = 0; j < c; j++)
	// {
	//  for (i = 0; i < (c - j) && num < n; i++, num++)
	//      board[i][j] = '.';
	// }
}

void Board::mine_spiral(int n)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			board[i][j] = '.';

	int depth = 0;
	i = 0;
	do
	{
		for (j = depth; j < c - depth && i < n; j += 1, i++)
			board[depth][j] = '*';
		for (j = depth + 1; j < r - depth && i < n; j += 1, i++)
			board[j][c - 1 - depth] = '*';
		for (j = c - 2 - depth; j >= depth && i < n; j -= 1, i++)
			board[r - 1 - depth][j] = '*';
		for (j = r - 2 - depth ; j > depth && i < n; j -= 1, i++)
			board[j][depth] = '*';
	}
	while (++depth && i < n);
}

int main()
{
	Board a(5, 5, 0);
	a.mine_spiral(14);
	a.click(2, 2);
	a.display();
}