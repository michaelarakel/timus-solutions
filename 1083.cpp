#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int k = s.size();
	long long ans = n;
	while (n > k)
	{
		n -= k;
		ans *= n;
	}
	cout << ans << endl;
}