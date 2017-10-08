#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	long long ans = 0;
	for (int i = 0; i <= v.size() / 2; ++i)
		ans += (v[i] / 2) + 1;
	cout << ans << endl;
}