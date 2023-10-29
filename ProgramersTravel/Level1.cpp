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

vector<int> Level1::PersonalInformationCollectionPeriod(string today, vector<string> terms, vector<string> privacies)
{
	size_t dot1 = today.find('.');
	size_t dot2 = today.find('.', dot1 + 1);

	int iTodayYear = stoi(today.substr(0, dot1)) - 2000;
	int iTodayMonth = stoi(today.substr(dot1 + 1, dot2 - dot1 - 1));
	int iTodayDay = stoi(today.substr(dot2 + 1));
	int iTodaySum = (iTodayYear * 336) + (iTodayMonth * 28) + iTodayDay;

	vector<int> answer;
	map<char, int> mapTerm;

	for (int i = 0; i < terms.size(); i++)
	{
		size_t space = terms[i].find(' ');
		char chTermsType = terms[i][0];
		int iTermsMonth = stoi(terms[i].substr(space + 1));
		mapTerm.insert(make_pair(chTermsType, iTermsMonth));
	}

	for (int i = 0; i < privacies.size(); i++)
	{
		size_t dot1 = privacies[i].find('.');
		size_t dot2 = privacies[i].find('.', dot1 + 1);
		size_t space = privacies[i].find(' ');

		int iExpirationYear = stoi(privacies[i].substr(0, dot1)) - 2000;
		int iExpirationMonth = stoi(privacies[i].substr(dot1 + 1, dot2 - dot1 - 1));
		int iExpirationDay = stoi(privacies[i].substr(dot2 + 1, 2));
		char type = privacies[i].substr(space + 1)[0];

		iExpirationMonth += mapTerm[type];

		if (iExpirationMonth > 12)
		{
			int rest = iExpirationMonth % 12;
			int division = iExpirationMonth / 12;

			iExpirationYear += division;
			iExpirationMonth = rest;
		}

		int sum = (iExpirationYear * 336) + (iExpirationMonth * 28) + iExpirationDay;

		if (sum <= iTodaySum)
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}

int Level1::KnightsWeapon(int number, int limit, int power)
{
	int answer = 0;
	vector<int> vecDivisors;


	for (int i = 1; i <= number; i++)
	{
		int iSqrtNumber = sqrt(i);
		int iCount = 0;

		for (int k = 1; k <= iSqrtNumber; k++)
		{
			if (i % k == 0)
			{
				iCount++;

				if (k != (i / k))
					iCount++;
			}
		}

		if (iCount > limit)
			vecDivisors.push_back(power);
		else
			vecDivisors.push_back(iCount);
	}

	for (int i = 0; i < vecDivisors.size(); i++)
	{
		answer += vecDivisors[i];
	}

	return answer;
}

vector<int> Level1::TheNearestLetter(string s)
{
	vector<int> answer;
	map<char, int> mapLetter;

	for (int i = 0; i < s.size(); i++)
	{
		char chTemp = s[i];

		if (mapLetter.empty())
		{
			mapLetter.insert(pair<char, int>(chTemp, i));
			answer.push_back(-1);
		}
		else
		{
			map<char, int>::iterator it = mapLetter.find(chTemp);

			if (it == mapLetter.end()) // 찾지 못했다.
			{
				mapLetter[chTemp] = i;
				answer.push_back(-1);
			}
			else
			{
				int iTemp = mapLetter[chTemp];
				answer.push_back(i - iTemp);
				mapLetter[chTemp] = i;
			}
		}
	}

	return answer;
}

int Level1::SeparatingStrings(string s)
{
	char chStandard = '\0';
	int answer = 0;
	int iStandardCount = 0;
	int iCompareCount = 0;

	for (int i = 0; i < s.size(); i++) 
	{
		if (chStandard == '\0')
		{
			iStandardCount++;
			chStandard = s[i];
			continue;
		}

		if (chStandard == s[i])
		{
			iStandardCount++;
		}
		else
		{
			iCompareCount++;
		}

		if (iStandardCount == iCompareCount)
		{
			chStandard = '\0';
			answer++;
		}
	}

	if (chStandard != '\0')
		answer++;

	
	return answer;
}

int iFruitVendorAnswer = 0;
bool Descending(int a, int b)
{
	return a > b;
}
int Level1::FruitVendor(int k, int m, vector<int> score)
{
	// k : 가장 비싼 사과, m : 한 박스에 들어가는 사과의 수, score : 현재 가지고 있는 사과들의 가격

	sort(score.begin(), score.end(), Descending);

	for (int i = 0; i < score.size(); i += m)
	{
		if (i + m - 1 >= score.size())
			continue;

		iFruitVendorAnswer += score[i + m - 1] * m;
	}

	return iFruitVendorAnswer;
}