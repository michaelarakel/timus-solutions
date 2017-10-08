#include <iostream>
#include <vector>

using namespace std;

bool augmenting_path(int v, const vector <vector <int> >& g, vector <char>& used, vector <int>& mt)
{
	if (used[v])
		return false;
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i)
	if (mt[g[v][i]] == -1 || augmenting_path(mt[g[v][i]], g, used, mt))
	{
		mt[g[v][i]] = v;
		return true;
	}
	return false;
}

int main()
{
	int partition_a, partition_b, edges;
	cin >> partition_a >> partition_b >> edges;
	vector <vector <int> > graph(partition_a);
	for (int i = 0; i < edges; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
	}

	vector <int> matching(partition_b, -1);
	vector <char> used;
	int matching_power = 0;
	for (int i = 0; i < partition_a; ++i)
	{
		used.assign(partition_a, false);
		if (augmenting_path(i, graph, used, matching))
			++matching_power;
	}
	vector <char> connected[2];
	connected[0].assign(partition_a, false);
	connected[1].assign(partition_b, false);
	for (int i = 0; i < matching.size(); ++i)
	{
		if (matching[i] != -1)
		{
			connected[0][matching[i]] = true;
			connected[1][i] = true;
		}
	}

	for (int k = 0; k < 2; ++k)
	for (int i = 0; i < connected[k].size(); ++i)
	if (!connected[k][i])
		++matching_power;

	cout << matching_power << endl;
}