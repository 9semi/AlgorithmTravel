#include "Level1.h"

using namespace std;

vector<string> Level1::RunningRace(vector<string> players, vector<string> callings)
{
	vector<string> answer;
	map<string, int> playerFirst;
	map<int, string> rankFirst;

	for (int i = 0; i < players.size(); i++)
	{
		playerFirst.insert(make_pair(players[i], i));
		rankFirst.insert(make_pair(i, players[i]));
	}

	for (int i = 0; i < callings.size(); i++)
	{
		int index = playerFirst[callings[i]];
		string a = rankFirst[index];

		string b = rankFirst[index - 1];
		int index2 = playerFirst[b];

		playerFirst[a] = index2;
		playerFirst[b] = index;

		rankFirst[index] = b;
		rankFirst[index2] = a;
	}

	for (int i = 0; i < players.size(); i++)
	{
		answer.push_back(rankFirst[i]);
	}

	return answer;
}

vector<int> Level1::MemoryScore(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
	int iIndex = 0;
	bool bIsFirst = true;
	vector<int> vecAnswer;
	map<string, int> mapYearning;

	for (int i = 0; i < name.size(); i++)
	{
		mapYearning.insert({ name[i], yearning[i] });
	}

	for (const auto& innerVec : photo)
	{
		for (const auto& element : innerVec)
		{
			if (bIsFirst)
			{
				vecAnswer.push_back(mapYearning[element]);
				bIsFirst = false;
			}
			else
			{
				vecAnswer[iIndex] += mapYearning[element];
			}
		}
		bIsFirst = true;
		iIndex++;
	}

	return vecAnswer;
}

vector<int> Level1::WalkInThePark(vector<string> park, vector<string> routes)
{
	vector<int> answer;
	vector<vector<int>> vecMap;

	int iCurrentX;
	int iCurrentY;

	int iWidth = park[0].size();
	int iHeight = park.size();

	for (int i = 0; i < park.size(); i++)
	{
		vector<int> row;

		for (int k = 0; k < park[i].size(); k++)
		{
			if (park[i][k] == 'S')
			{
				row.push_back(0);
				iCurrentX = i;
				iCurrentY = k;
			}
			else if (park[i][k] == 'O')
				row.push_back(0);
			else
				row.push_back(1);
		}
		vecMap.push_back(row);
	}

	for (int i = 0; i < routes.size(); i++)
	{
		size_t found = routes[i].find(' ');
		string direction = routes[i].substr(0, found);
		string howmanytimes = routes[i].substr(found + 1);
		int iCount;
		int iMoveTimes = 0;
		bool bIsComplete = true;

		// 동(오른)쪽
		if (direction == "E")
		{
			iCount = iCurrentY + stoi(howmanytimes);

			if (iCount >= iWidth)
				continue;

			for (int k = iCurrentY; k < iCount; k++)
			{
				// 만약 앞이 O라면
				if (vecMap[iCurrentX][k + 1] == 0)
				{
					iMoveTimes++;
				}
				else
				{
					bIsComplete = false;
					break;
				}
			}

			if (bIsComplete)
				iCurrentY += iMoveTimes;
			else
				continue;
		}
		// 서(왼)쪽
		else if (direction == "W")
		{
			iCount = iCurrentY - stoi(howmanytimes);

			if (iCount < 0)
				continue;

			for (int k = iCurrentY; k > iCount; k--)
			{
				// 만약 앞이 O라면
				if (vecMap[iCurrentX][k - 1] == 0)
				{
					iMoveTimes++;
				}
				else
				{
					bIsComplete = false;
					break;
				}
			}

			if (bIsComplete)
				iCurrentY -= iMoveTimes;
		}
		// 남(아래)쪽
		else if (direction == "S")
		{
			iCount = iCurrentX + stoi(howmanytimes);

			if (iCount >= iHeight)
				continue;

			for (int k = iCurrentX; k < iCount; k++)
			{
				// 만약 앞이 O라면
				if (vecMap[k + 1][iCurrentY] == 0)
				{
					iMoveTimes++;
				}
				else
				{
					bIsComplete = false;
					break;
				}
			}

			if (bIsComplete)
				iCurrentX += iMoveTimes;
			else
				continue;
		}
		// 북(위)쪽
		else
		{
			iCount = iCurrentX - stoi(howmanytimes);

			if (iCount < 0)
				continue;

			for (int k = iCurrentX; k > iCount; k--)
			{
				// 만약 앞이 O라면
				if (vecMap[k - 1][iCurrentY] == 0)
				{
					iMoveTimes++;
				}
				else
				{
					bIsComplete = false;
					break;
				}
			}

			if (bIsComplete)
				iCurrentX -= iMoveTimes;
			else
				continue;
		}
	}

	answer = { iCurrentX, iCurrentY };
	return answer;
}

