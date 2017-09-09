#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_VERTEX 20001

int K, V, E;
vector<int> Graph[MAX_VERTEX];
vector<int> color(MAX_VERTEX, 0);


bool BFS(int start)
{
	queue<int> q;

	q.push(start);
	color[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < Graph[cur].size(); i++)
		{
			int next = Graph[cur][i];

			if (color[next] == 0)
			{
				color[next] = ~color[cur];
				q.push(next);
			}

			else
			{
				if (color[next] == color[cur])
					return false;
			}
		}
	}

	return true;
}


int main(void)
{
	// https://www.acmicpc.net/problem/1707
	// 1707번 문제
	// 이분 그래프
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> K;

	while (K--)
	{
		int src, dst;
		bool res = true;

		cin >> V >> E;

		for (int i = 1; i <= V; i++)
			Graph[i].clear();

		color.assign(V + 1, 0);

		for (int i = 0; i < E; i++)
		{
			cin >> src >> dst;
			Graph[src].push_back(dst);
			Graph[dst].push_back(src);
		}

		for (int i = 1; i <= V; i++)
		{
			if (color[i] == 0)
			{
				res = BFS(i);
				if (!res)    
					break;
			}
		}


		printf(!res ? "NO\n" : "YES\n");
	}
	return 0;
}