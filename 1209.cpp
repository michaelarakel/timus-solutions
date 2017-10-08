#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

bool binary_search(int first, int last, int n)
{
	if (first > last)
		return false;
	int pos = (first + last)/2;
	if (v[pos] == n)
		return true;
	if (n > v[pos])
		return binary_search(pos + 1, last, n);
	if (n < v[pos])
		return binary_search(first, pos - 1, n);
}

int main ()
{
	v.push_back(1);
	for (int i = 1; i < 65536; i++)
		v.push_back(v[i - 1] + i);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (binary_search(0, 65535, num))
			cout << '1';
		else
			cout << '0';
		cout << " ";
	}
}