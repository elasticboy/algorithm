#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
#define ARR_MAX 15
#define PROFIT_MAX 1000

int term[ARR_MAX + 1] = {0,};
int profit[ARR_MAX + 1] = { 0, };;
int dp[ARR_MAX + 1] = { 0, };
//(1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1, 000)
int N = 0;

int _max(int val1, int val2) {
	if (val1 > val2) 
		return val1;
	return val2;
}

int Dp(int day) {
	if (day == N + 1)
		return 0;
	if (day > N + 1)
		return (-1)*1111111;
	if (dp[day] > 0) 
		return dp[day];
	//현재 날짜를 고르지 않고 다른 날짜로 넘어갈 경우와 현재 날짜를 선택하고 넘어갈 경우를 나눈다. 
	dp[day] = _max( Dp(day+1), Dp(day+term[day])+profit[day] );
	return dp[day];
}

int main() {

	freopen("test_case/4.txt", "r", stdin);
	scanf("%d", &N);
	//입력값 받기
	for (int i = 1;i <= N;i++) 
	{
		int t=0, p = 0;
		scanf("%d%d", &t, &p);
		term[i] = t;
		profit[i] = p;
	}
	int ans = Dp(1);
	printf("%d", ans);
}