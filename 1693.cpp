#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


enum Color
{
	A = 1, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U,
	SIZE
};


#define MAX 100001 
#define INF 987654321

vector<int> graph[MAX];
bool visited[MAX];
int cache[MAX][Color::SIZE];

int GetColor(int pos, Color color)
{
	int& ret = cache[pos][color];

	if (ret != -1)
		return ret;

	visited[pos] = true;
	ret = (int)color;

	for (int i = 0; i < graph[pos].size(); i++)
	{
		if (visited[graph[pos][i]]) 
			continue;

		int choose = INF;
		for (int j = Color::A; j < Color::SIZE; j++)
		{
			if (j != color)
			{
				if (GetColor(graph[pos][i], (Color)j) < choose)
					choose = GetColor(graph[pos][i], (Color)j);
			}
		}

		ret += choose;
	}

	visited[pos] = false;

	return ret;
}

int main(void)
{

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	cin >> T;
	
	int test_case = T;

	for (int i = 0; i < test_case-1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		graph[n1].push_back(n2);
		graph[n2].push_back(n1);

	}

	memset(cache, -1, sizeof(cache));

	int ans = INF;

	for (int i = Color::A; i < Color::SIZE; i++)
	{
		if (ans > GetColor(1, (Color)i))
			ans = GetColor(1, (Color)i);
	}

	cout << ans;

	return 0;
}

