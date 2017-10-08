#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int count;

pair <int, int> findEachOther(vector <vector <char> > v, pair <int, int> start1, pair <int, int> start2, vector <vector <pair <int, int> > > tel)
{
	deque <pair <int, int> > d1(1, start1), d2(1, start2);
	while (!d1.empty() && !d2.empty())
	{
		pair <int, int> curr = d1[0];
		d1.pop_front();
		if (v[curr.first + 1][curr.first + 1] == '.' ||
			v[curr.first + 1][curr.first + 1] == '!')
		{
			if (v[curr.first + 1][curr.first + 1] == '.')
			{
				v[curr.first + 1][curr.first + 1] = '-';
				d1.push_back(make_pair(curr.first + 1,curr.first + 1));
			}
			else
				return make_pair(curr.first + 1,curr.first + 1);
		}
		if (v[curr.first + 1][curr.first] == '.' ||
			v[curr.first + 1][curr.first] == '!')
		{
			if (v[curr.first + 1][curr.first] == '.')
				v[curr.first + 1][curr.first] = '$';
			else
				return make_pair(curr.first + 1,curr.first);
			d1.push_back(make_pair(curr.first + 1,curr.first));
		}
		if (v[curr.first + 1][curr.first - 1] == '.' ||
			v[curr.first + 1][curr.first - 1] == '!')
		{
			if (v[curr.first + 1][curr.first - 1] == '.')
				v[curr.first + 1][curr.first - 1] = '$';
			else
				return make_pair(curr.first + 1,curr.first - 1);
			d1.push_back(make_pair(curr.first + 1,curr.first - 1));
		}
		if (v[curr.first][curr.first + 1] == '.' ||
			v[curr.first][curr.first + 1] == '!')
		{
			if (v[curr.first][curr.first + 1] == '.')
				v[curr.first][curr.first + 1] = '-';
			else
				return make_pair(curr.first, curr.first + 1);
			d1.push_back(make_pair(curr.first,curr.first + 1));
		}

		if (v[curr.first][curr.first - 1] == '.' ||
			v[curr.first][curr.first - 1] == '!')
		{
			if (v[curr.first][curr.first - 1] == '.')
				v[curr.first][curr.first - 1] = '-';
			else
				return make_pair(curr.first,curr.first - 1);
			d1.push_back(make_pair(curr.first,curr.first - 1));
		}

		if (v[curr.first - 1][curr.first + 1] == '.' ||
			v[curr.first  - 1][curr.first + 1] == '!')
		{
			if (v[curr.first - 1][curr.first + 1] == '.')
				v[curr.first - 1][curr.first + 1] = '-';
			else
				return make_pair(curr.first - 1, curr.first + 1);
			d1.push_back(make_pair(curr.first - 1,curr.first + 1));
		}

		if (v[curr.first - 1][curr.first] == '.' ||
			v[curr.first - 1][curr.first] == '!')
		{
			if (v[curr.first - 1][curr.first] == '.')
				v[curr.first - 1][curr.first] = '-';
			else
				return make_pair(curr.first - 1, curr.first);
			d1.push_back(make_pair(curr.first - 1,curr.first));
		}

		if (v[curr.first - 1][curr.first - 1] == '.' ||
			v[curr.first - 1][curr.first - 1] == '!')
		{
			if (v[curr.first - 1][curr.first - 1] == '.')
				v[curr.first - 1][curr.first - 1] = '-';
			else
				return make_pair(curr.first - 1, curr.first - 1);
			d1.push_back(make_pair(curr.first - 1,curr.first - 1));
		}

		curr = d2[0];
		d2.pop_dront();
	}
}

int main ()
{
	count = 0;
	int n, m;
	cin >> n >> m;
	pair <int, int> start1, start2, end;
	vector <vector <char> > v(n + 2, vector <char>(m + 2));
	vector <vector <pair <int, int> > > teleport(26, vector <pair <int, int> >(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (isalpha(v[i][j]))
				teleport[v[i][j] - 'A'].push_back(make_pair(i, j);
			if (v[i][j] == '$')
				start1 = make_pair(i, j);
			if (v[i][j] = '!')
				start2 = make_pair(i, j);
		}
	pair <int, int> start = findEachOther(v, start1, start2, teleport);
	minWay(v, start, teleport);
}