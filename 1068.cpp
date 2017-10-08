#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	//if (n == 0 || n == 1)
	//	cout << 1;
	if (n >= 1)
		cout << (n * 1ll * (n + 1)) / 2;
	else
	{
		int temp = abs(n);
		cout << 1 - (temp * 1ll * (temp + 1)) / 2;
	}
}