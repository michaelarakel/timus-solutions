#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100;

int dsu[maxn];
int h[maxn];

void init_dsu()
{
	for (int i = 0; i < maxn; ++i)
	{
		dsu[i] = i;
		h[i] = 1;
	}
}

int dsu_get(int v)
{
	if (v == dsu[v])
		return v;
	return dsu[v] = dsu_get(dsu[v]);
}

bool dsu_unite(int u, int v)
{
	int a = dsu_get(u),
		b = dsu_get(v);

	if (a == b)
		return false;

	if (h[a] < h[b])
		swap(a, b);

	dsu[b] = a;
	if (h[b] == h[a])
		++h[a];
	return true;
}

int main()
{
	int n, a, d;
	cin >> n >> d >> a;
	vector <pair <int, pair <int, int> > > g;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			if (j <= i)
				continue;
			if (c == '1')
				g.push_back(make_pair(0, make_pair(i, j)));
			else
				g.push_back(make_pair(a, make_pair(i, j)));
		}
	}
	sort(g.begin(), g.end());
	init_dsu();
	long long cost = 0;
	vector <vector <char> > ans(n, vector <char>(n, '0'));

	for (int i = 0; i < g.size(); ++i)
	{
		pair <int, int> node = g[i].second;
		int	curr_cost = g[i].first;
		if (dsu_unite(node.first, node.second))
		{
			cost += curr_cost;
			char c;
			if (curr_cost != 0)
			{
				ans[node.first][node.second] = 'a';
				ans[node.second][node.first] = 'a';
			}
		}
		else
		{
			if (curr_cost == 0)
			{
				cost += d;
				ans[node.first][node.second] = 'd';
				ans[node.second][node.first] = 'd';
			}
		}
	}
	cout << cost << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
}