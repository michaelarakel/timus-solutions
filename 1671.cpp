#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 100000;

int n, m;

//for dsu
int parent[maxn];
int height[maxn];

void dsu_init()
{
	for (int i = 0; i < maxn; ++i)
	{
		parent[i] = i;
		++height[i];
	}
}

int dsu_find(int v)
{
	if (parent[v] == v)
		return v;
	return parent[v] = dsu_find(parent[v]);
}

bool dsu_unite(int u, int v)
{
	u = dsu_find(u);
	v = dsu_find(v);
	if (u == v)
		return false;
	if (height[v] < height[u])
		swap(u, v);
	parent[v] = u;
	if (height[u] == height[v])
		++height[u];
	return true;
}

bool bucket[maxn];

int components_count()
{
	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!bucket[dsu_find(i)])
			++counter;
		bucket[parent[i]] = true;
	}
	return counter;
}

int query_order[maxn];
bool edges_deleted[maxn];
pair <int, int> edges[maxn];
int query_answer[maxn];

int main()
{
	dsu_init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &edges[i].first, &edges[i].second);
		--edges[i].first;
		--edges[i].second;
	}

	int queries;
	scanf("%d", &queries);
	//vector <int> query_order(queries);
	//vector <char> edges_deleted(m, false);
	for (int i = 0; i < queries; ++i)
	{
		scanf("%d", &query_order[i]);
		--query_order[i];
		edges_deleted[query_order[i]] = true;
	}
	for (int i = 0; i < m; ++i)
	if (!edges_deleted[i])
		dsu_unite(edges[i].first, edges[i].second);

	int components = components_count();
	for (int i = queries - 1; i >= 0; --i)
	{
		query_answer[i] = (components);
		pair <int, int> edge = edges[query_order[i]];
		if (dsu_unite(edge.first, edge.second))
				--components;
	}

	for (int i = 0; i < queries; ++i)
		printf("%d ", query_answer[i]);
}