/**
*
* Solution to homework assignment 3
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
#include <fstream>
using namespace std;
short FindSize(char[], const short*);
char FindCode(char[], const short);
bool Validation(char[], const short);
int main()
{
	ifstream myFile("message.txt");
	if (!myFile.is_open())
	{
		cout << "-2";
		return 0;
	}
	const short MAX_SIZE = 151;
	char arr[MAX_SIZE];
	while (myFile.get(arr, MAX_SIZE, '\n'))
	{
		myFile.ignore(874, '\n');
		short size = FindSize(arr, &MAX_SIZE);
		if (Validation(arr, size))
		{	
			myFile.close();
			cout << "-1";
			return 0;
		}
		cout << FindCode(arr, size);
	}
	myFile.close();
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
char FindCode(char arr[], const short size)
{
	char smallest = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
		}
	}
	char code;
	if (smallest == 'z')
	{
		code = '.';
		return code;
	}
	else if (smallest == 'Z') code = 'a';
	else
	{
		code = smallest + 1;
	}
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == code) {
			code += 1;
			i = -1;
		}
	}
	return code;
}
bool Validation(char arr[], const short size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (arr[i]<'A' || (arr[i]>'Z' && arr[i]<'a') || arr[i]>'z')
		{
			return true;
		}
	}
	return false;
}