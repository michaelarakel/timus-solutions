#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool is_independent(const vector <vector <int> > & g, int mask)
{
	vector <int> vertex_set;
	for (int i = 0; i < g.size(); ++i)
	{
		if ((mask >> i) & 1)
			vertex_set.push_back(i);
	}

	for (int i = 0; i < vertex_set.size() - 1; ++i)
	for (int j = i + 1; j < vertex_set.size(); ++j)
	{
		if (binary_search(g[vertex_set[i]].begin(), g[vertex_set[i]].end(), vertex_set[j]))
			return false;
	}

	return true;
}

int num_of_ones(int n)
{
	int temp = 1;
	int counter = 0;
	while (temp <= n)
	{
		if (temp & n)
			++counter;
		temp <<= 1;
	}
	return counter;
}

int main()
{
	int n;
	cin >> n;
	map <string, vector <int> > m;
	vector <vector <int> > graph(n);
	for (int input = 0; input < n; ++input)
	{
		string player[3];
		for (int i = 0; i < 3; ++i)
			cin >> player[i];

		for (int i = 0; i < 3; ++i)
		{
			m[player[i]].push_back(input);
			auto it = m.find(player[i]);
			if (it->second.size() == 1)
			{
				continue;
			}
			m[player[i]].push_back(input);
			int temp = it->second.size();
			for (int ind = 0; ind < temp; ++ind)
			{
				graph[input].push_back(it->second[ind]);
				graph[it->second[ind]].push_back(input);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
		if (binary_search(graph[i].begin(), graph[i].end(), i))
		{
			auto it = lower_bound(graph[i].begin(), graph[i].end(), i);
			graph[i].erase(it);
		}
	}

	int max_mask = (1 << n) - 1;
	for (int mask = max_mask; mask > 0; mask = (mask - 1) & max_mask)
	{
		if (is_independent(graph, mask))
		{
			cout << num_of_ones(mask) << endl;
			return 0;
		}
	}
}