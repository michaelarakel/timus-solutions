#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000 * 1000;
int lp[maxn + 1];
vector <int> pr;

inline void init()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= maxn; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int main()
{
	init();
	int start, end;
	cin >> start >> end;
	if (start == 1)
	{
		cout << 1;
		return 0;
	}
	int pos = lower_bound(pr.begin(), pr.end(), start) - pr.begin();
	int prime_ans = 0;
	for (auto it : pr)
	{
		if (start <= it && it <= end)
			prime_ans = it;
		if (it > end)
			break;
	}
	if (prime_ans)
	{
		cout << prime_ans << endl;
		return 0;
	}

	double triviality = 1000 * 1000 * 1000;
	int ans = 0;
	for (int i = start; i <= end; ++i)
	{
		int temp = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			if (i % j == 0)
				temp += j;
		}
		if (triviality * i > temp)
		{
			triviality = temp;
			triviality /= i;
			ans = i;
		}
	}
	cout << ans;
}