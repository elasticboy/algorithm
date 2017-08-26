

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define DIAGONAL_MIN 5 
#define DIAGONAL_MAX 1000

#define HEIGHT_MIN 1 
#define HEIGHT_MAX 99

#define WIDTH_MIN 2
#define WIDTH_MAX 100

int diagonal = 0;
int width_ = 0;
int height_ = 0;

int main(void)
{
	// https://www.acmicpc.net/problem/1297
	// 1297번 문제
	// TV 크기 
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);


	scanf("%d", &diagonal);
	scanf("%d", &height_);
	scanf("%d", &width_);


	for (int i = 1; i < 100; i++)
	{
		for (int j = 1; j < 100; j++)
		{
			if (  pow(width_ * i, 2)  + pow(height_ * j, 2)    == pow(diagonal,2))
			{
				printf("%f %f\n", i, j);
				return 0;
			} 
		}
	}


	return 0;
}