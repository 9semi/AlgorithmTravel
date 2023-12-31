#include "Level2.h"
using namespace std;

//                ↑   →  ↓  ←     
int addRow[4] = { -1, 0, 1, 0 };
int addCol[4] = { 0, 1, 0 , -1 };

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
	int iSum = 0;
	queue<pair<int, int>> qBFS;
	qBFS.push({ currentRow, currentCol });
	bArrVisitPlace[currentRow][currentCol] = true;

	while (qBFS.size() > 0)
	{
		int x = qBFS.front().first;
		int y = qBFS.front().second;

		iSum += maps[x][y] - '0';
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

	answer.push_back(iSum);
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
	bool visit[100][100] = { false, };
	int iStartRow = -1, iStartCol = -1;
	int iMaxRow = maps.size() - 1, iMaxCol = maps[0].size() - 1;
	int iCurrentRow, iCurrentCol, iCurrentCount;
	queue<vector<int>> qBFS;
	
	for (int i = 0; i < maps.size(); i++)
	{
		for (int k = 0; k < maps[0].size(); k++)
		{
			if (maps[i][k] == startWord)
			{
				iStartRow = i;
				iStartCol = k;
				i = maps.size();
				break;
			}
		}
	}  

	vector<int> vecTemp = { iStartRow, iStartCol, 0 };
	visit[iStartRow][iStartCol] = true;
	qBFS.push(vecTemp);

	while (!qBFS.empty())
	{
		vecTemp = qBFS.front(); qBFS.pop();
		iCurrentRow = vecTemp[0];
		iCurrentCol = vecTemp[1];
		iCurrentCount = vecTemp[2];

		if (maps[iCurrentRow][iCurrentCol] == targetWord)
		{
			return iCurrentCount;
		}

		for (int i = 0; i < 4; i++)
		{
			int iNewRow = iCurrentRow + addRow[i];
			int iNewCol = iCurrentCol + addCol[i];

			if (iNewRow < 0 || iNewCol < 0 || iNewRow > iMaxRow || iNewCol > iMaxCol)
				continue;
			if (maps[iNewRow][iNewCol] == 'X' || visit[iNewRow][iNewCol])
				continue;

			qBFS.push({ iNewRow, iNewCol, iCurrentCount + 1 });
			visit[iNewRow][iNewCol] = true;
		}
	}

	return -1;
}
int Level2::EscapeTheMaze(vector<string> maps)
{
	int iFindL = EscapeTheMazeBFS(maps, 'S', 'L');

	if (iFindL < 0)
	{
		return -1;
	}
	else
	{
		int iFindE = EscapeTheMazeBFS(maps, 'L', 'E');

		if (iFindE < 0)
			return -1;
		else
			return iFindL + iFindE;
	}
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

struct RowCol
{
	int row, col;

	RowCol(int iRow, int iCol) { row = iRow; col = iCol; }
};
int GameMapShortestDistanceBFS(vector<vector<int>> maps)
{
	queue<RowCol> q;
	RowCol rc(0, 0);
	q.push(rc);

	int iMaxCol = maps[0].size();
	int iMaxRow = maps.size();

	vector<vector<bool>> visit(iMaxRow, vector<bool>(iMaxCol, false));
	visit[0][0] = true;

	vector<vector<int>> distance(iMaxRow, vector<int>(iMaxCol, 0));
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

			if (iNextRow < 0 || iNextCol < 0 || iNextRow > iMaxRow - 1 ||  iNextCol > iMaxCol - 1)
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
int Level2::GameMapShortestDistance(vector<vector<int> > maps)
{
	int iGoalPositionX = maps.size() - 1;
	int iGoalPositionY = maps[0].size() - 1;

	if (maps[iGoalPositionX - 1][iGoalPositionY] == 0 && maps[iGoalPositionX][iGoalPositionY - 1] == 0)
		return -1;
	else if (maps[0][1] == 0 && maps[1][0] == 0)
		return -1;
	else
		return GameMapShortestDistanceBFS(maps);
}

bool CompareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b) 
{
	return a.second > b.second;
}
int Level2::PickTangerine(int k, vector<int> tangerine)
{
	int answer = 0;
	int iSum = 0;

	map<int, int> mapTangerine;
	
	for (int i = 0; i < tangerine.size(); i++)
	{
		mapTangerine[tangerine[i]]++;
	}

	vector<pair<int, int>> vecTangerine(mapTangerine.begin(), mapTangerine.end());
	sort(vecTangerine.begin(), vecTangerine.end(), CompareSecond);
	
	for (int i = 0; i < vecTangerine.size(); i++)
	{
		iSum += vecTangerine[i].second;
		answer++;

		if (iSum >= k)
			break;
	}

	return answer;
}

vector<string> Level2::OpenChatRoom(vector<string> record)
{
	vector<string> answer;
	map<string, string> mapUidName;
	vector<string> vecRecordOrder; // Uid, Enter/Leave

	for (int i = 0; i < record.size(); i++) 
	{
		vector<string> vecRecordData; // 0: Enter, Leave		1: uid			2: 이름
		istringstream iss(record[i]);
		string strTemp;
		
		while (iss >> strTemp)
		{
			vecRecordData.push_back(strTemp);
		}
		if(vecRecordData[0] != "Leave")
			mapUidName[vecRecordData[1]] = vecRecordData[2];

		if(vecRecordData[0] == "Enter" || vecRecordData[0] == "Leave")
			vecRecordOrder.push_back(vecRecordData[1] + " " + vecRecordData[0]);
	}

	for (int i = 0; i < vecRecordOrder.size(); i++)
	{
		string result;
		vector<string> vecRecordData;
		istringstream iss(vecRecordOrder[i]);
		string strTemp;

		while (iss >> strTemp)
		{
			vecRecordData.push_back(strTemp);
		}

		result = mapUidName[vecRecordData[0]];
		
		if(vecRecordData[1] == "Enter")
			result += "님이 들어왔습니다.";
		else
			result += "님이 나갔습니다.";

		answer.push_back(result);
	}

	return answer;
}

int Level2::DefenseGame(int n, int k, vector<int> enemy)
{
	int answer = 0;
	priority_queue<int> queueDescending;

	for (int i = 0; i < enemy.size(); i++)
	{
		n = n - enemy[i];
		queueDescending.push(enemy[i]);
		answer++;

		if (n < 0)
		{
			n += queueDescending.top(); queueDescending.pop();

			if (k > 0)
			{
				k--;
			}
			else
			{
				answer--;
				break;
			}
		}
	}

	return answer;
}

int Level2::CutRollCake(vector<int> topping){
	int answer = 0;
	map<int, int> mapFirst, mapSecond;

	for (int i = 0; i < topping.size(); i++)
	{
		mapFirst[topping[i]]++;
	}

	for (int i = topping.size() - 1; i >= 0; i--)
	{
		int iData = topping[i];
		mapFirst[iData]--;
		mapSecond[iData]++;

		if (mapFirst[iData] <= 0)
		{
			mapFirst.erase(iData);
		}

		if (mapFirst.size() == mapSecond.size())
		{
			answer++;
		}
	}

	return answer;
}

vector<bool> bVecFatigabilityVisit;
int iFatigabilityAnswer = 0;
void FatigabilityDFS(int k, vector<vector<int>> dungeons, int count)
{
	for (int i = 0; i < dungeons.size(); i++)
	{
		if (!bVecFatigabilityVisit[i] && k >= dungeons[i][0])
		{
			bVecFatigabilityVisit[i] = true;
			FatigabilityDFS(k - dungeons[i][1], dungeons, count + 1);
			bVecFatigabilityVisit[i] = false;
		}
	}

	if (iFatigabilityAnswer < count)
		iFatigabilityAnswer = count;
}
int Level2::Fatigability(int k, vector<vector<int>> dungeons)
{
	bVecFatigabilityVisit.resize(dungeons.size());
	FatigabilityDFS(k, dungeons, 0);

	return iFatigabilityAnswer;
}

int Level2::Lifeboat(vector<int> people, int limit)
{
	int answer=0;
	int iLeftIndex = 0;
	int iRightIndex = people.size() - 1;
	
	vector<int> iVecAscending = people;
	
	sort(iVecAscending.begin(), iVecAscending.end());

	while (iLeftIndex <= iRightIndex)
	{
		if (iLeftIndex == iRightIndex)
		{
			iRightIndex--;
		}
		else
		{
			int iSum = iVecAscending[iLeftIndex] + iVecAscending[iRightIndex];

			if (iSum <= limit)
			{
				iLeftIndex++; iRightIndex--;
			}
			else
			{
				iRightIndex--;
			}
		}

		answer++;
	}

	return answer;
}

string Level2::MakingLargeNumber(string number, int k)
{
	bool bFirstWhile = true;
	bool bSecondWhile = true;

	while (bFirstWhile)
	{
		int iChangeCount = 0;

		for (int i = 1; i <= number.size(); i++)
		{
			if (number[i - 1] < number[i] && k > 0)
			{
				number.erase(i - 1, 1);
				k--;
				iChangeCount++;

				if (k < 1)
				{
					bFirstWhile = false;
				}

				break;
			}
		}

		if (iChangeCount == 0)
			break;
	}

	if (k > 0)
	{
		while (bSecondWhile)
		{
			int iChangeCount = 0;

			for (int i = number.size() - 1; i > 0; i--)
			{
				if (number[i - 1] < number[i] && k > 0)
				{
					number.erase(i - 1, 1);
					k--;
					iChangeCount++;

					if (k < 1)
					{
						bSecondWhile = false;
					}

					break;
				}
			}

			if (iChangeCount == 0)
				break;
		}
	}

	while (k != 0)
	{
		number.erase(number.size() - 1, 1);
		k--;
	}

	return number;
}

int Level2::SumOfContinuousSequence(vector<int> elements)
{
	map<int, int> mElement;
	int iEndIndex = elements.size();

	for (int i = 0; i < iEndIndex; i++)
	{
		elements.push_back(elements[i]);
	}

	for (int i = 0; i < iEndIndex; i++)
	{
		int iSum = 0;

		for (int k = 0; k < iEndIndex; k++)
		{
			int iIndex = i + k;
			iSum += elements[iIndex];

			mElement[iSum] = 1;
		}
	}

	return mElement.size();
}

int Level2::ParcelBox(vector<int> order)
{
	int answer = 0;
	int iOrderIndex = 0;
	queue<int> queueOrder;
	queue<int> queueNumber;
	stack<int> stackSubContainer;

	for (int i = 0; i < order.size(); i++)
	{
		queueOrder.push(order[i]);
		queueNumber.push(i + 1);
	}

	while (!queueNumber.empty())
	{
		int iOrder = queueOrder.front();
		int iNumber = queueNumber.front(); 

		if (iOrder == iNumber)
		{
			queueOrder.pop();
			queueNumber.pop();
			answer++;
		}
		else
		{
			if (stackSubContainer.size() > 0)
			{
				int iSub = stackSubContainer.top();

				if (iOrder == iSub)
				{
					queueOrder.pop();
					stackSubContainer.pop();
					answer++;
				}
				else
				{
					stackSubContainer.push(iNumber);
					queueNumber.pop();
				}
			}
			else
			{
				stackSubContainer.push(iNumber);
				queueNumber.pop();
			}
		}
	}

	while (!stackSubContainer.empty() && !queueOrder.empty())
	{
		int iSub = stackSubContainer.top(); stackSubContainer.pop();
		int iOrder = queueOrder.front(); queueOrder.pop();

		if (iSub == iOrder)
		{
			answer++;
		}
		else
		{
			break;
		}
	}

	return answer;
}

int GreatestCommonDivisor(int a, int b)
{
	while (b != 0)
	{
		int iTemp = b;
		b = a % b;
		a = iTemp;
	}

	return a;
}
bool IsItDivided(int iOtherGCD, vector<int> arr)
{
	if (iOtherGCD == 1)
		return true;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % iOtherGCD == 0)
			return true;
	}

	return false;
}
int Level2::ShareTheNumberCards(vector<int> arrayA, vector<int> arrayB)
{
	int iArrayAGCD, iArrayBGCD;

	if (arrayA.size() > 1)
	{
		iArrayAGCD = GreatestCommonDivisor(arrayA[0], arrayA[1]);

		for (int i = 1; i < arrayA.size(); i++)
		{
			iArrayAGCD = GreatestCommonDivisor(iArrayAGCD, arrayA[i]);
		}
	}
	else
	{
		iArrayAGCD = arrayA[0];
	}

	if (arrayB.size() > 1)
	{
		iArrayBGCD = GreatestCommonDivisor(arrayB[0], arrayB[1]);

		for (int i = 1; i < arrayB.size(); i++)
		{
			iArrayBGCD = GreatestCommonDivisor(iArrayBGCD, arrayB[i]);
		}

	}
	else
	{
		iArrayBGCD = arrayB[0];
	}

	if (IsItDivided(iArrayAGCD, arrayB))
		iArrayAGCD = 1;

	if (IsItDivided(iArrayBGCD, arrayA))
		iArrayBGCD = 1;

	if (iArrayAGCD == 1 && iArrayBGCD == 1)
		return 0;
	else
	{
		if (iArrayAGCD > iArrayBGCD)
			return iArrayAGCD;
		else
			return iArrayBGCD;
	}

	return 0;
}

