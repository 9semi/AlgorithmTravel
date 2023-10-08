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
		vector<int> fees = { 180, 5000, 10, 600 };
		vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
			"07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
		vector<int> result = L2.CalculatingParkingFees(fees, records);
		ShowResult(result);
	}
}



