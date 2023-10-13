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

//                    →  ←   ↑  ↓
vector<int> iAddX = { 0, 0, 1, -1 };
vector<int> iAddY = { 1, -1, 0, 0 };
int Level2::RicochetRobot(vector<string> board)
{
	int iStartX = -1, iStartY = -1;
	int iGoalX, iGoalY;

	for (int i = 0; i < board.size(); i++)
	{
		for (int k = 0; k < board[0].size(); k++)
		{
			if (board[i][k] == 'R')
			{
				iStartX = i;
				iStartY = k;
				break;
			}
		}

		if (iStartX != -1)
			break;
	}
	queue<pair<int, int>> q;
	q.push({ iStartX, iStartY });

	queue<int> qCount;
	qCount.push(0);

	int visit[100][100] = { 0, };

	while (!q.empty())
	{
		int iMaxX = board.size();
		int iMaxY = board[0].size();
		int iCurrentX = q.front().first;
		int iCurrentY = q.front().second;
		int iCurrentCount = qCount.front();

		q.pop();
		qCount.pop();

		if (board[iCurrentX][iCurrentY] == 'G')
		{
			return iCurrentCount;
		}

		// 순서 : 오, 왼, 위, 아
		for (int i = 0; i < 4; i++)
		{
			int tempX = iCurrentX;
			int tempY = iCurrentY;
		
			if (iAddX[i] != 0)
			{
				while (tempX > -1 && tempX < iMaxX && board[tempX][iCurrentY] != 'D')
				{
					tempX += iAddX[i];
				}

				if (visit[tempX - iAddX[i]][iCurrentY] == 0)
				{
					visit[tempX - iAddX[i]][iCurrentY] = 1;
					q.push({ tempX - iAddX[i], iCurrentY });
					qCount.push(iCurrentCount + 1);
				}
			}
			else if (iAddY[i] != 0)
			{
				while (tempY > -1 && tempY < iMaxY && board[iCurrentX][tempY] != 'D')
				{
					tempY += iAddY[i];
				}

				if (visit[iCurrentX][tempY - iAddY[i]] == 0)
				{
					visit[iCurrentX][tempY - iAddY[i]] = 1;
					q.push({ iCurrentX, tempY - iAddY[i] });
					qCount.push(iCurrentCount + 1);
				}
			}
		}
	}
	return -1;
}

int EscapeTheMazeBFS(vector<string> maps, char startWord, char targetWord)
{
	int iStartX = -1, iStartY = -1;

	for (int i = 0; i < maps.size(); i++)
	{
		for (int k = 0; k < maps[0].size(); k++)
		{
			if (maps[i][k] == startWord)
			{
				iStartX = i; iStartY = k;
				break;
			}
		}
		if (iStartX > -1)
			break;
	}

	int iMaxX = maps.size();
	int iMaxY = maps[0].size();

	queue<tuple<int, int, int>> q;
	int visit[100][100] = { 0, };

	q.push({ iStartX, iStartY, 0 });

	while (!q.empty())
	{
		int iCurrentX = get<0>(q.front());
		int iCurrentY = get<1>(q.front());
		int iCurrentCount = get<2>(q.front());
		q.pop();

		if (maps[iCurrentX][iCurrentY] == targetWord)
		{
			return iCurrentCount;
		}

		for (int i = 0; i < 4; i++)
		{
			int newX = iCurrentX + iAddX[i];
			int newY = iCurrentY + iAddY[i];

			if (newX >= iMaxX || newX < 0 || newY >= iMaxY || newY < 0)
				continue;
			if (maps[newX][newY] == 'X')
				continue;
			if (visit[newX][newY] == 1)
				continue;

			q.push({ newX, newY, iCurrentCount + 1 });
			visit[iCurrentX][iCurrentY] = 1;
		}
	}
	return -1;
}
int Level2::EscapeTheMaze(vector<string> maps)
{
	int iFindL = EscapeTheMazeBFS(maps, 'S', 'L');
	int iFindE = EscapeTheMazeBFS(maps, 'L', 'E');

	if (iFindL < 0 || iFindE < 0)
		return -1;
	else
		return iFindE + iFindL;
}

