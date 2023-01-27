/**
*
* Solution to homework assignment 1
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
	int n;
	double m, x;
	cin >> n;
	while (n <= 0)
	{
		cin >> n;
	}
	cin >> x;
	while (x < 0)
	{
		cin >> x;
	}
	cin >> m;
	while (m < 0)
	{
		cin >> m;
	}
	double moneyForBD = 0.0;
	double moneyFromSell = 0.0;
	double totalMoney = 0.0;
	if(n%2==0)
	{
		moneyFromSell = (n / 2)*m;
		for (int i = 0; i < (n / 2); i++)
		{
			moneyForBD += 30 + i * 30;
			moneyForBD -= 5;
		}
	}
	else
	{
		moneyFromSell = ((n / 2) + 1)*m;
		for (int i = 0; i < (n / 2); i++)
		{
			moneyForBD += 30 + i * 30;
			moneyForBD -= 5;
		}
	}
	totalMoney = moneyForBD + moneyFromSell;
	if (totalMoney >= x) cout << "yes\n" << totalMoney - x;
	else cout << "no\n" << x - totalMoney;
	return 0;
}