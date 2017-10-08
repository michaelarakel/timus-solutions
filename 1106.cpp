#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int v, const vector <vector <int> >& g, vector <char>& used, vector <int>& color)
{
	used[v] = true;
	int reverse_color = (color[v] == 0);
	for (auto it : g[v])
	{
		if (!used[it])
		{
			color[it] = reverse_color;
			dfs(it, g, used, color);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector <vector <int> >g(n);
	vector <int> color(n, -1);
	vector <char> used(n, false);
	for (int i = 0; i < n; ++i)
	{
		int num;
		while (cin >> num)
		{
			if (num == 0)
				break;
			g[i].push_back(num - 1);
			g[num - 1].push_back(i);
		}
	}

	for (int i = 0; i < n; ++i)
	if (!used[i])
	{
		if (g[i].size() == 0)
		{
			cout << 0;
			return 0;
		}
		color[i] = 0;
		dfs(i, g, used, color);
	}

	vector <int> ans;
	int counter = 0;
	for (auto it : color)
	{
		if (it)
			ans.push_back(counter);
		++counter;
	}
	cout << ans.size() << endl;
	for (auto it : ans)
		cout << it << ' ';
}