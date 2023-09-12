#include "Level2.h"

using namespace std;

int iAnswer = 0;
int TargetNumberBFS(vector<int> numbers, int target)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, numbers[0]));
	q.push(make_pair(0, -numbers[0]));

	while (!q.empty())
	{
		int count = q.front().first;
		int sum = q.front().second;
		q.pop();

		if (count == numbers.size() - 1)
		{
			if (sum == target)
			{
				iAnswer++;
			}
		}

		if (count < numbers.size() - 1)
		{
			q.push(make_pair(count + 1, sum + numbers[count + 1]));
			q.push(make_pair(count + 1, sum - numbers[count + 1]));
		}
	}
	return iAnswer;
}
void TargetNumberDFS(vector<int> numbers, int target, int count, int sum)
{
	if (count == numbers.size())
	{
		if (sum == target)
		{
			iAnswer++;
		}
		return;
	}
	TargetNumberDFS(numbers, target, count + 1, sum + numbers[count]);
	TargetNumberDFS(numbers, target, count + 1, sum - numbers[count]);
	return;
}

struct XY
{
	int x, y;

	XY(int iX, int iY) { x = iX; y = iY; }
};

int ny[4] = { 0, 1, 0, -1 };
int nx[4] = { -1, 0, 1 ,0 };

int GameMapShortestDistanceBFS(vector<vector<int>> maps)
{
	int iCount = 0;
	XY xy(0, 0);

	queue<XY> q;
	q.push(xy);

	vector<vector<bool>> visit;
	visit[0][0] = true;

	vector<vector<int>> distance;
	distance[0][0] = 1;

	int iMaxY = maps[0].size(); // 5
	int iMaxX = maps.size(); // 6

	while (!q.empty())
	{
		int iCurrentX = q.front().x;
		int iCurrentY = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int iNextX = iCurrentX + ny[i];
			int iNextY = iCurrentY + nx[i];

			if (iNextX < 0 && iNextX > iMaxY - 1 && iNextY < 0 && iNextY > iMaxX - 1)
				continue;

			if (maps[iNextX][iNextY] == 0)
				continue;

			if (visit[iNextX][iNextY])
				continue;

			XY temp(iNextX, iNextY);
			q.push(temp);
			visit[iNextX][iNextY] = true;
			distance[iNextX][iNextY] = distance[iCurrentX][iCurrentY] + 1;
		}
	}
	if (!visit[iMaxX - 1][iMaxY - 1])
		return -1;
	else
		return distance[iMaxX - 1][iMaxY - 1];

}

int Level2::InterceptionSystem(vector<vector<int>> targets)
{
	int iAnswer = 0;

	sort(targets.begin(), targets.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
		return a[0] < b[0];
		});

	sort(targets.begin(), targets.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
		return a[1] < b[1];
		});

	int s = INT16_MIN;
	int e = INT16_MIN;

	for (const auto& vec : targets)
	{
		if (e <= vec[0])
		{
			s = vec[0];
			e = vec[1];
			iAnswer++;
		}
	}

	return iAnswer;
}
int Level2::TargetNumber(vector<int> numbers, int target)
{
	//return TargetNumberBFS(numbers, target);
	TargetNumberDFS(numbers, 4, 0, 0);
	return iAnswer;
}
int Level2::GameMapShortestDistance(vector<vector<int>> maps)
{
	int iGoalPositionX = maps.size() - 1;
	int iGoalPositionY = maps[0].size() - 1;

	if (maps[iGoalPositionX - 1][iGoalPositionY] == 0 && maps[iGoalPositionX - 1][iGoalPositionY - 1] == 0 && maps[iGoalPositionX][iGoalPositionY - 1] == 0)
		return -1;
	else
		return GameMapShortestDistanceBFS(maps);
}


