/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 1
* @compiler VC
*
*/
#include <iostream>
using namespace std;
bool CanItBeIncreasingWithNChanges(const int[], const int&, const int&);
int MaxLengthOfIncreasing(const int[], const int&);
int main()
{
	int N;
	int M;
	cin >> N;
	if (N <= 0)
	{
		cout << "-1";
		return 0;
	}
	cin >> M;
	if (M <= 0)
	{
		cout << "-1";
		return 0;
	}
	int *arr = new int[M];
	for (int i = 0; i < M; ++i)
	{
		cin >> arr[i];
		if (arr[i] <= 0)
		{
			cout << "-1";
			return 0;
		}
	}
	cout << CanItBeIncreasingWithNChanges(arr, M, N);
	delete[]arr;
	return 0;
}
bool CanItBeIncreasingWithNChanges(const int arr[], const int& size, const int& N)
{
	return MaxLengthOfIncreasing(arr, size) == size || ((size - MaxLengthOfIncreasing(arr, size)) <= N);
}
int MaxLengthOfIncreasing(const int arr[], const int& size) 
{
	int *lengths = new int[size];
	for (int i = 0; i < size; ++i)
	{
		lengths[i] = 1;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] <= arr[i])
			{
				if (lengths[j] + 1 > lengths[i]) lengths[i] = lengths[j] + 1;
			}
		}
	}

	int maxLength = lengths[0];
	for (int i = 1; i < size; i++)
	{
		if (lengths[i] > maxLength) maxLength = lengths[i];
	}
	delete[] lengths;
	return maxLength;
}