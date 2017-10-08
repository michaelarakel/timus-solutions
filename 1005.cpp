#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ending = (1 << v.size()) - 1;
	long long best_answer = 1000 * 1000 * 1000 * 1ll * 1000;
	for (int mask = 0; mask <= ending; ++mask)
	{
		long long curr_ans = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if ((1 << i) & mask)
				curr_ans += v[i];
			else
				curr_ans -= v[i];
		}
		if (best_answer > abs(curr_ans))
			best_answer = abs(curr_ans);
	}
	cout << best_answer << endl;
}