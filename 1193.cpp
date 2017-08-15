

#include <stdio.h>
#include <iostream>

using namespace std;


int N;
int total = 0;

#define MAX 100000


int main(void)
{
	// https://www.acmicpc.net/problem/1193
	// 1193번 문제
	// 분수찾기

	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	scanf("%d", &N);

	bool isOdd = false;
	int temp = 0;
	int count = 0;

	for (int i = 1; i <= MAX; i++)
	{
		total += i;
		isOdd = !isOdd;

		for (int j = 1; j <= i; j++)
		{
			count++;

			if (isOdd)
			{
				if (count == N)
				{
					printf("%d%s%d ", (i - j) + 1, "/", j);
					return 0;
				}
				
			}

			else
			{
				if (count == N)
				{
					printf("%d%s%d ", j, "/", (i - j) + 1);
					return 0;
				}
				
			}
		}


		if (total >= N)
		{
			break;
		}
	}



	return 0;
}