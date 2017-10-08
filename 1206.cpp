#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int base = 1000 * 1000 * 1000;

vector <int> mul(const vector <int>& c, int b)
{
	vector <int> a(c);
	int carry = 0;

	for (int i = 0; i < a.size() || carry; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		long long cur = a[i] * 1ll * b + carry;
		a[i] = (int)(cur % base);
		carry = (int)(cur / base);
	}
	return a;
}

void print(const vector <int> & v)
{
	cout << v.back();
	for (int i = (int)v.size() - 2; i >= 0; --i)
		printf("%09d", v[i]);
}

int main()
{
	vector <vector <int> > ans;
	ans.push_back(vector <int>(1, 36));
	while (ans.size() <= 50)
		ans.push_back(mul(ans[ans.size() - 1], 55));
	int k;
	cin >> k;
	print(ans[k - 1]);
}