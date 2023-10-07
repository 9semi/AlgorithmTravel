#include "Level1.h"

using namespace std;

class Level2
{
public:
	struct RowCol
	{
		int row;
		int col;

		RowCol(int x, int y) : row(x), col(y) { }
	};

	int InterceptionSystem(vector<vector<int>> targets);
	int TargetNumber(vector<int> numbers, int target);
	int GameMapShortestDistance(vector<vector<int>> maps);
	vector<int> SumOfSuccessivePartialSequences(vector<int> sequence, int k);
	vector<int> DesertedIslandTrip(vector<string> maps);
	int MakeTheSumOfTheTwoQueuesEqual(vector<int> queue1, vector<int> queue2);
	int RicochetRobot(vector<string> board);
	int EscapeTheMaze(vector<string> maps);
	long long SeesawPartner(vector<int> weights);
	int MagicalElevator(int storey);
	int ConvertNumbers(int x, int y, int n);
	vector<int> FindALargeNumberAtTheBack(vector<int> numbers);
	long long Dot(int k, int d);
	vector<int> CheckDistancing(vector<vector<string>> places);
	int SkillTree(string skill, vector<string> skill_trees);
	int DiscountEvent(vector<string> want, vector<int> number, vector<string> discount);
};