bool IsPrimeNumber(string strNumber)
{
	long iNumber = stol(strNumber);

	if (iNumber <= 1)
		return false;
	if (iNumber <= 3)
		return true;
	if (iNumber % 2 == 0 || iNumber % 3 == 0)
		return false;

	for (int i = 2; i <= sqrt(iNumber); i++)
	{
		if (iNumber % i == 0) 
		{
			return false;
		}
	}

	return true;
}
string ChangingTheDecimal(int iDecimalNumber, int iBase)
{
	string strResult = "";

	while (iDecimalNumber > 0)
	{
		int remainder = iDecimalNumber % iBase;
		char digit;

		if (remainder < 10)
			digit = '0' + remainder;
		else
			digit = 'A' + (remainder - 10);

		strResult = digit + strResult;
		iDecimalNumber /= iBase;
	}

	return strResult;
}
int Level2::FindDecimalCountsOfDecimal(int n, int k)
{
	int answer = 0;
	string strNotation = ChangingTheDecimal(n, k);
	char chDelimiter = '0'; // 구분자
	vector<string> vecNumbers;
	string strCurrentPart = "";

	for (char c : strNotation)
	{
		if (chDelimiter == c)
		{
			if (!strCurrentPart.empty())
			{
				vecNumbers.push_back(strCurrentPart);
				strCurrentPart.clear();
			}
		}
		else
		{
			strCurrentPart += c;
		}
	}

	if (!strCurrentPart.empty())
	{
		vecNumbers.push_back(strCurrentPart);
	}

	for (int i = 0; i < vecNumbers.size(); i++)
	{
		if (IsPrimeNumber(vecNumbers[i]))
			answer++;
	}

	return answer;
}

