/**
*
* Solution to homework assignment 2
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
int main()
{
	int N;
	cin >> N;
	while (N < 3 || N>100)
	{
		cin >> N;
	}
	int arr[100];
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		while (arr[i] < 1)
		{
			cin >> arr[i];
		}
	}
	bool isItTriangle = true;
	const int MAXI = (N % 2 == 0) ? (N / 2 - 1) : (N / 2);
	for (int i = 1; i <= MAXI; ++i)
	{
		if (abs(arr[i] - arr[i - 1]) != abs(arr[N - i] - arr[N - i - 1]))
		{
			isItTriangle = false;
			break;
		}
	}
	cout << isItTriangle << "\n";
	return 0;
}
