#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> b(n);

	for (int i = n - 1; i>= 0; --i)
		cin >> a[i] >> b[i];
	int carry = 0;

	while (a.size() > 1 && a.back() == 0)
		a.pop_back();

	while (b.size() > 1 && b.back() == 0)
		b.pop_back();

	for (int i = 0; i < max(a.size(), b.size()) || carry; ++i)
	{
		if (i == a.size())
			a.push_back(0);
		int cur = a[i] + carry;
		if (i < b.size())
			cur += b[i];
		carry = (cur >= 10);

		if (carry)
			cur -= 10;
		a[i] = cur;
	}
	while (a.size() < n)
		a.push_back(0);
	int num = 0;
	while (num < n)
	{
		cout << a[a.size() - 1 - num];
		++num;
	}
}