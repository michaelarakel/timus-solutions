#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <long long> fib;
	fib.push_back(1);
	fib.push_back(2);
	for (int i = 2; i <= 45; ++i)
		fib.push_back(fib[i - 1] + fib[i - 2]);
	int n, k;
	cin >> n >> k;
	if (k > fib[n])
	{
		cout << -1;
		return 0;
	}
	--k;
	--n;
	vector <char> ans;

	while (n >= 0)
	{
		if (k >= fib[n])
		{
			k -= fib[n];
			ans.push_back('1');
		}
		else
			ans.push_back('0');
		--n;
	}
	if (k > 0)
		cout << -1;
	else
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i];
}