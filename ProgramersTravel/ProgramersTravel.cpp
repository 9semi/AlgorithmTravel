#include "Level2.h"

using namespace std;

int main()
{
	Level2 L2;
	vector<vector<int>> targets = { {4, 5},{4, 8},{10, 14},{11, 13},{5, 12},{3, 7},{1, 4} };
	cout<<L2.InterceptionSystem(targets);
}
