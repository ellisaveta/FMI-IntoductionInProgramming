/**
*
* Solution to homework assignment 4
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
int NOD(int, int);
int* Result(const int&, const int&, const int&, const int&, const char&);
int main()
{
	int a1, b1;
	cin >> a1 >> b1;
	if (b1 <= 0)
	{
		cout << "-1";
		return 0;
	}
	char op;
	cin >> op;
	if (op != '+' && op != '-' && op != '*' && op != '/')
	{
		cout << "-1";
		return 0;
	}
	int a2, b2;
	cin >> a2 >> b2;
	if (b2 <= 0)
	{
		cout << "-1";
		return 0;
	}
	int* result;
	result = Result(a1, b1, a2, b2, op);
	if (result[1] == 0)
	{
		cout << "-1";
		return 0;
	}
	for (short i = 0; i < 2; ++i)
	{
		cout << *(result+i) << " ";
	}
	delete[] result;
	return 0;
}
int NOD(int a, int b)
{
	while (a != b)
	{
		if (a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		a -= b;
	}
	return a;
}
int* Result(const int& a1, const int& b1, const int& a2, const int& b2, const char& op)
{
	int* result = new int[2];
	switch(op)
	{
	case '+':
		result[0] = (a1*b2) + (a2*b1);
		result[1] = b1 * b2;
		break;
	case '-':
		result[0] = (a1*b2) - (a2*b1);
		result[1] = b1 * b2;
		break;
	case '*':
		result[0] = a1 * a2;
		result[1] = b1 * b2;
		break;
	case '/':
		result[0] = a1 * b2;
		result[1] = b1 * a2;
		break;
	}
	if (result[1] == 0)
	{
		return result;
	}
	else if (result[0] == 0)
	{
		result[1] = 1;
		return result;
	}
	int nod=1;
	if (result[0] < 0 && result[1] < 0)
	{
		result[0] = -result[0];
		result[1] = -result[1];
		nod = NOD(result[0], result[1]);
	}
	else if (result[0] < 0)
	{
		int temp = -result[0];
		nod = NOD(temp, result[1]);
	}
	else if (result[1] < 0)
	{
		int temp = -result[1];
		nod = NOD(result[0], temp);
	}
	else
	{
		nod = NOD(result[0], result[1]);
	}
	if (nod > 1)
	{
		result[0] /= nod;
		result[1] /= nod;
	}
	if (result[1] < 0)
	{
		result[0] = -result[0];
		result[1] = -result[1];
	}
	return result;
}