int Level2::StringCompression(string s)
{
	int answer = s.size();
	int iHalf = s.size() / 2;
	
	for (int i = 1; i <= iHalf; i++)
	{
		vector<string> vecCuttedString;
		int iCount = 1;
		int iIndex = 0;
		int iVectorIndex = 0;
		string strTemp = "";
		string strResult = "";

		for (int k = 0; k < s.size(); k++)
		{
			if (iIndex < i)
			{	
				iIndex++;
			}
			else
			{
				vecCuttedString.push_back(strTemp);
				strTemp = "";
				iIndex = 1;
			}

			strTemp += s[k];
		}

		if (strTemp.size() > 0)
			vecCuttedString.push_back(strTemp);

		while (iVectorIndex < vecCuttedString.size() - 1)
		{
			if (vecCuttedString[iVectorIndex] == vecCuttedString[iVectorIndex + 1])
			{
				iCount++;
			}
			else
			{
				if (iCount == 1)
				{
					strResult += vecCuttedString[iVectorIndex];
				}
				else
				{
					strResult += to_string(iCount) + vecCuttedString[iVectorIndex];
					iCount = 1;
				}
			}

			iVectorIndex++;
		}

		if (iCount == 1)
			strResult += vecCuttedString[iVectorIndex];
		else
			strResult += to_string(iCount) + vecCuttedString[iVectorIndex];

		if (answer > strResult.size())
			answer = strResult.size();
	}

	return answer;
}

