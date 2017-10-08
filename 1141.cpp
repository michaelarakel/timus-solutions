#include <iostream>

using namespace std;

inline int bin_pow(int a, int n, int mod)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * 1ll * a) % mod;
		a = (a * 1ll * a) % mod;
		n >>= 1;
	}
	return res;
}

int gcd(int a, int b, int& x, int& y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return a;
	}
	int x1, y1;
	int g = gcd(b % a, a, x1, y1);
	y = x1;
	x = y1 - (b / a) * x1;
	return g;
}

int inverse(int a, int mod)
{
	int inv, temp;
	gcd(a, mod, inv, temp);
	return inv;
}

inline void solve()
{
	int n, c, e;
	cin >> e >> n >> c;
	int p, q;

	for (int i = 2; i * i <= n; ++i)
	if (n % i)
	{
		p = i;
		q = n / i;
		break;
	}

	int d = inverse(e, (p - 1) * (q - 1));
	cout << bin_pow(c, d, n) << endl;
}

int main()
{
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; ++i)
		solve();
}