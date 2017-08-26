

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	// https://www.acmicpc.net/problem/2997
	// 2997번 문제
	// 네번째 수
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	int num1, num2, num3;

	int temp = 0;

	scanf("%d%d%d", &num1, &num2, &num3);

	if (num2>num1 && num3>num2)
	{
		if (num2 - num1 == num3 - num2)
		{
			temp = num2 - num1;
		}
	}


	printf("%d", num3+temp);

	return 0;
}