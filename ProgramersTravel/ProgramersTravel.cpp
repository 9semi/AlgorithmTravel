﻿#include "Level3.h"

using namespace std;

void ShowResult(vector<string> result)
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}

void ShowResult(vector<int> result)
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}

void ShowResult(int result)
{
	cout << result << endl;
}

void ShowResult(string result)
{
	cout << result << endl;
}

int main()
{
	Level1 L1;
	Level2 L2;
	Level3 L3;

	{
		vector<vector<int>> land = { {0, 0, 0, 1, 1, 1, 0, 0}, 
									{0, 0, 0, 0, 1, 1, 0, 0},
									{1, 1, 0, 0, 0, 1, 1, 0},
									{1, 1, 1, 0, 0, 0, 0, 0}, 
									{1, 1, 1, 0, 0, 0, 1, 1} };
		int result = L2.PCCPQuestion1(land);
		ShowResult(result);
	}
}



