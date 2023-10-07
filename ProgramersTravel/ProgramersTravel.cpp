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
		vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
		vector<int> number = { 3, 2, 2, 2, 1 };
		vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
		int result = L2.DiscountEvent(want, number, discount);
		ShowResult(result);
	}
}



