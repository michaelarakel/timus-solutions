#include <iostream>
#include <vector>

using namespace std;

void print_eq(const vector <int> & v, const int dest, const int size)
{
	cout << size << endl;
	for (int i = 0; i < v.size(); ++i)
	if (v[i] == dest)
		cout << i + 1 << ' ';
	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	vector <int> color(n, 0);
	vector <vector <int> > graph(n);
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j)
		{
			int num;
			cin >> num;
			graph[i].push_back(num - 1);
		}
	}
	while (true)
	{
		bool got_ans = true;
		for (int i = 0; i < n; ++i)
		{
			int counter = 0;
			for (int j = 0; j < graph[i].size(); ++j)
			if (color[graph[i][j]] == color[i])
				++counter;
			if (counter >= 2)
			{
				color[i] = !color[i];
				got_ans = false;
			}
		}
		if (got_ans)
			break;
	}

	int color_counter[2] = { 0, 0 };
	for (int i = 0; i < n; ++i)
		++color_counter[color[i]];

	if (color_counter[0] == color_counter[1])
		print_eq(color, color[0], color_counter[0]);
	else if (color_counter[0] > color_counter[1])
		print_eq(color, 1, color_counter[1]);
	else
		print_eq(color, 0, color_counter[0]);
}