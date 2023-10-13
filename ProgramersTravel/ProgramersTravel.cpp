#include "Level3.h"

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

int main()
{
	Level1 L1;
	Level2 L2;
	Level3 L3;

	{
		int rows = 6;
		int columns = 6;
		vector<vector<int>> queries = { {2,2,5,4},{3,3,6,6},{5,1,6,3} };
		vector<int> result = L2.RotatingMatrixBorders(rows, columns, queries);
		ShowResult(result);
	}
}



