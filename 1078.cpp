#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
	point(int x = 0, int y = 0) : x(x), y(y) {}
	point(const point& p)
	{
		x = p.x;
		y = p.y;
	}
	bool operator == (const point& p)
	{
		return x == p.x &&
			y == p.y;
	}
	int x;
	int y;
};

struct segment 
{
	segment(const point& a = point(), const point& b = point()) : a(a), b(b) {}
	segment(const segment& s)
	{
		a = (s.a);
		b = (s.b);
	}
	bool operator == (const segment& s)
	{
		return a == s.a &&
			b == s.b;
	}
	bool contains(const segment& s)
	{
		return a.x < s.a.x && s.b.x < b.x;
	}
	point a;
	point b;
};

inline long long dist(const segment& a)
{
	return (a.a.x - a.b.x) * 1ll * (a.a.x - a.b.x) + (a.a.y - a.b.y) * 1ll * (a.a.y - a.b.y);
}

bool comp_by_dist(const segment& a, const segment& b)
{
	return dist(a) < dist(b);
}

int dp[500];
int pre[500];
segment v[500];

int main()
{
	int n;
	cin >> n;
	vector <pair <segment, int> >input;
	for (int i = 0; i < n; ++i)
	{
		point a, b;
		cin >> a.x >> b.x;
		input.push_back(make_pair(segment(a, b), i + 1));
		v[i] = (segment(a, b));
	}
	sort(v, v + n, comp_by_dist);

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		pre[i] = -1;
		for (int j = 0; j < i; ++j)
			if (v[i].contains(v[j]))
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
	}

	int pos = 0;
	int ans = 1;

	for (int i = 0; i < n; ++i)
	{
		if (ans < dp[i])
		{
			ans = dp[i];
			pos = i;
		}
	}
	cout << ans << endl;
	vector <int> path;
	for (int i = pos; i != -1; i = pre[i])
		path.push_back(i);
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); ++i)
	{
		for (int j = 0; j < input.size(); ++j)
		{
			if (input[j].first == v[path[i]])
			{
				cout << input[j].second;
				if (i != path.size() - 1)
					cout << ' ';
				break;
			}
		}
	}
}