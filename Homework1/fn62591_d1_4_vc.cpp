/**
*
* Solution to homework assignment 1
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
#include <cmath>
using namespace std;
int main()
{
	long long x;
	cin >> x;
	while (x<1 || x> 1e9)
	{
		cin >> x;
	}
	int n = (int)x;
	int sum = n+2;
	int minA = 1, minB = 1, minC = n;
	for (int a = 1; a <= sqrt(n); ++a)
	{
		for (int b = 1; b <= sqrt(n); ++b)
		{
			if (n % (a*b) == 0)
			{
				int c = n / (a*b);
				if (sum > (a + b + c))
				{
					sum = a + b + c;
					minA = a;
					minB = b;
					minC = c;
				}
			}
		}
	}
	cout << minA << " " << minB << " " << minC << '\n';
	return 0;
}
