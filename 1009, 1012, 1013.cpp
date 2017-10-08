#include <iostream>
#include <vector>

using namespace std;

const int base = 1000 * 1000 * 1000;

vector <int> sum (const vector <int>& a, const vector <int>& b)
{
	vector <int> c = a;
	int mind = 0;
	for (int i = 0; i < max(c.size(), b.size()) || mind; ++i)
	{
		if (i == c.size())
			c.push_back(0);
		c[i] += mind;
		if (i < b.size())
			c[i] += b[i];
		mind = c[i] >= base;
		if (mind)
			c[i] -= base;
	}
	return c;
}

void multip (vector <int>& a, const int n)
{
	int mind = 0;
	for (int i = 0; i < a.size() || mind; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		long long curr = a[i] * 1ll * n + mind;
		a[i] = (int) (curr % base);
		mind = (int) (curr / base);
	}
	while (a.back() == 0 && a.size() > 1)
		a.pop_back();
}

void print (const vector <int>& a)
{
	cout << (a.empty()? 0 : a.back());
	for (int i = (int) a.size() - 2; i >= 0; --i)
		printf("%09d", a[i]);
}

int main ()
{
	int n, k;
	cin >> n >> k;
	vector <vector <int> > v;
	vector <int> temp(1, 1);
	v.push_back(temp);
	temp[0] = k - 1;
	v.push_back(temp);
	for (int i = 2; i <= n; ++i)
	{
		vector <int> temp = sum(v[i - 2], v[i - 1]);
		multip (temp, k - 1);
		v.push_back(temp);
	}
	print(v[n]);
}