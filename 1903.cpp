#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int INF = 1000 * 1000 * 1000;
const int maxn = 10000;

typedef vector < vector <pair<int, int> > > graph;

int dijkstra(const graph& g, int start, int end, int stirring)
{
	int n = g.size();
	vector <char> used(n, false);
	vector <int> d(n, INF);
	d[start - 1] = 0;
	priority_queue<pair <int, int>, vector <pair <int, int> >, greater <pair<int, int> > > q;
	q.push(make_pair(0, start - 1));

	while (!q.empty())
	{
		int node = q.top().second,
			len = q.top().first;
		q.pop();
		if (len > d[node])
			continue;
		for (int i = 0; i < g[node].size(); ++i)
		{
			int curr = g[node][i].second,
				cost = g[node][i].first;
				if (d[curr] > len + cost)
				{
					d[curr] = len + cost;
					q.push(make_pair(d[curr], curr));
				}
		}
	}
	return d[end - 1];
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <pair <int, int> > > g(n),
		rev_g(n);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		int cost;
		if (u > v)
			cost = 1;
		else
			cost = 0;
		g[u - 1].push_back(make_pair(cost, v - 1));
		g[v - 1].push_back(make_pair(cost, u - 1));
		rev_g[u - 1].push_back(make_pair(cost == 0, v - 1));
		rev_g[v - 1].push_back(make_pair(cost == 0, u - 1));
	}

	int start, end;
	cin >> start >> end;
	cout << min(dijkstra())
}