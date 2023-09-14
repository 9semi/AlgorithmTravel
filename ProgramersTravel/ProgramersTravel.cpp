#include "Level1.h"
#include "Level2.h"

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

	{
		vector<int> q1 = { 3,2,7,2 };
		vector<int> q2 = { 4,6,5,1 };
		int result = L2.MakeTheSumOfTheTwoQueuesEqual(q1, q2);
		ShowResult(result);
	}
}



