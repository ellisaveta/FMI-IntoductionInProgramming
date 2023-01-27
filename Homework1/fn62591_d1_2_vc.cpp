/**
*
* Solution to homework assignment 1
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
	int x;
	cin >> x;
	int big = -1;
	int lessBig = -1;
	while (x > 0)
	{
		if (x > big)
		{
			lessBig = big;
			big = x;
		}
		else if (x > lessBig)
		{
			lessBig = x;
		}
		cin >> x;
	}
	cout << lessBig;
	return 0;
}