long long  Level2::SeesawPartner(vector<int> weights)
{
	int iWeightsLengh = weights.size();
	vector<int> vecDistance = { 2,3,4 };
	long long answer = 0;
	map<int, int> mWeight;
	map<int, int> mSameWeightCount;

	for (int i = 0; i < iWeightsLengh; i++)
	{
		if (mSameWeightCount.count(weights[i]) > 0)
		{
			answer -= mSameWeightCount[weights[i]] * 2;
			mSameWeightCount[weights[i]] += 1;
		}
		else
		{
			mSameWeightCount.insert(make_pair(weights[i], 1));
		}

		for (int k = 0; k < 3; k++)
		{
			int iKey = weights[i] * vecDistance[k];

			if (mWeight.count(iKey) > 0)
			{
				int value = mWeight[iKey];

				answer += value;
				mWeight[iKey] = value + 1;
			}
			else
			{
				mWeight.insert(make_pair(iKey, 1));
			}
		}
	}
	return answer;
}

int Level2::MagicalElevator(int storey)
{
	vector<int> vResult;
	queue<vector<int>> q;
	q.push({ storey, 0 });

	while (!q.empty())
	{
		vector<int> temp = q.front();

		int currentStorey = temp[0];
		int currentCount = temp[1];
		q.pop();

		if (currentStorey == 0)
		{
			vResult.push_back(currentCount);
			continue;
		}

		int rest = currentStorey % 10;
		
		if (rest == 0)
		{
			q.push({ currentStorey / 10, currentCount });
			continue;
		}

		if (rest > 5)
		{
			currentStorey += 10 - rest;
			q.push({ currentStorey, currentCount + (10 - rest)});
		}
		else if (rest < 5)
		{
			currentStorey -= rest;
			q.push({ currentStorey, currentCount + rest });
		}
		else
		{
			q.push({ currentStorey + rest, currentCount + rest });
			q.push({ currentStorey - rest, currentCount + rest });
		}
	}

	sort(vResult.begin(), vResult.end());
	return vResult[0];
}

int Level2::ConvertNumbers(int x, int y, int n)
{
	queue<vector<int>> q;
	map<int, int> m;

	q.push({ x, 0 });
	m.insert({ x, 1 });

	while (!q.empty())
	{
		vector<int> temp = q.front();
		q.pop();
		
		if (temp[0] == y)
		{
			return temp[1];
		}
		else if (temp[0] > y)
		{
			continue;
		}

		int iCurrentX = temp[0];

		if (m.count(iCurrentX + n) == 0)
		{
			q.push({ iCurrentX + n, temp[1] + 1 });
			m.insert({ iCurrentX + n, 1 });
		}
			
		if (m.count(iCurrentX * 2) == 0)
		{
			q.push({ iCurrentX * 2, temp[1] + 1 });
			m.insert({ iCurrentX * 2, 1 });
		}

		if (m.count(iCurrentX * 3) == 0)
		{
			q.push({ iCurrentX * 3, temp[1] + 1 });
			m.insert({ iCurrentX * 3, 1 });
		}
			
	}

	return -1;
}

vector<int> Level2::FindALargeNumberAtTheBack(vector<int> numbers)
{
	vector<int> tempVector;
	stack<int> tempStack;

	tempStack.push(numbers[numbers.size() - 1]);
	tempVector.push_back(-1);

	for (int i = numbers.size() - 2; i >= 0; i--)
	{
		int iTemp = -1;

		while (!tempStack.empty())
		{
			if (tempStack.top() > numbers[i])
			{
				iTemp = tempStack.top();
				break;
			}
			else
			{
				tempStack.pop();
			}
		}

		tempVector.push_back(iTemp);
		tempStack.push(numbers[i]);
	}

	reverse(tempVector.begin(), tempVector.end());

	return tempVector;
}

long long Level2::Dot(int k, int d)
{
	long long answer = 0;
	long long dd = pow(d, 2);

	for (int i = 0; i <= d; i += k)
	{
		long long xx = pow(i, 2);
		
		int yy = (int)sqrt(dd - xx);
		
		int temp = yy / k + 1;

		answer += temp;
	}

	return answer;
}

