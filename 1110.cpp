#include <iostream>
using namespace std;

int mod;

int bin_pow(int a, int b)
{
	int res = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
		{
			res = (res * 1ll * a) % mod;
		}
		a = (a * 1ll * a) % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	int n, y;
	cin >> n >> mod >> y;
	y %= mod;

	bool got_answer = false;
	for (int x = 0; x < mod; ++x)
	{
		if (bin_pow(x, n) == y)
		{
			got_answer = true;
			cout << x << ' ';
		}
	}
	if (!got_answer)
		cout << -1;
	cout << endl;
	return 0;
}