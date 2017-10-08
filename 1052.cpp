#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
	point(int x, int y) : x(x), y(y) {}
	int x;
	int y;
};

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

struct line
{
	line(const point& x, const point& y)
	{
		a = y.y - x.y;
		b = x.x - y.x;
		c =  - (a * x.x + b * x.y);
		int g = gcd(gcd(abs(a), abs(b)), abs(c));
		a /= g;
		b /= g;
		c /= g;
	}
	int put_multiplied_by(const point& x, int multip) const
	{
		return (a * multip * 1ll * x.x + b * multip * 1ll * x.y + c * 1ll * multip);
	}
	bool operator == (const line& l)
	{
		return l.put_multiplied_by(point(-c, 0), a) == 0 &&
				l.put_multiplied_by(point(0, -c), b) == 0;
	}
	bool belongs(const point& a)
	{
		return (put_multiplied_by(a, 1) == 0);
	}
	int a;
	int b;
	int c;
};

int main()
{
	int n;
	cin >> n;
	vector <point> v;
	for (int i = 0; i < n; ++i)
	{
		point a(0, 0);
		cin >> a.x >> a.y;
		v.push_back(a);
	}
	int max = -1;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = i + 1; j < v.size(); ++j)
		{
			line temp(v[i], v[j]);
			int counter = 0;
			for (int k = 0; k < v.size(); ++k)
			{
				if (temp.belongs(v[k]))
					++counter;
			}
			if (max < counter)
				max = counter;
		}
	}
	cout << max << endl;
}