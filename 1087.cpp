#include <iostream>
#include <vector>

using namespace std;

const int maxn = 10000;
bool used[maxn + 1];
bool is_winning[maxn + 1];

void rec(int n, const vector <int>& v)
{
	if (n == 0)
		return;

	bool has_winning_combination = false;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > n)
			continue;

		if (!used[n - v[i]])
			rec(n - v[i], v);

		if (!is_winning[n - v[i]])
		{
			has_winning_combination = true;
			break;
		}
	}
	used[n] = true;
	is_winning[n] = has_winning_combination;
}

int main()
{
	is_winning[0] = true;
	used[0] = true;
	int n, m;
	cin >> n >> m;
	vector <int> v(m);
	for (int i = 0; i < m; ++i)
		cin >> v[i];
	rec(n, v);
	if (is_winning[n])
		cout << 1;
	else
		cout << 2;
}