vector<int> Level1::ScreenOrganization(vector<string> wallpaper)
{
	vector<int> answer;

	int iStartX = INT16_MAX;
	int iStartY = INT16_MAX;
	int iEndX = INT16_MIN;
	int iEndY = INT16_MIN;

	for (int i = 0; i < wallpaper.size(); i++)
	{
		for (int k = 0; k < wallpaper[i].size(); k++)
		{
			if (wallpaper[i][k] == '#')
			{
				if (iStartX > i)
				{
					iStartX = i;
				}

				if (iStartY > k)
				{
					iStartY = k;
				}

				if (iEndX < i)
				{
					iEndX = i;
				}

				if (iEndY < k)
				{
					iEndY = k;
				}
			}
		}
	}

	answer = { iStartX, iStartY, iEndX + 1, iEndY + 1 };
	return answer;
}

int Level1::Overpainting(int n, int m, vector<int> section)
{
	int iAnswer = 0;
	int iLastPaintedArea = 0;
	int iCurrentIndex = 0;
	int iVectorLength = section.size();

	while (iLastPaintedArea < section[iVectorLength - 1])
	{
		if (iLastPaintedArea >= section[iCurrentIndex])
		{
			iCurrentIndex++;
		}
		else
		{
			iLastPaintedArea = section[iCurrentIndex];
			iLastPaintedArea += m - 1;
			iCurrentIndex++;
			iAnswer++;
		}
	}

	return iAnswer;
}

vector<int> Level1::BuiltInKeyBoard(vector<string> keymap, vector<string> targets)
{
	vector<int> answer;
	map<char, int> mapBestIndex;

	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		for (int i = 0; i < keymap.size(); i++)
		{
			size_t found = keymap[i].find(ch);

			if (found != string::npos)
			{
				found++;

				if (mapBestIndex.count(ch) > 0)
				{
					if (mapBestIndex[ch] > found)
					{
						mapBestIndex[ch] = found;
					}
				}
				else
				{
					mapBestIndex.insert(make_pair(ch, found));
				}
			}
		}
	}

	for (int i = 0; i < targets.size(); i++)
	{
		int iSumIndex = 0;

		for (int k = 0; k < targets[i].size(); k++)
		{
			char chTemp = targets[i][k];
			if (mapBestIndex.count(chTemp) > 0)
			{
				iSumIndex += mapBestIndex[chTemp];
			}
			else
			{
				iSumIndex = -1;
				k = targets[i].size();
			}
		}
		answer.push_back(iSumIndex);
	}
	return answer;
}

string Level1::BunchOfCards(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
	string answer = "";

	int iCard1Index = 0;
	int iCard2Index = 0;

	for (int i = 0; i < goal.size(); i++)
	{
		if (iCard1Index < cards1.size() && goal[i] == cards1[iCard1Index])
		{
			iCard1Index++;
		}
		else if (iCard2Index < cards2.size() && goal[i] == cards2[iCard2Index])
		{
			iCard2Index++;
		}
		else
		{
			answer = "No";
			return answer;
		}
	}

	answer = "Yes";

	return answer;
}

string Level1::SecretCodeForTheTwo(string s, string skip, int index)
{
	string answer = "";

	for (int i = 0; i < s.size(); i++)
	{
		char chTemp = s[i];

		for (int k = 0; k < index; k++)
		{
			chTemp += 1;

			if (chTemp > 'z')
			{
				chTemp = 'a';
			}

			size_t found = skip.find(chTemp);

			if (found != string::npos)
			{
				k--;
			}
		}

		s[i] = chTemp;
	}
	answer = s;
	return answer;
}