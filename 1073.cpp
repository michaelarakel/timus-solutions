#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//const int maxn = 60001;
//int dp[maxn];
const double eps = 1e-8;

int main()
{
	long long n;
	cin >> n;
	int temp = sqrt(n * 1.) + eps;
	if (temp * 1ll * temp == n)
	{
		cout << 1;
		return 0;
	}
	else
	{
		long long temp = 4;
		while (n % temp == 0)
			temp *= 4;
		temp /= 4;
		n /= temp;
		if (n % 8 == 7)
		{
			cout << 4;
			return 0;
		}

		for (long long i = 2; i * i <= n; ++i)
		{
			int counter = 0;
			while (n % i == 0)
			{
				n /= i;
				++counter;
			}
			if (counter != 0 && (i != 2) && (i % 4 == 3) && ((counter & 1)))
			{
				cout << 3;
				return 0;
			}
		}
		if (n > 1)
		{
			if (n % 4 == 3)
			{
				cout << 3;
				return 0;
			}
		}
		cout << 2;
	}
}