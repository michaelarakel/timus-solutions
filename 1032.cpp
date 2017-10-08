#include <iostream>
#include <vector>

using namespace std;

void print(const vector <int>& v, int start, int end)
{
	cout << end - start + 1 << endl;
	for (int i = start; i <= end; ++i)
		cout << v[i] << endl;
	return;
}

int main()
{
	int n;
	cin >> n;
	vector <int> v(n);
	vector <int> partial_sums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		partial_sums[i] = v[i];
		if (i > 0)
			partial_sums[i] += partial_sums[i - 1];
		partial_sums[i] %= n;
	}
	vector <int> used(n, -1);
	for (int i = 0; i < partial_sums.size(); ++i)
	{
		if (partial_sums[i] == 0)
		{
			print(v, 0, i);
			break;
		}
		if (used[partial_sums[i]] != -1)
		{
			print(v, used[partial_sums[i]] + 1, i);
			break;
		}
		used[partial_sums[i]] = i;
	}
}