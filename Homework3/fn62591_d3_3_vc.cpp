/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 3
* @compiler VC
*
*/
#include <iostream>
#include <vector>
using namespace std;
bool IsItMagic(const int*, vector<vector<double>>);
int main()
{
	int n;
	cin >> n;
	if ((n <= 1) || (n >= 1000))
	{
		cout << "-1";
		return 0;
	}
	vector<vector<double>> matrix(n);
	for (short i = 0; i < n; ++i)
	{
		double element;
		for (short j = 0; j < n; ++j)
		{
			cin >> element;
			if ((element < 0) || (element > 100))
			{
				cout << "-1";
				return 0;
			}
			matrix[i].push_back(element);
		}
	}
	if (IsItMagic(&n, matrix)) cout << "true";
	else cout << "false";
	return 0;
}
bool IsItMagic(const int* n, vector<vector<double>> matrix)
{
	vector<double> checker;
	double sumOfHorizontal=0;
	double sumOfVertical = 0;
	double sumOfMainDiagonal = 0;
	double sumOfOtherDiagonal = 0;
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		sumOfHorizontal = 0;
		for (size_t j = 0; j < matrix[i].size(); ++j)
		{
			sumOfHorizontal += matrix[i][j];
			if (i == j) sumOfMainDiagonal += matrix[i][j];
		}
		checker.push_back(sumOfHorizontal);
	}
	checker.push_back(sumOfMainDiagonal);
	for (size_t j = 0; j < matrix.size(); ++j)
	{
		sumOfVertical = 0;
		for (size_t i = 0; i < *n; ++i)
		{
			sumOfVertical += matrix[i][j];
			if (i + j == (*n-1)) sumOfOtherDiagonal += matrix[i][j];
		}
		checker.push_back(sumOfVertical);
	}
	checker.push_back(sumOfOtherDiagonal);
	for (short i = 1; i < checker.size(); ++i)
	{
		if (checker[i] != checker[i - 1])
		{
			return false;
		}
	}
	return true;
}