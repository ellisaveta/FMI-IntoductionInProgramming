/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 2
* @compiler VC
*
*/
#include <iostream>
using namespace std;
int main()
{
	int N;
	int profit = 0;
	do
	{
		cin >> N;
	} while (N < 3 || N>365);
	double arr[365];
	for (int i = 0; i < N; ++i)
	{
		do
		{
			cin >> arr[i];
		} while (arr[i] < 0.1 || arr[i]>100);
	}
	for (int i = 1; i < N; i++)
	{
		while (arr[i - 1] > arr[i])
		{
			++i;
			if (i == N) break;
		}
		profit -= arr[i - 1];
		while (arr[i - 1] < arr[i])
		{
			++i;
			if (i == N) break;
		}
		profit += arr[i - 1];
	}
	cout << profit;
	return 0;
}