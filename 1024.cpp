#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return max(a, b) / gcd(a, b) * min(a, b);
}

int main()
{
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		--v[i];
	}

	vector <char> used(n, false);
	int ans = 1;
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			int cycle_len = 1;
			int pos = i;
			while (true)
			{
				used[pos] = true;
				pos = v[pos];
				if (used[pos])
					break;
				++cycle_len;
			}
			ans = lcm(ans, cycle_len);
		}
	}
	cout << ans;
}