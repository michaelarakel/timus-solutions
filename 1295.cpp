#include <iostream>
using namespace std;

const int base = 100000;

int binpow(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
		{
			res = (res * 1ll * a) % base;
		}
		a = (a * 1ll * a) % base;
		n >>= 1;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int temp = (1 + binpow(2, n) + binpow(3, n) + binpow(4, n)) % base;
	if (temp == 0)
	{
		cout << 5;
		return 0;
	}
	int counter = 0;
	while (temp % 10 == 0)
	{
		++counter;
		temp /= 10;
	}
	cout << counter;
}