vector<int> Level2::CheckDistancing(vector<vector<string>> places)
{
	vector<int> answer;
	queue<Level2::RowCol> q;
	bool visit[5][5];

	for (int i = 0; i < places.size(); i++)
	{
		memset(visit, false, sizeof(visit));

		for (int k = 0; k < places[0].size(); k++)
		{
			string line = places[i][k];

			for (int n = 0; n < line.size(); n++)
			{
				if (line[n] == 'P')
				{
					q.push(Level2::RowCol(k,n));
				}
			}
		}

		while (!q.empty())
		{
			Level2::RowCol rc = q.front(); q.pop();
			visit[rc.row][rc.col] = true;

			for (int m = 0; m < 4; m++)
			{
				int newRow = rc.row + iAddX[m];
				int newCol = rc.col + iAddY[m];

				if (newRow < 0 || newCol < 0 || newRow > 4 || newCol > 4 || visit[newRow][newCol] || places[i][newRow][newCol] == 'X')
				{
					continue;
				}
				else if(places[i][newRow][newCol] == 'P')
				{
					visit[newRow][newCol] = true;
					answer.push_back(0);

					while (!q.empty())
					{
						q.pop();
					}
					break;
				}
				else  // == 'O'
				{
					for (int j = 0; j < 4; j++)
					{
						int newnewRow = newRow + iAddX[j];
						int newnewCol = newCol + iAddY[j];

						if (newnewRow < 0 || newnewCol < 0 || newnewRow > 4 || newnewCol > 4 || visit[newnewRow][newnewCol])
						{
							continue;
						}
						else if (places[i][newnewRow][newnewCol] == 'P')
						{
							visit[newnewRow][newnewCol] = true;
							answer.push_back(0);
							m = 4;

							while (!q.empty())
							{
								q.pop();
							}
							break;
						}
					}
				}
			}
		}

		if(i == answer.size())
			answer.push_back(1);
	}
	return answer;
}

int Level2::SkillTree(string skill, vector<string> skill_trees)
{
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		bool bIsIncrease = true;
		vector<char> vecTemp;
		int iCount = 0;

		for (int k = 0; k < skill_trees[i].length(); k++)
		{
			vecTemp.push_back(skill_trees[i][k]);
		}

		while (vecTemp.size() > 0)
		{
			int iTemp = skill.find(vecTemp[0]);

			if (vecTemp[0] == skill[iCount])
			{
				vecTemp.erase(vecTemp.begin());
				iCount++;
			}
			else if (iTemp > 0)
			{
				bIsIncrease = false;
				break;
			}
			else
			{
				vecTemp.erase(vecTemp.begin());
			}
		}

		if (bIsIncrease)
			answer++;
	}

	return answer;
}

int Level2::DiscountEvent(vector<string> want, vector<int> number, vector<string> discount)
{
	int answer = 0;
	map<string, int> m;

	for (int i = 0; discount.size() - i >= 10 ; i++)
	{
		m.clear();

		for (int j = 0; j < want.size(); j++)
		{
			m.insert(pair<string, int>(want[j], number[j]));
		}

		int iEndCount = 0;

		for (int k = i; iEndCount < 10; k++, iEndCount++)
		{
			auto data = m.find(discount[k]);

			if (data != m.end())
			{
				// 찾음
				m[discount[k]]--;

				if (m[discount[k]] <= 0)
				{
					m.erase(discount[k]);
				}
			}
		}

		if (m.empty())
			answer++;
	}

	return answer;
}

