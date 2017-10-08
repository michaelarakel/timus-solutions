#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100;
int color[maxn];
vector <int> g[maxn];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		while (cin >> num)
		{
			if (!num)
				break;
			g[i].push_back(num - 1);
			g[num - 1].push_back(i);
		}
	}
	vector <char> used(n, false);
	queue <int> q;
	q.push(0);
	used[0] = true;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		int col = color[node];

		for (int i = 0; i < g[node].size(); ++i)
		{
			int v = g[node][i];
			if (!used[v])
			{
				used[v] = true;
				color[v] = (col == 0);
				q.push(v);
			}
			else
			{
				if (color[v] == col)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << color[i];
	cout << endl;
}