vector<int> vecPrimeNumbers;
map<int, int> mapFindPrimeNumbers;
vector<bool> vecFindPrimeNumbersVisit;
void FindPrimeNumbersDFS(vector<int> vecNumbers, int iIndex, string strCurrentNumber)
{
	if (iIndex >= vecNumbers.size())
		return;

	for (int i = 0; i < vecNumbers.size(); i++)
	{
		if (!vecFindPrimeNumbersVisit[i])
		{
			string strNewNumber = strCurrentNumber + to_string(vecNumbers[i]);
			int iNewNumber = stoi(strNewNumber);

			if (mapFindPrimeNumbers[iNewNumber] == 0)
			{
				mapFindPrimeNumbers[iNewNumber] = 1;

				if (IsPrimeNumber(strNewNumber))
					vecPrimeNumbers.push_back(iNewNumber);
			}

			vecFindPrimeNumbersVisit[i] = true;
			FindPrimeNumbersDFS(vecNumbers, iIndex + 1, strNewNumber);
			vecFindPrimeNumbersVisit[i] = false;

		}
	}
}
int Level2::FindPrimeNumbers(string numbers)
{
	vector<int> vecNumbers;

	vecFindPrimeNumbersVisit.resize(numbers.size());

	for (int i = 0; i < numbers.size(); i++)
	{
		vecNumbers.push_back(numbers[i] - '0');
	}

	FindPrimeNumbersDFS(vecNumbers, 0, "");

	return vecPrimeNumbers.size();
}

