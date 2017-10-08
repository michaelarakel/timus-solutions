#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n, vector <int>(n));
	vector <int> priority(n);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[v - 1][u - 1] = 1;
	}
	//vector <char> used(n, false);
	//vector <int> top_sort;
	/*for (int i = 0; i < used.size(); ++i)
		if (!used[i])
			if (!dfs(0, g, used))
			{
				cout << "NO";
				return 0;
			}
	*/
	vector <int> proposal(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> proposal[i];
		--proposal[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int node = proposal[i];
		bool check = true;
		for (int i = 0; i < g[node].size(); ++i)
		if (g[node][i] != 0)
		{
			check = false;
			break;
		}
		if (!check)
		{
			cout << "NO";
			return 0;
		}
		for (int i = 0; i < g.size(); ++i)
			g[i][node] = 0;
	}
	cout << "YES";
}