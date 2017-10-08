#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

void primediv (int num, vector <int>& res)
{
	for (int i = 0; v[i] <= num && num != 1; i++)
		if (num % v[i] == 0)
		{
			res[i]++;
			num /= v[i];
			--i;
		}
}

int main ()
{
	const int size = 500000;
	vector <char> prime(size + 1, true);
	prime[0] = prime[1] = false;
	v.push_back(2);
	for (int i = 3; i <= size; i+= 2)
	{
		if (prime[i])
		{
			v.push_back(i);
			if (i <= size/i)
				for (int j = i*i; j <= size; j+= i)
					prime[j] = false;
		}
	}
	int n, m;
	cin >> n >> m;
	if (m >= n/2)
		m = n - m;
	vector <int> a(n/2 + 1);
	vector <int> b(n/2 + 1);
	for (int i = n - m + 1; i <= n; i++)
		primediv(i, a);
	for (int i = 2; i <= m; i++)
		primediv(i, b);
	int count = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] > b[i])
			count++;
	cout << count;
}