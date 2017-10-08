#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int i, j, fi, fj;

int binary_search(long long start, long long end)
{
	vector <long long> v(abs(j - i) + 1);
	v[0] = fi;
	long long pos = (start + end)/2;
	v[1] = pos;
	for (int k = 2; k < v.size(); k++)
	{
		v[k] = v[k - 1] + v[k - 2];
		if (v[k] > 2000000000)
			return binary_search(start, pos - 1);
		if (v[k] < -2000000000)
			return binary_search(pos + 1, end);
	}
	if (v[v.size() - 1] == fj)
		return pos;
	if (v[v.size() - 1] > fj)
		return binary_search(start, pos - 1);
	return binary_search(pos + 1, end);
}

int main ()
{
	int n;
	map <int, int> fib;
	cin >> i >> fi >> j >> fj >> n;
	if (i > j)
	{
		swap(i, j);
		swap(fi, fj);
	}
	fib[i] = fi;
	fib[j] = fj;
	if (j != i + 1)
		fib[i + 1] = binary_search(-2000000000, 2000000000);
	if (n > i)
		for (int k = i + 2; k <= n; k++)
			fib[k] = fib[k - 1] + fib[k - 2];
	if (n < i)
		for (int k = i - 1; k >= n; --k)
			fib[k] = fib[k + 2] - fib[k + 1];
	cout << fib[n];
}