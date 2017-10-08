#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;

typedef long double ld;

const ld INF = 1000 * 1000 * 1000;

ld distance(ld a_x, ld a_y, ld b_x, ld b_y)
{
	return sqrt((a_x - b_x) * (a_x - b_x) + (a_y - b_y) * (a_y - b_y));
}

int main()
{
	ld metro_speed, walk_speed;
	cin >> walk_speed >> metro_speed;
	int n;
	cin >> n;
	deque < pair < double, double > > coordinates;
	for (int i = 0; i < n; ++i)
	{
		double x, y;
		cin >> x >> y;
		coordinates.push_back(make_pair(x, y));
	}

	vector < vector <ld> > graph(n + 2, vector <ld>(n + 2));
	vector < pair < int, int > > input_edges;
	vector < char > is_station(n + 2, false);
	int u, v;
	while (cin >> u >> v)
	{
		if (u == 0 && v == 0)
			break;

		input_edges.push_back(make_pair(u, v));
	}

	coordinates.push_front(make_pair(0, 0));
	coordinates.push_back(make_pair(0, 0));
	cin >> coordinates[0].first >> coordinates[0].second >> coordinates.back().first >> coordinates.back().second;

	for (int i = 0; i < coordinates.size() - 1; ++i)
	for (int j = i + 1; j < coordinates.size(); ++j)
	{
		ld d = distance(coordinates[i].first, coordinates[i].second, coordinates[j].first, coordinates[j].second);
		graph[i][j] = graph[j][i] = d / walk_speed;
	}

	for (int i = 0; i < input_edges.size(); ++i)
	{
		int u = input_edges[i].first,
			v = input_edges[i].second;

		ld d = distance(coordinates[u].first, coordinates[u].second, coordinates[v].first, coordinates[v].second);
		graph[u][v] = graph[v][u] =  d / metro_speed;
		is_station[u] = is_station[v] = true;
	}

	vector <ld> d(n + 2, INF);
	d[0] = 0;
	priority_queue <pair <ld, int>, vector < pair <ld, int> >, greater < pair <ld, int> > > q;
	q.push(make_pair(d[0], 0));
	vector <int> pre(n + 2, -1);
	while (!q.empty())
	{
		int node = q.top().second;
		ld dist = q.top().first;
		q.pop();
		if (dist > d[node])
			continue;

		for (int i = 0; i < graph[node].size(); ++i)
		{
			if (d[i] > graph[node][i] + dist)
			{
				d[i] = graph[node][i] + dist;
				pre[i] = node;
				q.push(make_pair(d[i], i));
			}
		}
	}

	cout << fixed << setprecision(7) << d[d.size() - 1] << endl;

	vector <int> path;
	vector <int> stations;
	for (int v = n + 1; v != -1; v = pre[v])
		path.push_back(v);

	int station_counter = 0;
	for (int i = path.size() - 1; i > 0; --i)
	if (is_station[path[i]])
	{
		++station_counter;
		stations.push_back(path[i]);
	}

	cout << station_counter;
	for (int i = 0; i < stations.size(); ++i)
		cout << ' ' << stations[i];
	cout << endl;

	return 0;
}