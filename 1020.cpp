#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
const double pi = acos(-1.);

double euclid_distance(pair<double , double>& a, pair<double , double>& b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main()
{
	int n;
	double r;
	cin >> n >> r;
	vector <pair <double, double> > v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	long double dist = 2 * pi * r;
	for (int i = 0; i < n; ++i)
		dist += euclid_distance(v[i], v[(i + 1) % n]);
	cout << fixed << setprecision(2) << dist;
}