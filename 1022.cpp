#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <set <int> > g(n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		while (cin >> num)
		{
			if (num == 0)
				break;
			g[i].insert(num - 1);
		}
	}
	vector <char> used(n, false);
	vector <int> ans;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!used[j] && g[j].size() == 0)
			{
				used[j] = true;
				ans.push_back(j + 1);
				for (int k = 0; k < n; ++k)
					g[k].erase(j);
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << ' ';
}