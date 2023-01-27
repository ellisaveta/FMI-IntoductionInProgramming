/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Elisaveta Georgieva
* @idnumber 62591
* @task 5
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
	while (x<2 || x>1e9)
	{
		cin >> x;
	}
	int n = (int)x;
	bool infinity = false;
	short number = 0;
	for (int i = 3; i <= n; ++i)
	{
		if (n%i == 0 && i%5!=0 && i%2==1 )
		{
			infinity = true;
			break;
		}
	}
	if (infinity) cout << "NO\n";
	else
	{
		while (n > 1)
		{
			++number;
			if (n % 10 == 0) n /= 10;
			else if (n % 2 == 0) n /= 2;
			else n /= 5;
		}
		cout << number << '\n';
	}
	return 0;
}