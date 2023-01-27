/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 4
* @compiler VC
*
*/
#include <iostream>
#include <vector>
using namespace std;
bool IsItRepeat(vector<int>, int);
bool IsTheSumZero(int, int, int);
int main()
{
	int N;
	do
	{
		cin >> N;
	} while (N < 3 || N>100);
	vector<int> vec;
	int input;
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		do
		{
			cin >> input;
		} while (IsItRepeat(vec, input));
		vec.push_back(input);
	}
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = i + 1; j < N; ++j)
		{
			for (size_t u = j + 1; u < N; ++u)
			{
				if (IsTheSumZero(vec[i], vec[j], vec[u])) ++count;
			}
		}
	}
	cout << count;
	return 0;
}
bool IsItRepeat(vector<int> v, int element)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (element == v[i])
		{
			return true;
		}
	}
	return false;
}
bool IsTheSumZero(int a, int b, int c)
{
	if (a + b + c == 0) return true;
	return false;
}