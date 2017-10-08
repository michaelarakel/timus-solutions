#include <iostream>
#include <vector>

using namespace std;

const int maxn = 10000;

int dsu[maxn];
int height[maxn];

void init_dsu()
{
	for (int i = 0; i < maxn; ++i)
		dsu[i] = i;
}

int find(int v)
{
	if (v == dsu[v])
		return v;
	return dsu[v] = find(dsu[v]);
}

bool merge(int a, int b)
{
	int u = find(a),
		v = find(b);
	if (u == v)
		return false;

	if (height[u] < height[v])
		swap(u, v);

	dsu[v] = u;
	if (height[u] == height[v])
		++height[u];
	return true;
}

int main()
{
	init_dsu();

	vector < pair <int, pair <int, int> > > edges;

	int n, tunnels[2];
	cin >> n >> tunnels[0] >> tunnels[1];
	for (int k = 0; k < 2; ++k)
	{
		for (int i = 0; i < tunnels[k]; ++i)
		{
			int u, v;
			cin >> u >> v;
			edges.push_back(make_pair(k, make_pair(u - 1, v - 1)));
		}
	}

	int bridge_counter = 0;
	for (int i = 0; i < edges.size(); ++i)
	{
		int u = edges[i].second.first,
			v = edges[i].second.second,
			cost = edges[i].first;

		if (merge(u, v))
		{
			if (cost == 1)
				++bridge_counter;
		}
	}

	cout << bridge_counter << endl;
}