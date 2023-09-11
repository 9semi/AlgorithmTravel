#include "Level1.h"
#include "Level2.h"

using namespace std;

void ShowResult(vector<string> datas)
{
	for (int i = 0; i < datas.size(); i++)
	{
		cout << datas[i] << " ";
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
		//vector<vector<int>> targets = { {4, 5},{4, 8},{10, 14},{11, 13},{5, 12},{3, 7},{1, 4} };
		//vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
		//vector<string> callings = { "kai", "kai", "mine", "mine" };
		//vector<string> result = L1.RunningRace(players, callings);
		//ShowResult(result);
	}
	{
		vector<int> numbers = { 4,1,2,1 };
		ShowResult(L2.TargetNumber(numbers, 4));
	}
}