int CalculateFee(int iTotalTime, vector<int> fees)
{
	int iFee;

	if (iTotalTime > fees[0])
	{
		int iTemp = ceil(static_cast<float>(iTotalTime - fees[0]) / fees[2]);
		iFee = iTemp * fees[3] + fees[1];
	}
	else
	{
		iFee = fees[1];
	}

	return iFee;
}
int CalculateTime(string hour_minute)
{
	istringstream iss(hour_minute);
	string strHour, strMinute;

	getline(iss, strHour, ':');
	getline(iss, strMinute);

	int iHour = stoi(strHour);
	int iMinute = stoi(strMinute);


	int iTemp = (iHour * 60) + iMinute;

	return iTemp;
}
vector<int> Level2::CalculatingParkingFees(vector<int> fees, vector<string> records)
{
	vector<int> answer;
	vector<int> vecCarNumber;
	map<int, int> carNumber_calculate;
	map<int, int> carNumber_totalTime;

	for (int i = 0; i < records.size(); i++)
	{
		istringstream iss(records[i]);
		string str;
		vector<string> stringVector;

		while (iss >> str)
		{
			stringVector.push_back(str);
		}

		auto it1 = carNumber_calculate.find(stoi(stringVector[1]));

		int iTime = CalculateTime(stringVector[0]);
		int iCarNumber = stoi(stringVector[1]);

		// 계산맵, 해당 키가 없음 : 추가한다.
		if (it1 == carNumber_calculate.end()) 
		{
			carNumber_calculate.insert(pair<int, int>(iCarNumber, iTime));

			auto it2 = find(vecCarNumber.begin(), vecCarNumber.end(), iCarNumber);

			if(it2 == vecCarNumber.end())
				vecCarNumber.push_back(iCarNumber);
		}
		// 계산맵, 해당 키가 있음 : 기존 시간에 부가한다.
		else
		{
			int iInTime = carNumber_calculate[iCarNumber];
			int iTimeOfUse = iTime - iInTime;

			carNumber_calculate.erase(iCarNumber);

			auto it2 = carNumber_totalTime.find(iCarNumber);

			// 정보맵, 해당 차 번호 키가 없음 : 추가한다.
			if (it2 == carNumber_totalTime.end())
			{
				carNumber_totalTime.insert(pair<int, int>(iCarNumber, iTimeOfUse));
			}
			// 정보맵, 해당 차 번호 키가 있음 : 
			else
			{
				carNumber_totalTime[iCarNumber] += iTimeOfUse;
			}
		}
	}

	for (const auto& data : carNumber_calculate)
	{
		int iTimeOfUse = CalculateTime("23:59") - data.second;

		auto it = carNumber_totalTime.find(data.first);

		// 정보맵, 해당 차 번호 키가 없음 : 추가한다.
		if (it == carNumber_totalTime.end())
		{
			carNumber_totalTime.insert(pair<int, int>(data.first, iTimeOfUse));
		}
		// 정보맵, 해당 차 번호 키가 있음 : 
		else
		{
			carNumber_totalTime[data.first] += iTimeOfUse;
		}
	}

	sort(vecCarNumber.begin(), vecCarNumber.end());

	for (int i = 0; i < vecCarNumber.size(); i++)
	{
		answer.push_back(CalculateFee(carNumber_totalTime[vecCarNumber[i]], fees));
	}

	return answer;
}

struct stPoint
{
	int X;
	int Y;

	stPoint(int x, int y) : X(x), Y(y) { }
};
enum eDirection
{
	R,
	L,
	U,
	D
};
bool IsNewWay(vector<string>& visitCheck, stPoint stCurrentPoint, stPoint stNewPoint, char dir)
{
	bool bIsNewWay = false;
	string strTemp1 = to_string(stCurrentPoint.X) + to_string(stCurrentPoint.Y) + dir;
	auto it = find(visitCheck.begin(), visitCheck.end(), strTemp1);

	if (it == visitCheck.end())
	{
		string strTemp2;

		switch (dir)
		{
		case 'R':
			strTemp2 = to_string(stNewPoint.X) + to_string(stNewPoint.Y) + 'L';
			break;
		case 'L':
			strTemp2 = to_string(stNewPoint.X) + to_string(stNewPoint.Y) + 'R';
			break;
		case 'U':
			strTemp2 = to_string(stNewPoint.X) + to_string(stNewPoint.Y) + 'D';
			break;
		case 'D':
			strTemp2 = to_string(stNewPoint.X) + to_string(stNewPoint.Y) + 'U';
			break;
		}

		visitCheck.push_back(strTemp1);
		visitCheck.push_back(strTemp2);
		bIsNewWay = true;
	}

	return bIsNewWay;
}
eDirection charToDirection(char c)
{
	switch (c)
	{
	case 'R':
		return R;
	case 'L':
		return L;
	case 'U':
		return U;
	case 'D':
		return D;
	default:
		return R;
	}
}
int Level2::LengthOfVisit(string dirs)
{
	int answer = 0;
	stPoint stCurrentPoint = stPoint(0, 0);
	vector<string> visitCheck;

	for (int i = 0; i < dirs.size(); i++)
	{
		int addX = iAddX[charToDirection(dirs[i])];
		int addY = iAddY[charToDirection(dirs[i])];

		int newX = stCurrentPoint.X + addX;
		int newY = stCurrentPoint.Y + addY;

		stPoint newPoint = stPoint(newX, newY);

		if (newX < -5 || newY < -5 || newX > 5 || newY > 5)
		{
			continue;
		}
		else
		{
			if (IsNewWay(visitCheck, stCurrentPoint, newPoint, dirs[i]))
				answer++;

			stCurrentPoint = newPoint;
		}
	}
	return answer;
}

