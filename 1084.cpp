#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = acos(-1.);

int main()
{
	int fence, radius;
	cin >> fence >> radius;
	double area;
	if (2 * radius <= fence)
		area = pi * radius * radius;
	else if (fence <= radius * sqrt(2))
		area = fence * fence;
	else
	{
		double a = fence / 2.;
		double sqr = sqrt(radius * 1. * radius - a * a);

		area = 2 * fence * sqr + 2 * radius * radius * (asin(a / radius) - asin(sqr / radius));
	}
	cout << fixed << setprecision(3) << area;
}