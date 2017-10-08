#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000 * 1000 * 1000;

typedef pair <int, vector <int> > path;

void dfs(const vector <vector <int> >& g, )

int main()
{
	int n, m;
	cin >> n >> m;
	while (1)
	{
		vector < vector <int> > g(n, vector <int>(-INF));

		for (int i = 0; i < m; ++i)
		{
			int start, end, cost;
			cin >> start >> end >> cost;
			g[start - 1][end - 1] = min(g[start - 1][end - 1], cost);
			g[end - 1][start - 1] = min(g[end - 1][start - 1], cost);
		}

		vector <char> used(n, false);
		
		cin >> n;
		if (n == -1)
			break;
		cin >> m;
	}
}