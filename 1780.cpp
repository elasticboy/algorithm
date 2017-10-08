

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define ARR_MAX 2300 // 3^7 + 1 = 2187 > 

int Paper[ARR_MAX][ARR_MAX] = { 0, };
int Res[3] = { 0, };
int arrSize;
int og_value = 0, paper_value = 0;

void DividePaper(pair<int, int>startPos, pair<int, int> endPos);

void DividePaper(pair<int,int>startPos, pair<int, int> endPos)
{
	og_value = Paper[startPos.second][startPos.first];

	for (int y = startPos.second; y < endPos.second; y++)
	{
		for (int x = startPos.first; x < endPos.first; x++)
		{
			paper_value = Paper[y][x];
			if (og_value != paper_value)
			{
				int segment = ((endPos.first - startPos.first) + 1) / 3;
				
				int limit_x = endPos.first - segment + 1;
				int limit_y = endPos.second - segment + 1;

				for (int i = startPos.second; i <= limit_y; i+=segment)
				{
					for (int j = startPos.first; j <= limit_x; j+=segment)
					{
						DividePaper(make_pair(i, j), make_pair(i + segment - 1, j + segment - 1));
					}
				}

				return;
			}

			og_value = paper_value;
		}
	}

	Res[paper_value + 1]++;
}

int main(void)
{
	// https://www.acmicpc.net/problem/1780
	// 1780번 문제
	// 종이의 개수
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &arrSize);


	for (int i = 1; i <= arrSize; i++)
		for (int j = 1; j <= arrSize; j++)
			scanf("%d", &Paper[i][j]);

	DividePaper(make_pair(1, 1), make_pair(arrSize, arrSize));

	for (int i = 0; i < 3; i++)
		printf("%d\n", Res[i]);

	return 0;
}