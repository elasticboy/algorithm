

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define ARR_MIN_SIZE 1
#define ARR_MAX_SIZE 101

int arr[ARR_MAX_SIZE][ARR_MAX_SIZE];

typedef struct Rect
{
	int i;
	int j;

	int x;
	int y;
}Rect;



int main(void)
{
	// https://www.acmicpc.net/problem/2167
	// 2167번 문제
	// 2차원배열의 합
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	//arr[ARR_MAX_SIZE][ARR_MAX_SIZE] = { 0 };

	int row_size, col_size;
	scanf("%d%d", &row_size, &col_size);

	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int area_pos_size;

	scanf("%d", &area_pos_size);

	Rect* rect = (Rect*)malloc(sizeof(Rect)*area_pos_size);


	
	for (int k= 0; k < area_pos_size;k++)
	{
		scanf("%d%d%d%d", &rect[k].i, &rect[k].j, &rect[k].x, &rect[k].y);

		int total = 0;

		for (int i = rect[k].i - 1 ; i < rect[k].x; i++)
		{
			for (int j = rect[k].j -1 ; j < rect[k].y; j++)
			{
				total += arr[i][j];
			}
		}

		printf("%d\n", total);
	}


	return 0;
}