bool CompareTime(const vector<string>& a, vector<string>& b) 
{
	return a[1] < b[1]; 
}
vector<string> Level2::ConductingAProject(vector<vector<string>> plans)
{
	sort(plans.begin(), plans.end(), CompareTime);

	vector<string> answer;
	stack<vector<string>> remainingProject;
	int iCurrentTime = CalculateTime(plans[0][1]);

	while (!plans.empty())
	{
		if (iCurrentTime < CalculateTime(plans[0][1]))
		{
			if (remainingProject.empty())
			{
				iCurrentTime = CalculateTime(plans[0][1]);

				if (plans.size() > 1)
				{
					int iTimeSum = stoi(plans[0][2]) + iCurrentTime;
					int iTimeDifference = CalculateTime(plans[1][1]) - iCurrentTime;

					if (iCurrentTime + iTimeDifference >= iTimeSum)
					{
						iCurrentTime = iTimeSum;
						answer.push_back(plans[0][0]);
						plans.erase(plans.begin());
					}
					else
					{
						vector<string> vecTemp = plans[0];
						int iTemp = stoi(vecTemp[2]);
						iTemp -= iTimeDifference;
						iCurrentTime += iTimeDifference;
						vecTemp[2] = to_string(iTemp);
						remainingProject.push(vecTemp);
						plans.erase(plans.begin());
					}
				}
				else
				{
					answer.push_back(plans[0][0]);
					plans.erase(plans.begin());
				}
			}
			else
			{
				vector<string> vecTemp = remainingProject.top(); remainingProject.pop();
				int iTimeSum = iCurrentTime + stoi(vecTemp[2]);
				int iTimeDifference = CalculateTime(plans[0][1]) - iCurrentTime;

				if (iCurrentTime + iTimeDifference >= iTimeSum)
				{
					iCurrentTime = iTimeSum;
					answer.push_back(vecTemp[0]);
				}
				else
				{
					int iTemp = stoi(vecTemp[2]);
					iTemp -= iTimeDifference;
					iCurrentTime += iTimeDifference;
					vecTemp[2] = to_string(iTemp);
					remainingProject.push(vecTemp);
				}
			}
		}
		else
		{
			if (plans.size() > 1)
			{
				int iTimeSum = stoi(plans[0][2]) + iCurrentTime;
				int iTimeDifference = CalculateTime(plans[1][1]) - iCurrentTime;

				if (iCurrentTime + iTimeDifference >= iTimeSum)
				{
					iCurrentTime = iTimeSum;
					answer.push_back(plans[0][0]);
					plans.erase(plans.begin());
				}
				else
				{
					vector<string> vecTemp = plans[0];
					int iTemp = stoi(vecTemp[2]);
					iTemp -= iTimeDifference;
					iCurrentTime += iTimeDifference;
					vecTemp[2] = to_string(iTemp);
					remainingProject.push(vecTemp);
					plans.erase(plans.begin());
				}
			}
			else
			{
				answer.push_back(plans[0][0]);
				plans.erase(plans.begin());
			}
		}
	}

	while (!remainingProject.empty())
	{
		vector<string> vecTemp = remainingProject.top(); remainingProject.pop();

		answer.push_back(vecTemp[0]);
	}

	return answer;
}

