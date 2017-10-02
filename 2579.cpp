#include <stdio.h>
#include <iostream>

using namespace std;

int cache[10001] = { 0, };
int stair[10001] = { 0, };


// 연속 0번 => cache[n-1]
// 한번도 연속된게 없기 때문에, 직전에 올라온거까지 저장
// 연속 1번 => cache[n-2] + stair[n]
// 직전에 올라 계단을 올라와서는 안됨, 그리고 그 직전에는 상관없음
// 연속 2번 => cache[n-3] + stair[n-1] + stair[n]
// 연속 2번이기 때문에, 그 직전에 올라온거랑 현재 계단은 무조건 올라가야되고 그 직전에는 올라와서는 안됨. 그전에는 상관없음

int main(void)
{

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
		scanf("%d", &stair[i]);

	cache[1] = stair[1];
	cache[2] = stair[1] + stair[2];

	for (int i = 3; i <= T; i++)
	{

		if (cache[i] < cache[i - 2] + stair[i])
			cache[i] = cache[i - 2] + stair[i];
		if (cache[i] < cache[i - 3] + stair[i] + stair[i - 1])
			cache[i] = cache[i - 3] + stair[i] + stair[i - 1];

	}


	printf("%d", cache[T]);


	return 0;
}
