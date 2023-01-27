/**
*
* Solution to homework assignment 4
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
#include <vector>
using namespace std;
struct Position
{
	short x;
	short y;
	Position(const short x, const short y) : x(x), y(y) {}
};

void ValidateAndAdd(const short&, const short&, const short&, const short&, vector<Position>&, Position&);
bool IsThePositionAccessible(const short&, const short&, const short&, const short&, const short&, const short&, const short&);
void AddElementsToNewPositionsVector(vector<Position>&, vector<Position>&, const short&, const short&, short = 0);
bool IsItNew(vector<Position>&, const Position&);

int main()
{
	short N, M;
	cin >> N;
	if (N < 3 || N>200)
	{
		cout << "-1";
		return 0;
	}
	cin >> M;
	if (M < 3 || M>200)
	{
		cout << "-1";
		return 0;
	}
	short p, q;
	cin >> p;
	if (p < 0 || p >= N)
	{
		cout << "-1";
		return 0;
	}
	cin >> q;
	if (q < 0 || q >= M)
	{
		cout << "-1";
		return 0;
	}
	short p1, q1;
	cin >> p1;
	if (p1 < 0 || p1 >= N)
	{
		cout << "-1";
		return 0;
	}
	cin >> q1;
	if (q1 < 0 || q1 >= M)
	{
		cout << "-1";
		return 0;
	}
	short k;
	cin >> k;
	if (k < 0 || k>30)
	{
		cout << "-1";
		return 0;
	}
	if (p == p1 && q == q1)
	{
		cout << "true";
		return 0;
	}
	if (IsThePositionAccessible(p, q, p1, q1, k, N, M)) cout << "true";
	else cout << "false";
	return 0;
}

void ValidateAndAdd(const short& x, const short& y, const short& N, const short& M, vector<Position>& newPositions, Position& newPosition)
{
	if (x >= 0 && x < N && y >= 0 && y < M)
	{
		newPosition.x = x;
		newPosition.y = y;
		if(IsItNew(newPositions, newPosition)) newPositions.push_back(newPosition);
	}
}
bool IsItNew(vector<Position>& currentVecotor, const Position& element)
{
	for (short b = 0; b < currentVecotor.size(); ++b)
	{
		if (currentVecotor[b].x == element.x && currentVecotor[b].y == element.y)
		{
			return false;
		}
	}
	return true;
}

bool IsThePositionAccessible(const short& p, const short& q, const short& p1, const short& q1, const short& k, const short& N, const short& M)
{
	vector <Position> allPositions;
	vector <Position> previousPositions;
	vector <Position> newPositions;
	Position start = { p, q };
	Position wanted = { p1, q1 };
	previousPositions.push_back(start);
	allPositions.push_back(start);
	for (short i = 0; i < k; ++i)
	{
		AddElementsToNewPositionsVector(previousPositions, newPositions, N, M);
		for (short a = 0; a < previousPositions.size(); ++a)
		{
			if (IsItNew(allPositions, previousPositions[a]))
			{
				allPositions.push_back(previousPositions[a]);
			}
		}
		previousPositions.clear();
		for (short a = 0; a < newPositions.size(); ++a)
		{
			previousPositions.push_back(newPositions[a]);
		}
		newPositions.clear();
	}
	for (short a = 0; a < previousPositions.size(); ++a)
	{
		bool sreshtase = false;
		for (short b = 0; b < allPositions.size(); ++b)
		{
			if (allPositions[b].x == previousPositions[a].x && allPositions[b].y == previousPositions[a].y)
			{
				sreshtase = true;
				break;
			}
		}
		if (!sreshtase)
		{
			allPositions.push_back(previousPositions[a]);
		}
	}
	previousPositions.clear();
	for (int i = 0; i < allPositions.size(); ++i)
	{
		if (allPositions[i].x == wanted.x && allPositions[i].y == wanted.y)
		{
			return true;
		}
	}
	return false;
}

void AddElementsToNewPositionsVector(vector<Position>& previousPositions, vector<Position>& newPositions, const short& N, const short& M, short i)
{
	//for (short j = 0; j < previousPositions.size(); ++j)
	//{
	if (i == previousPositions.size()) return;
		Position newPosition = { 0, 0 };
		short x, y;
		x = previousPositions[i].x + 2;
		y = previousPositions[i].y + 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		y = previousPositions[i].y - 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		y = previousPositions[i].y + 2;
		x = previousPositions[i].x + 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		x = previousPositions[i].x - 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		x = previousPositions[i].x - 2;
		y = previousPositions[i].y + 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		y = previousPositions[i].y - 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		y = previousPositions[i].y - 2;
		x = previousPositions[i].x + 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		x = previousPositions[i].x - 1;
		ValidateAndAdd(x, y, N, M, newPositions, newPosition);
		return AddElementsToNewPositionsVector(previousPositions, newPositions, N, M, i + 1);
	//}
}