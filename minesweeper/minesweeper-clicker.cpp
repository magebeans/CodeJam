#include <fstream>
#include <conio.h>
#include <cctype>
#include <iostream>

using namespace std;

class Board
{
private:
	char board[20][20];
	int r, c;
public:
	Board (int x, int y): r(x), c(y) {};
	void read(char *name);
	void fill(int n);
	void mine_spiral(int n);
	void click(int x, int y);
	void display();
};

int main()
{
	int T;
	fstream fin("board.txt");
	fin >> T;
	for (int i = 0; i < T; i++)
	{
		int r, c, m;
		fin >> r >> c >> m;
		Board b(r, c);
		b.mine_spiral(m);
		b.click(r / 2, c / 2);
		b.display();
	}
}

void Board::read(char *name)
{
	fstream fin(name, ios::in);
	fin >> r;
	fin >> c;

	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			fin >> board[i][j];
		}

}

void Board::fill(int n)
{
	struct Point
	{
		int x, y, dx, dy;
		void increment ()
		{
			x += dx;
			y += dy;
		}
	};

	Point corners[] = {{0, 0, 1, 0}, {0, c - 1, 0, 1}, {r - 1, 0, -1, 0}, {r - 1, c - 1, 0, -1}};
	int i = 0;
	while (i < n)
	{
		for (int j = 0; j < 4 && i < n; j++, i++)
		{
			board[corners[j].x][corners[j].y] = '*';
			corners[j].increment();
		}
	}
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
		for (j = depth; j < c - depth && i < n; j++, i++)
			board[depth][j] = '*';
		for (j = depth + 1; j < r - depth && i < n; j++, i++)
			board[j][c - 1 - depth] = '*';
		for (j = c - 2 - depth; j >= depth && i < n; j--, i++)
			board[r - 1 - depth][j] = '*';
		for (j = r - 2 - depth ; j > depth && i < n; j--, i++)
			board[j][depth] = '*';
	}
	while (++depth && i < n);
}