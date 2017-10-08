#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int divisors[10];

int main()
{
	int n;
	cin >> n;
	if (n <= 9)
	{
		if (n == 0)
			cout << 10;
		else
			cout << n;
		cout << endl;
		return 0;
	}
	vector <int> ans;

	for (int i = 9; i >= 2; --i)
	{
		while (n % i == 0)
		{
			ans.push_back(i);
			n /= i;
		}
	}

	if (n > 1)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i];
	cout << endl;
}