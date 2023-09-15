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
int Level2::TargetNumber(vector<int> numbers, int target)
{
	//return TargetNumberBFS(numbers, target);
	TargetNumberDFS(numbers, 4, 0, 0);
	return iAnswer;
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

int addRow[4] = { -1, 0, 1, 0 };
int addCol[4] = { 0, 1, 0 , -1 };
struct RowCol
{
	int row, col;

	RowCol(int iRow, int iCol) { row = iRow; col = iCol; }
};
int GameMapShortestDistanceBFS(vector<vector<int>> maps)
{
	RowCol rc(0, 0);

	queue<RowCol> q;
	q.push(rc);

	int iMaxRow = maps.size();
	int iMaxCol = maps[0].size();

	vector<vector<bool>> visit(iMaxRow, vector<bool>(iMaxCol));
	visit[0][0] = true;

	vector<vector<int>> distance(iMaxRow, vector<int>(iMaxCol));
	distance[0][0] = 1;

	while (!q.empty())
	{
		int iCurrentRow = q.front().row;
		int iCurrentCol = q.front().col;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int iNextRow = iCurrentRow + addRow[i];
			int iNextCol = iCurrentCol + addCol[i];

			if (iNextRow < 0 
				|| iNextRow > iMaxRow - 1
				|| iNextCol < 0
				|| iNextCol > iMaxCol - 1)
				continue;

			if (maps[iNextRow][iNextCol] == 0)
				continue;

			if (visit[iNextRow][iNextCol])
				continue;

			RowCol temp(iNextRow, iNextCol);
			q.push(temp);
			visit[iNextRow][iNextCol] = true;
			distance[iNextRow][iNextCol] = distance[iCurrentRow][iCurrentCol] + 1;
		}
	}
	if (!visit[iMaxRow - 1][iMaxCol - 1])
		return -1;
	else
		return distance[iMaxRow - 1][iMaxCol - 1];

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
vector<int> Level2::SumOfSuccessivePartialSequences(vector<int> sequence, int k)
{
	vector<int> answer;

	int iStartPoint = 0;
	int iEndPoint = 0;
	int iMinLength = 1000001;
	int iSum = 0;

	for (int i = 0; i < sequence.size(); i++)
	{
		if (sequence[i] == k)
		{
			answer = { i, i };
			return answer;
		}
	}

	int i = 0;
	int j = 0;
	iSum = sequence[i];
	while (j <= i && i < sequence.size())
	{
		if (iSum < k)
		{
			i++;
			iSum += sequence[i];
		}
		else if (iSum > k)
		{
			iSum -= sequence[j];
			j++;
		}

		if (iSum == k)
		{
			if (iMinLength > (i - j))
			{
				iStartPoint = j;
				iEndPoint = i;
				iMinLength = i - j;
			}

			i++;
			if (i < sequence.size())
				iSum += sequence[i];

		}
	}

	answer = { iStartPoint, iEndPoint };
	return answer;
}

vector<int> answer;
bool bArrVisitPlace[101][101];
vector<int> iRow = { 0, 0, -1, 1 };
vector<int> iCol = { 1, -1, 0, 0 };
bool SearchRangeDistinction(vector<string> maps, int searchRow, int searchCol)
{
	if (searchRow >= maps.size()) return false;
	else if (searchRow < 0) return false;
	else if (searchCol >= maps[0].size()) return false;
	else if (searchCol < 0) return false;
	else if (maps[searchRow][searchCol] == 'X') return false;
	else if (bArrVisitPlace[searchRow][searchCol]) return false;
	else return true;
}
void DesertedIslandTripBFS(vector<string> maps, int currentRow, int currentCol)
{
	int sum = 0;
	queue<pair<int, int>> qBFS;
	qBFS.push({ currentRow, currentCol });
	bArrVisitPlace[currentRow][currentCol] = true;

	while (qBFS.size() > 0)
	{
		int x = qBFS.front().first;
		int y = qBFS.front().second;

		sum += maps[x][y] - '0';
		qBFS.pop();

		for (int i = 0; i < 4; i++)
		{
			int searchRow = x + iRow[i];
			int searchCol = y + iCol[i];

			if (SearchRangeDistinction(maps, searchRow, searchCol))
			{
				bArrVisitPlace[searchRow][searchCol] = true;
				qBFS.push({ searchRow, searchCol });
			}
		}
	}

	answer.push_back(sum);
}
vector<int> Level2::DesertedIslandTrip(vector<string> maps)
{
	for (int i = 0; i < maps.size(); i++)
	{
		for (int k = 0; k < maps[i].size(); k++)
		{
			if (maps[i][k] != 'X' && !bArrVisitPlace[i][k])
			{
				DesertedIslandTripBFS(maps, i, k);
			}
		}
	}

	if (answer.size() <= 0)
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());

	return answer;
}

int Level2::MakeTheSumOfTheTwoQueuesEqual(vector<int> queue1, vector<int> queue2)
{
	int answer = 0;
	unsigned int iSumQueue1 = 0;
	unsigned int iSumQueue2 = 0;
	int iTemp = 0;
	int iLimitCount = queue1.size() * 4;

	queue<int> qQueue1;
	queue<int> qQueue2;

	for (int i = 0; i < queue1.size(); i++)
	{
		iSumQueue1 += queue1[i];
		iSumQueue2 += queue2[i];
		qQueue1.push(queue1[i]);
		qQueue2.push(queue2[i]);
	}

	while (iSumQueue1 != iSumQueue2)
	{
		if (answer > iLimitCount)
			return -1;

		if (iSumQueue1 > iSumQueue2)
		{
			iTemp = qQueue1.front();
			qQueue1.pop();
			qQueue2.push(iTemp);

			iSumQueue1 -= iTemp;
			iSumQueue2 += iTemp;

			answer++;
		}
		else
		{
			iTemp = qQueue2.front();
			qQueue2.pop();
			qQueue1.push(iTemp);

			iSumQueue2 -= iTemp;
			iSumQueue1 += iTemp;

			answer++;
		}
	}

	return answer;
}

