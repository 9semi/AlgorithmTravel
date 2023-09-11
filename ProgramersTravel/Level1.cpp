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