/**
*
* Solution to homework assignment 2
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
void IsItPalindrom(vector<int>, int&);
int main()
{
	int N;
	do
	{
		cin >> N;
	} while (N < 3 || N>1000);
	vector<int> vec;
	int input;
	for (int i = 0; i < N; ++i)
	{
		do
		{
			cin >> input;
		} while (input < 0 || input>9);
		vec.push_back(input);
	}
	int count = 0;
	for (int i = 2; i < N; ++i)
	{
		vector<int> tempVec = { vec[i - 2], vec[i - 1], vec[i] };
		IsItPalindrom(tempVec, count);
		for (int j = i + 1; j < N; ++j)
		{
			tempVec.push_back(vec[j]);
			IsItPalindrom(tempVec, count);
		}
	}
	if (count > 0) cout << count;
	else cout << "-1";
	return 0;
}
void IsItPalindrom(vector<int> vec1, int& count)
{
	vector<int> copy;
	for (int i = (vec1.size() - 1); i >= 0; i--)
	{
		copy.push_back(vec1[i]);
	}
	if (vec1 == copy)
	{
		count++;
	}
}