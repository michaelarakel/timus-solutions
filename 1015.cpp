#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int sign(long long x)
{
	if (x == 0)
		return 0;
	return x / abs(x);
}

struct point
{
	point(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
	long long x;
	long long y;
	long long z;

	static point corss_product(const point& a, const point& b)
	{
		return point(a.y * b.z - a.z * b.y, -(a.x * b.z - a.z * b.x), a.x * b.y - a.y * b.x);
	}

	static long long dot_product (const point& lhs, const point& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	static long long triple_product(const point& a, const point& b, const point& c)
	{
		return dot_product(a, corss_product(b, c));
	}

	point operator - (const point& p) const
	{
		return point(x - p.x, y - p.y, z - p.z);
	}
};

struct plane
{
	plane(const point& p1, const point& p2, const point& p3)
	{
		point norm = point::corss_product(p2 - p1, p3 - p1);
		a = norm.x;
		b = norm.y;
		c = norm.z;
		d = -point::dot_product(norm, p1);
	}

	long long orientation(const point& p) const
	{
		return sign(a * p.x + b * p.y + c * p.z + d);
	}
	long long a;
	long long b;
	long long c;
	long long d;
};

void printVector(const std::string& name, int a, int b, int c)
{
	std::cout << name << " = (" << a << ", " << b << ", " << c << ")\n";
}

int main()
{
	freopen("theorem_check.txt", "w", stdout);
	const int maxn = 30;
	for (int gamma1 = 15; gamma1 <= maxn; ++gamma1)
	for (int gamma2 = 1; gamma2 <= maxn; ++gamma2)
	for (int gamma3 = 1; gamma3 <= maxn; ++gamma3)
	for (int alpha1 = 1; alpha1 < gamma1; ++alpha1)
	for (int alpha2 = 1; alpha2 < gamma2; ++alpha2)
	for (int alpha3 = 1; alpha3 < gamma3; ++alpha3)
	for (int beta1 = 1; beta1 < gamma1; ++beta1)
	for (int beta2 = 1; beta2 < gamma2; ++beta2)
	for (int beta3 = 1; beta3 < gamma3; ++beta3)
	for (int m1 = 1; m1 < gamma1; ++m1)
	for (int m2 = 1; m2 < gamma2; ++m2)
	for (int m3 = 1; m3 < gamma3; ++m3)
	{
		int detA1 = gamma1 * (alpha2 * beta3 - alpha3 * beta2);
		if (detA1 <= 0)
			break;
		int detA2 = -gamma2 * (alpha1 * beta3 - alpha3 * beta1);
		int detA3 = gamma3 * (alpha1 * beta2 - alpha2 * beta1);
		if (detA2 == 0 || detA3 == 0)
			break;
		if (alpha1 * (m2 + 1) >= alpha2 * (m1 + 1) ||
			alpha3 * (m2 + 1) >= alpha2 * (m3 + 1))
			continue;
		if (beta1 * (m3 + 1) >= beta3 * (m1 + 1) ||
			beta2 * (m3 + 1) >= beta3 * (m2 + 1))
			continue;

		if (beta3 * (alpha1 - gamma1) - alpha3 * (beta1 - gamma1) <= 0 ||
			beta2 * (alpha1 - gamma1) - alpha2 * (beta1 - gamma1) <= 0)
			break;
		if ((beta3 * (alpha2 - gamma2) - alpha3 * (beta2 - gamma2)) * 1ll * detA2 <= 0 ||
			(alpha1 * (alpha2 - gamma2) - beta1 * (alpha2 - gamma2)) * 1ll * detA2 <= 0)
			break;
		if ((alpha2 * (beta3 - gamma3) - beta2 * (alpha3 - gamma3)) * 1ll * detA3 <= 0 ||
			(alpha1 * (beta3 - gamma3) - beta1 * (alpha3 - gamma3)) * 1ll * detA3 <= 0)
			break;

		if (gamma1 * gamma2 - alpha1 * alpha3 * gamma2 - alpha2 * alpha3 * gamma1 <= 0)
			break;

		if (gamma1 * gamma3 - beta1 * beta2 * gamma3 - beta2 * beta3 * gamma1 <= 0)
			break;

		if (gamma2 * gamma3 - beta1 * beta2 * gamma3 - beta1 * beta3 * gamma2 <= 0)
			break;

		long long x = (m1 + 1) * 1ll * detA1 / gamma1 + (m2 + 1) * 1ll * detA2 / gamma2 + (m3 + 1) * 1ll * detA3 / gamma3;
		if (x <= 0)
		{
			printVector("gamma", gamma1, gamma2, gamma3);
			printVector("alpha", alpha1, alpha2, alpha3);
			printVector("beta", beta1, beta2, beta3);
			printVector("m", m1, m2, m3);
			std::cout << std::endl;
		}
	}
}