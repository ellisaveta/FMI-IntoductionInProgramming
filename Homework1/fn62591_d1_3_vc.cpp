/**
*
* Solution to homework assignment 1
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
using namespace std;
int main()
{
	int a1, a2, a3;
	cin >> a1;
	while (a1 < 0 || a1>9)
	{
		cin >> a1;
	}
	cin >> a2;
	while (a2 < 0 || a2>9)
	{
		cin >> a2;
	}
	cin >> a3;
	while (a3 < 0 || a3>9)
	{
		cin >> a3;
	}
	if (a1 == a2 || a2 == a3 || a3 == a1)
	{
		if (a1 == 0 && a2 == 0 && a3 == 0) cout << a1;
		else
		{
			if (a1 == a2)
			{
				if (a1 == 0) cout << a3 << a1 << a2 << a3;
				else cout << a1 << a3 << a2;
			}
			else if(a2 == a3)
			{
				if (a2 == 0) cout << a1 << a2 << a3 << a1;
				else cout << a2 << a1 << a3;
			}
			else
			{
				if (a1 == 0) cout << a2 << a1 << a3 << a2;
				else cout << a1 << a2 << a3;
			}
		}
	}
	else
	{
		if (a1 > a2) swap(a1, a2);
		if (a2 > a3) swap(a2, a3);
		if (a1 > a2) swap(a1, a2);
		if (a1 == 0) cout << a2 << a1 << a3 << a1 << a2;
		else cout << a1 << a2 << a3 << a2 << a1;
	}
	return 0;
}