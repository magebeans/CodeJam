#include <iostream>
#include <fstream>

using namespace std;

class Board
{
private:
	char board[50][50];
	int n; //size
public:
	Board(int size)
	{
		n = size;
	}
	void input(istream &i);
	void output(ostream &o);
	void rotate();
	void apply_gravity();
	bool check_win();
};

void Board::input(istream &in)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			in >> board[i][j];
		// in.get(); //For the endline
	}
}

void Board::output(ostream &o)
{
	int i, j;
	cout << endl;
	for (i = 0; i < n; i ++)
	{
		for (j = 0; j < n; j++)
			o << board[i][j];
		o << endl;
	}
}

void Board::apply_gravity()
{
	int i, j, temp;
	for (j = 0; j < n; j++)
	{
		for (i = n - 1; i >= 0; i--)
		{
			if (board[i][j] == 'B' || board[i][j] == 'R')
			{
				for (int k = i; k >= 1 && board[k - 1][j] == '.'; k--)
				{
					temp = board[k][j];
					board[k][j] = board[k][j - 1];
					board[k][j - 1] = temp;

				}
			}
		}
	}
}

bool Board::check_win()
{
	bool ret = 0;
	return ret;
}

void Board::rotate()
{
	int i, j;
	char temp;
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
		{
			temp = board[i][j];
			board[i][j] = board[j][n - i - 1];
			board[j][n - i - 1] = temp;
		}
}

int main()
{
	int n;
	fstream fin("in.in", ios::in);

	fin >> n;
	Board b(n);

	b.input(fin);
	b.output(cout);
	b.rotate();
	b.output(cout);
	b.apply_gravity();
	b.output(cout);
}