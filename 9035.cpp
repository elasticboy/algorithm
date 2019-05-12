#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
#define DP_MAX 1000
int dp[DP_MAX + 1] = { 0, };

int main() {
	//freopen("test_case/1.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	dp[1] = 1; dp[2] = 2, dp[3] = 4;
	for (int test_case = 0;test_case < T;test_case++) {
		int cur_num = 0;
		scanf("%d", &cur_num);
		for(int i=4;i<=cur_num;i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		printf("%d\n", dp[cur_num]);
	}
}