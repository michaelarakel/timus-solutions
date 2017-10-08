#include <iostream>
#include <vector>
#include <algorithm>
int maxn = 30;

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main()
{
	int level_count;
	cin >> level_count;

	vector <int> last_level(maxn, 0),
		current_level(maxn, INF);
	int n;
	for (int level = 0; level < level_count; ++level)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int num, cost;
			while (cin >> num)
			{
				if (num == 0)
					break;
				cin >> cost;
				current_level[i] = min(current_level[i], last_level[num - 1] + cost);
			}
		}
		swap(last_level, current_level);
		current_level.assign(maxn, INF);
		if (level != level_count - 1)
		{
			char c;
			cin >> c;
		}
	}

	cout << *min_element(last_level.begin(), last_level.begin() + n);
}