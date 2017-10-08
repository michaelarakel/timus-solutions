#include<iostream>
using namespace std;
int res(int a, int b)
{
	for (int i = 1; i <= 10001; i++)
	{
		long long x = (i*a);
		long long y = (i*b);
		long long z = ((long long)(y / 10000)) * 10000;
		if ((x<z) && (z<y))
		{
			return i;
		}
	}
}
int main()
{
	double a, b;
	cin >> a >> b;

	int a1 = (int)(100.0*a + 0.5);
	int b1 = (int)(100.0*b + 0.5);
	cout << res(a1, b1) << endl;
	return 0;
}