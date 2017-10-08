#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a;
	int fact[10000] = { 0, };
	for (int i = 0; i < 10; ++i)
	{
		cin >> a;
		for (int i = 2; i * i <= a; ++i)
		{
			while (a % i == 0)
			{
				++fact[i];
				a /= i;
			}
		}
		if (a > 1)
			++fact[a];
	}
	int ans = 1;

	for (int i = 0; i < 10000; ++i)
	{
		if (fact[i] > 0)
		{
			ans *= (fact[i] + 1);
			ans %= 10;
		}
	}
	cout << (ans) % 10 << endl;
}