bool CompareTime2(const vector<string>& a, vector<string>& b)
{
	return a[0] < b[0];
}
int Level2::HotelRoom(vector<vector<string>> book_time)
{
	sort(book_time.begin(), book_time.end(), CompareTime2);

	vector<int> vecClosingTime;
	vecClosingTime.push_back(CalculateTime(book_time[0][1]) + 10);
	book_time.erase(book_time.begin());


	while (!book_time.empty())
	{
		vector<string> vecTemp = book_time[0];
		book_time.erase(book_time.begin());

		int iCurrentCheckInTime = CalculateTime(vecTemp[0]);
		int iCurrentCheckOutTime = CalculateTime(vecTemp[1]);

		if (vecClosingTime[0] > iCurrentCheckInTime)
		{
			vecClosingTime.push_back(iCurrentCheckOutTime + 10);
		}
		else
		{
			vecClosingTime[0] = iCurrentCheckOutTime + 10;
		}

		sort(vecClosingTime.begin(), vecClosingTime.end());

	}
	
	return vecClosingTime.size();
}

string PullOneSpace(string s)
{
	char chTemp = s[0];
	s.erase(s.begin());
	s.push_back(chTemp);
	return s;
}
int Level2::RotatingParentheses(string s)
{
	int answer = 0;
	bool bIsLeft = false;
	char chCurrentParenthesis;

	stack<char> stackLeft;
	vector<char> vecLeft = { '(', '[', '{' };
	vector<char> vecRight = { ')', ']', '}' };
	map<char, char> mapParentheses;

	for (int i = 0; i < vecLeft.size(); i++) 
	{
		mapParentheses.insert(pair<char, char>(vecLeft[i], vecRight[i]));
	}

	for (int i = 0; i < s.size(); i++)
	{
		bool bIsComplete = true;

		for (int k = 0; k < s.size(); k++)
		{
			bIsLeft = false;
			chCurrentParenthesis = s[k];

			for (int n = 0; n < vecLeft.size(); n++)
			{
				if (chCurrentParenthesis == vecLeft[n])
				{
					bIsLeft = true;
					break;
				}
			}

			if (bIsLeft)
			{
				stackLeft.push(chCurrentParenthesis);
			}
			else
			{
				if (stackLeft.size() > 0)
				{
					char chTemp = stackLeft.top(); stackLeft.pop();

					if (mapParentheses[chTemp] == chCurrentParenthesis)
					{
						continue;
					}
					else
					{
						bIsComplete = false;
						s = PullOneSpace(s);
						k = s.size();
					}

				}
				else
				{
					bIsComplete = false;
					s = PullOneSpace(s);
					k = s.size();
				}
			}
		}
		if (stackLeft.empty())
		{
			if (bIsComplete)
			{
				s = PullOneSpace(s);
				answer++;
			}
		}
		else
		{
			while (!stackLeft.empty())
			{
				stackLeft.pop();
			}
		}
	}

	return answer;
}

vector<int> Level2::RotatingMatrixBorders(int rows, int columns, vector<vector<int>> queries)
{
	vector<int> answer;
	vector<vector<int>> vecBoard(rows, vector<int>(columns, 0));

	int iNumber = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < columns; k++)
		{
			vecBoard[i][k] = iNumber;
			iNumber++;
		}
	}

	for (int i = 0; i < queries.size(); i++)
	{
		vector<int> vecTemp = queries[i];
		vector<int> vecBorder;

		int row1 = vecTemp[0] - 1; // 2
		int row2 = vecTemp[2] - 1; // 5
		int col1 = vecTemp[1] - 1; // 2
		int col2 = vecTemp[3] - 1; // 4

		int iTemp = vecBoard[row1][col1];

		for (int k = row1 + 1; k <= row2; k++)
		{
			vecBorder.push_back(vecBoard[k][col1]);
			vecBoard[k - 1][col1] = vecBoard[k][col1];
		}

		for (int k = col1 + 1; k <= col2; k++)
		{
			vecBorder.push_back(vecBoard[row2][k]);
			vecBoard[row2][k - 1] = vecBoard[row2][k];
		}

		for (int k = row2 - 1; k >= row1; k--)
		{
			vecBorder.push_back(vecBoard[k][col2]);
			vecBoard[k + 1][col2] = vecBoard[k][col2];
		}

		for (int k = col2 - 1; k >= col1; k--)
		{
			vecBorder.push_back(vecBoard[row1][k]);
			vecBoard[row1][k + 1] = vecBoard[row1][k];
		}

		vecBorder.push_back(iTemp);
		vecBoard[row1][col1 + 1] = iTemp;

		sort(vecBorder.begin(), vecBorder.end());
		answer.push_back(vecBorder[0]);
	}
	
	return answer;
}