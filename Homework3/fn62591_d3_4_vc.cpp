/**
*
* Solution to homework assignment 3
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
using namespace std;
short FindSize(char[], const short*);
bool Validation(char[], const short);
int PositionOfRepeat(char[], const short, const char);
int HowManyVariations(char[] , const short);
const short MAX_SIZE = 100;
int main()
{
	char arr[MAX_SIZE];
	cin.getline(arr, MAX_SIZE);
	const short size = FindSize(arr, &MAX_SIZE);
	if (Validation(arr, size)) return 0;
	cout << HowManyVariations(arr, size);
	return 0;
}
short FindSize(char arr[], const short* max_size)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		++i;
	}
	return i;
}
bool Validation(char arr[], const short size)
{
	if (size == 0)
	{
		cout << "-1";
		return true;
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (arr[i]<'A' || arr[i]>'z' || (arr[i]>'Z'&&arr[i]<'a'))
		{
			cout << "-1";
			return true;
		}
	}
	return false;
}
int PositionOfRepeat(char arr[], const short size, const char element)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == element)
		{
			return i;
		}
	}
	return -1;
}
int counterArr[MAX_SIZE] = {1, 1};
int HowManyVariations(char arr[], const short size)
{
	int counter;
	if (size <= 1) return 1;
	for (int i = 0; i < size; ++i)
	{
		int index = PositionOfRepeat(arr, i, arr[i]);
		if (index >= 0) counter = (2 * counterArr[i]) - counterArr[index];
		else counter = 2 * counterArr[i];
		counterArr[i+1] = counter;
	}
	return counter-1; //-1 because it counts the empty string also
}
