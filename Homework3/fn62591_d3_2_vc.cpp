/**
*
* Solution to homework assignment 3
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
short FindSize(char[], const short*);
bool Validation(char[], const short);
bool IsTheThirdSumOfTheOthers(char[], const short, char[], const short, char[], const short);
bool IsArrayInThird(char[], const short, char[], const short);
int main()
{
	const short MAX_SIZE = 151;
	char arr1[MAX_SIZE];
	char arr2[MAX_SIZE];
	char arr3[MAX_SIZE];
	cin.getline(arr1, MAX_SIZE);
	short arr1Size = FindSize(arr1, &MAX_SIZE);
	if (Validation(arr1, arr1Size)) return 0;
	cin.getline(arr2, MAX_SIZE);
	short arr2Size = FindSize(arr2, &MAX_SIZE);
	if (Validation(arr2, arr2Size)) return 0;
	cin.getline(arr3, MAX_SIZE);
	short arr3Size = FindSize(arr3, &MAX_SIZE);
	if (Validation(arr3, arr3Size)) return 0;
	cout << IsTheThirdSumOfTheOthers(arr1, arr1Size, arr2, arr2Size, arr3, arr3Size);
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
		if (arr[i]<'a' || arr[i]>'z')
		{
			cout << "-1";
			return true;
		}
	}
	return false;
}
bool IsTheThirdSumOfTheOthers(char arr1[], const short arr1_size, char arr2[], const short arr2_size, char sum_arr[], const short sum_arr_size)
{
	if ((arr1_size + arr2_size) != sum_arr_size) return false; //If the length is not the same, obviously the arrays are not equal. 
	return IsArrayInThird(arr1, arr1_size, sum_arr, sum_arr_size) && IsArrayInThird(arr2, arr2_size, sum_arr, sum_arr_size);
}
bool IsArrayInThird(char arr[], const short arr_size, char sum_arr[], const short sum_arr_size)
{
	bool isItAtTheBeginning = true;
	bool isItInTheEnd = true;
	for (short i = 0; i < arr_size; ++i)
	{
		isItAtTheBeginning = false;
		for (short j = 0; j < arr_size; ++j)
		{
			if (sum_arr[i] == arr[j]) isItAtTheBeginning = true;
		}
		if (!isItAtTheBeginning) break; //If there is an element of the array that is not in the first arr_size elements of the summary array then break
	}
	if (isItAtTheBeginning) return true; //all elements of the array contain at the beginning of the summary array
	else
	{
		for (short i = sum_arr_size - arr_size; i < sum_arr_size; ++i)
		{
			isItInTheEnd = false;
			for (short j = 0; j < arr_size; ++j)
			{
				if (sum_arr[i] == arr[j]) isItInTheEnd = true;
			}
			if (!isItInTheEnd) break; //If there is an element of the array that is not in the last arr_size elements of the summary array then break
		}
	}
	if (isItInTheEnd) return true; //all elements of the array contain in the end of the summary array
	return false; //the array does not contain in the summary array
}