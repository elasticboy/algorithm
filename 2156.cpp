#include <stdio.h>
#include <iostream>

using namespace std;

int cache[10001] = { 0, };
int graphCup[10001] = { 0, };

//cache[n-1] => 현재의 바로 직전까지 포도주를 마신 정보를 저장

// cache[i][j] = graphCup[1] ~ graphCup[n] 
// 0번 연속 : cache[n][0] = max(cache[n-1][0], cache[n-1][1], cache[n-1][2])
// 1번 연속 : cache[n][1] = cache[n-1][0] + graphCup[n] 
// 2번 연속 : cache[n][2] = cache[n-1][1] + graphCup[n]

// cache[n] = graphCup[1] ~ graphCup[n] 포도주
// 0번 연속 : cache[n-1]
// 1번 연속 : cache[n-2] + graphCup[n]
// 2번 연속 : cache[n-3] + graphCup[n-1] + graphCup[n]


int main(void)
{

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
		scanf("%d", &graphCup[i]);

	cache[1] = graphCup[1];
	cache[2] = graphCup[1] + graphCup[2];

	for (int i = 3; i <= T; i++)
	{
		cache[i] = cache[i - 1];

		if (cache[i] < cache[i - 2] + graphCup[i])
			cache[i] = cache[i - 2] + graphCup[i];
		if (cache[i] < cache[i - 3] + graphCup[i - 1] + graphCup[i])
			cache[i] = cache[i - 3] + graphCup[i - 1] + graphCup[i];
	}



	printf("%d", cache[T]);

	return 0;
}
