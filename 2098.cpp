

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct SalesManGraph
{
	int value;
	bool isVisited;

}SalesManGraph;

SalesManGraph** graphArr;

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	scanf("%d", &T);

	graphArr = (SalesManGraph**)malloc(sizeof(SalesManGraph*)*T);
	for (int i = 0; i < T; i++)
	{
		graphArr[i] = (SalesManGraph*)malloc(sizeof(SalesManGraph)*T);
	}

	queue<SalesManGraph> queue;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			scanf("%d", &graphArr[i][j].value);
			graphArr[i][j].isVisited = false;

			if (graphArr[i][j].value != 0)
			{
				queue.push(graphArr[i][j]);
			}
		}
	}

	int count = 0;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			

			while (!queue.empty())
			{
				SalesManGraph front = queue.front();
				queue.pop();
				count++;
			}

		}

	}



	printf("%d",count);

	return 0;
}





