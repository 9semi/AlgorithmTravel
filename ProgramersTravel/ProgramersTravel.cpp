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
		int k = 5;
		int m = 10;
		vector<int> score = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		int result = L1.FruitVendor(k, m, score);
		ShowResult(result);
	}
}



