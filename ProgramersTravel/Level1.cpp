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