vector<vector<bool>> visitCheck;
map<int, int> col_score;

void PCCPQuestionBFS(vector<vector<int>> land, int row, int col)
{
	map<int, int> colMap;
	queue<pair<int, int>> q;
	
	int scoreCount = 1;
	int rowMax = land.size() - 1;
	int colMax = land[0].size() - 1;

	visitCheck[row][col] = true;
	q.push({ row,col });
	colMap[col] = 1;
	
	while (!q.empty())
	{
		int currentRow = q.front().first;
		int currentCol = q.front().second;
		q.pop();

		for (int i = 0; i < iRow.size(); i++)
		{
			int newRow = currentRow + iRow[i];
			int newCol = currentCol + iCol[i];

			if (newRow < 0 || newCol < 0 || newRow > rowMax || newCol > colMax || visitCheck[newRow][newCol] || land[newRow][newCol] == 0)
				continue;

			visitCheck[newRow][newCol] = true;
			q.push({ newRow, newCol });
			colMap[newCol] = 1;
			scoreCount += 1;
		}
	}

	for (const auto& entry : colMap)
	{
		col_score[entry.first] += scoreCount;
	}
}
int Level2::PCCPQuestion1(vector<vector<int>> land)
{
	int max = 0;
	int row = land.size();
	int col = land[0].size();

	visitCheck.resize(row, std::vector<bool>(col, false));

	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			if (visitCheck[i][k])
				continue;
			if (land[i][k] == 1)
				continue;

			PCCPQuestionBFS(land, i, k);
		}
	}

	for (int i = 0; i < col; i++)
	{
		if (max < col_score[i])
		{
			max  = col_score[i];
		}
	}

	return max;
}