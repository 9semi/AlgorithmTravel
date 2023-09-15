#include "Level3.h"

int Level3::Network(int n, vector<vector<int>> computers)
{
	vector<int> visit;
	queue<int> q;
	int iAnswer = 0;
	int iCount = 0;
	for (int i = 0; i < n; i++)
	{
		visit.emplace_back(-1);
	}

	while (true)
	{
		int iIndex = -1;

		for (int i = 0; i < n; i++)
		{
			if (visit[i] < 0)
			{
				iIndex = i;
				iCount++;
				visit[i] = iCount;
				break;
			}
		}

		if (iIndex == -1)
		{
			iAnswer = iCount;
			break;
		}
		else
		{
			q.push(iIndex);

			while (!q.empty())
			{
				int iFrontData = q.front();
				q.pop();

				for (int i = 0; i < n; i++)
				{
					if (iFrontData == i)
					{
						continue;
					}

					if (visit[i] != -1)
					{
						continue;
					}

					if (computers[iFrontData][i] == 1)
					{
						q.push(i);
						visit[i] = 1;
					}
				}
			}
		}
	}

	return iAnswer;
}