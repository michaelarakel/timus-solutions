#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void dfs(int v, const vector <vector <int> >& g, vector <char>& used)
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int node = g[v][i];
		if (!used[node])
			dfs(node, g, used);
	}
}

int main()
{
	int n;
	cin >> n;
	vector <vector <int> > parents(n);
	vector <vector <int> >children(n);
	string s;
	getline(cin, s);
	while (getline(cin, s))
	{
		if (s == "BLOOD")
			break;
		istringstream iss(s);
		int u, v;
		iss >> u >> v;
		parents[u - 1].push_back(v - 1);
		children[v - 1].push_back(u - 1);
	}

	vector <char> used(n, false);
	int num;
	while (cin >> num)
	{
		dfs(num - 1, parents, used);
		dfs(num - 1, children, used);
		/*for (int i = 0; i < parents[num - 1].size(); ++i)
			used[parents[num - 1][i]] = true;*/
		/*for (int i = 0; i < children[num - 1].size(); ++i)
			used[children[num - 1][i]] = true;*/
	}
	bool found = false;
	for (int i = 0; i < used.size(); ++i)
	if (!used[i])
	{
		found = true;
		cout << i + 1 << ' ';
	}
	if (!found)
		cout << 0;
	cout << endl;
}