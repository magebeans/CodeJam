#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
	int i, j;
	int T;
	double C, F, X;

	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> C >> F >> X;
		double rate = 2;
		double total_time = 0;
		// Time with zero cookies
		double farm_win_time = C / rate + X / (rate + F);
		double no_farm_win_time  = X / rate;

		while (farm_win_time < no_farm_win_time)
		{
			// If farm_win_time is less than no_farm_win_time, buy a farm
			total_time += C / rate;
			rate += F;

			farm_win_time = C / rate + X / (rate + F);
			no_farm_win_time  = X / rate;
		}

		total_time += X / rate;
		cout << "Case #" << i + 1 << ": " << setprecision(20) << total_time << endl;
	}
}