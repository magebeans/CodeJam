#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <float.h>
#include <iomanip>

using namespace std;

void input(fstream& fin, vector<double>& a, int n);
int msp_brute(const vector<double>& a, vector<double>& b);
double msp_sort(vector<double>& a, vector<double>& b);
int factorial(int n);

int main()
{
	int cases, n, i;
	double msp;
	fstream fin("A-large-practice.in" , ios::in);
	fstream fout("min-scale-prod.out", ios::out);

	fin>>cases;

	for(i = 0 ; i < cases; i++)
	{
		fin>>n;
		
		vector<double> a,b;
		input(fin,a,n);
		input(fin,b,n);
		
		msp = msp_sort(a,b);
		
		fout << setprecision(15);
		fout << "Case #" << i+1 << ": " << msp << endl;
	}
}

void input(fstream& fin, vector<double>& a, int n)
{
	double x;
	for(int i = 0; i < n; i++)
	{
		fin >> x;
		a.push_back(x);
	}
}

int msp_brute(const vector<double>& a, vector<double>& b)
{
	int min_scale_prod, b_perms, i, scale_prod;
	vector<double>::const_iterator j,k;

	min_scale_prod = INT_MAX;
	b_perms = factorial(b.size());
	
	for(i = 0; i < b_perms; i++)
	{
		scale_prod = 0;
		
		for(j = a.begin(), k = b.begin(); j != a.end(); j++, k++)
			scale_prod += (*j) * (*k);
		if(scale_prod < min_scale_prod)
			min_scale_prod = scale_prod;

		next_permutation(b.begin(),b.end());
	}

	return min_scale_prod;
}

double msp_sort(vector<double>& a, vector<double>& b)
{
	double scale_prod = 0;
	vector<double>::iterator j;
	vector<double>::reverse_iterator k;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(j = a.begin(), k = b.rbegin(); j!= a.end(); j++, k++)
		scale_prod += (*j) * (*k);
	
	return scale_prod;
}

int factorial(int n)
{
	static int factorials[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	if(n > 10)
		return 0;
	else
		return factorials[n];
}