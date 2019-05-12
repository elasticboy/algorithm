#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
#define ARR_MAX 15+1
#define TERM_MAX 5+1
#define PROFIT_MAX 1000

int arr[ARR_MAX][TERM_MAX] = { 0, };
int N = 0;
int res = 0;
//(1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1, 000)

int max(int res, int cur_res) {
	if (cur_res > res)
		return cur_res;
	else
		return res;
}

int _term(int n) {
	//현재 인덱스에 비용이 있는 지 탐색 중 
	for (int i = 1;i <= TERM_MAX;i++)
	{
		int term = 0;
		//비용이 있으면 무조건 하나는 있다
		if (arr[n][i] > 0)
			return i;
	}
	return 0;
}

void dfs(int n, int term, int profit) {
	profit += arr[n][term];
	res = max(res, profit);
	int cur_n = n + term;
	for (int i = cur_n;i <= N;i++)
	{
		int term = _term(i);
		if (i == N && term == 1)
		{
			//마지막 날짜에 걸렸을 때, 기간이 1이라면
			//마지막도 포함한다.
			profit += arr[i][term];
			res = max(res, profit);
			return;
		}

		//다음 경우가 범위가 넘어갈때
		if (i >= N)
			return;
		//term이 1이 아닌 경우, i는 일정하기에, 
		//term이 1이 아니면 N+1은 조건을 만족하지 않는다. 
		if (i + term > N + 1)
			return;

		dfs(i, term, profit);
	}
}

int main() {

	freopen("test_case/4.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1;i <= N;i++) {
		int term, profit;
		scanf("%d%d", &term, &profit);
		arr[i][term] = profit; //True
	}

	dfs(1, 0, 0);
	printf("%d", res);
}