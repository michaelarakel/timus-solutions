#include <iostream>
#include <vector>

using namespace std;

int n;
long long counter = 0;

bool check(const vector <int>& v)
{
	int diff = 0;
	for (int i = 0; i < v.size() / 2; ++i)
		diff += v[i];
	for (int i = v.size() / 2 + (n % 2); i < v.size(); ++i)
		diff -= v[i];
	return (diff == 0);
}

void rec(vector <int>& v)
{
	if (v.size() == n)
	{
		if (check(v))
			++counter;
		return;
	}
	for (int i = 0; i <= 9; ++i)
	{
		v.push_back(i);
		rec(v);
		v.pop_back();
	}
}

int main()
{
	int a[10] = { 10, 10, 100, 670, 6700, 55252, 552520, 4816030, 48160300 };
	cin >> n;
	cout << a[n - 1];
	/*vector <int> v;
	rec(v);*/
	//cout << counter;
}