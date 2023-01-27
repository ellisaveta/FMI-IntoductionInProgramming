/**
*
* Solution to homework assignment 3
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
bool IsItGood(const char[], const short);
int HowManyRepeats(const char[], const short, const char);
bool IsItEncounteredBefore(const char[], const short, const char);
bool IsTheCountEqualWhenDeleteOne(const int[], const short);
bool IsTheCountEqual(const int[], const short);
int main()
{
	const short MAX_SIZE = 151;
	char arr[MAX_SIZE];
	cin.getline(arr, MAX_SIZE);
	short i = 0;
	for (i = 0; arr[i] != '\0'; ++i){}
	const short SIZE = i;
	if (SIZE == 0)
	{
		cout << "-1";
		return 0;
	}
	cout << IsItGood(arr, SIZE);
	return 0;
}
bool IsItGood(const char arr[], const short size)
{
	int counter[150] = {0};
	int j = -1;
	for (short i = 0; i < size; ++i)
	{
		if (!IsItEncounteredBefore(arr, i, arr[i]))
		{
			++j;
			counter[j] = HowManyRepeats(arr, size, arr[i]);
		}
	}
	int counterSize = 0;
	for (int i = 0; counter[i] != 0; ++i)
	{
		++counterSize;
	}
	if (IsTheCountEqual(counter, counterSize)) return true;
	else
		return IsTheCountEqualWhenDeleteOne(counter, counterSize);
}
int HowManyRepeats(const char arr[], const short size, const char ToFind)
{
	int howMany = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == ToFind)
		{
			howMany+=1;
		}
	}
	return howMany;
}
bool IsItEncounteredBefore(const char arr[], const short index, const char ToFind)
{
	for (short i = 0; i < index; ++i)
	{
		if (arr[i] == ToFind)
		{
			return true;
		}
	}
	return false;
}
bool IsTheCountEqualWhenDeleteOne(const int counter[], const short size)
{
	for (short el = 0; el < size; ++el) {
		int temp[150] = {};
		for (short k = 0; k < el; ++k)
		{
			temp[k] = counter[k];
		}
		if (counter[el] - 1 > 0)
		{
			temp[el] = counter[el] - 1;
			for (short j = el + 1; j < size; ++j)
			{
				temp[j] = counter[j];
			}
		}
		else
		{
			for (short j = el + 1; j < size; ++j)
			{
				temp[j - 1] = counter[j];
			}
		}
		short tempSize = 0;
		for (short i = 0; temp[i] != 0; ++i)
		{
			++tempSize;
		}
		if (IsTheCountEqual(temp, tempSize))
			return true;
	}
	return false;
}
bool IsTheCountEqual(const int arr[], const short size)
{
	for (int i = 1; i<size; ++i)
	{
		if (arr[i] != arr[i - 1])
		{
			return false;
		}
	}
	return true;
}