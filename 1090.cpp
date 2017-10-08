#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1 << 15;

int segment_tree[20][maxn];

void update(int v, int tl, int tr, int pos, int value, int num)
{
	if (tl == tr)
	{
		segment_tree[num][v] = value;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update((v << 1), tl, tm, pos, value, num);
	else
		update((v << 1) + 1, tm + 1, tr, pos, value, num);
	segment_tree[num][v] = segment_tree[num][(v << 1)] + segment_tree[num][(v << 1) + 1];
}

int sum(int v, int l, int r, int tl, int tr, int num)
{
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return segment_tree[num][v];

	int tm = (tl + tr) >> 1;

	if (r <= tm)
		return sum(v << 1, l, r, tl, tm, num);
	else if (l > tm)
		return sum((v << 1) + 1, l, r, tm + 1, tr, num);
	else
		return sum((v << 1), l, tm, tl, tm, num) + sum((v << 1) + 1, tm + 1, r, tm + 1, tr, num);
}

int main()
{
	int n, k;
	cin >> n >> k;
	long long inversion_count = -1;
	int ans = 1;
	for (int j = 0; j < k; ++j)
	{
		long long current_inv = 0;
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			update(1, 1, n, num, 1, j);
			current_inv += sum(1, num + 1, n, 1, n, j);
		}
		if (inversion_count < current_inv)
		{
			inversion_count = current_inv;
			ans = j;
		}
	}


	cout << ans + 1 << endl;
}