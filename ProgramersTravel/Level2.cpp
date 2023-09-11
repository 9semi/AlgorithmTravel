#include "Level2.h"

using namespace std;

int Level2::InterceptionSystem(vector<vector<int>> targets)
{
	int answer = 0;

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
			answer++;
		}
	}

	return answer;
}


