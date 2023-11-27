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
	vector<int> CalculatingParkingFees(vector<int> fees, vector<string> records); 
	int LengthOfVisit(string dirs);
	vector<string> ConductingAProject(vector<vector<string>> plans);
	int HotelRoom(vector<vector<string>> book_time);
	int RotatingParentheses(string s);
	vector<int> RotatingMatrixBorders(int rows, int columns, vector<vector<int>> queries);
	int GameMapShortestDistance(vector<vector<int> > maps);
	int PickTangerine(int k, vector<int> tangerine);
	vector<string> OpenChatRoom(vector<string> record);
	int DefenseGame(int n, int k, vector<int> enemy);
	int CutRollCake(vector<int> topping);
	int Fatigability(int k, vector<vector<int>> dungeons);
	int Lifeboat(vector<int> people, int limit);
	string MakingLargeNumber(string number, int k);
	int SumOfContinuousSequence(vector<int> elements);
	int ParcelBox(vector<int> order);	
	int ShareTheNumberCards(vector<int> arrayA, vector<int> arrayB);
	int FindDecimalCountsOfDecimal(int n, int k);
	int StringCompression(string s);
	int FindPrimeNumbers(string numbers);
	int PCCPQuestion1(vector<vector<int>> land);
};