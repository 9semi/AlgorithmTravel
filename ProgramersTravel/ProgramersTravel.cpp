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
		//vector<vector<int>> targets = { {4, 5},{4, 8},{10, 14},{11, 13},{5, 12},{3, 7},{1, 4} };
		//vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
		//vector<string> callings = { "kai", "kai", "mine", "mine" };
		//vector<string> result = L1.RunningRace(players, callings);
		//ShowResult(result);
	}
	{
		//vector<int> numbers = { 4,1,2,1 };
		//ShowResult(L2.TargetNumber(numbers, 4));
	}
	{
		//vector<string> name = { "may", "kein", "kain", "radi" };
		//vector<int> yearning = { 5, 10, 1, 3 };
		//vector<vector<string>> photo = { {"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"},{"kon", "kain", "may", "coni"} };
		//vector<int> result = L1.MemoryScore(name, yearning, photo);
		//ShowResult(result);
	}
	{
		vector<vector<int>> maps = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1},{0, 0, 0, 0, 1} };
		//vector<vector<int>> maps = { {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1} };
		int result = L2.GameMapShortestDistance(maps);
		ShowResult(result);
	}

}



