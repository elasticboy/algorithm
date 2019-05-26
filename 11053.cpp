#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#define ARR_MAX 1000
int arr[ARR_MAX] = { 0, };
int dp[ARR_MAX + 1] = { 0, };
int res = 0;
int N;

int main() {
	//freopen("test_case/1.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) 
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i]>arr[j]) {
				if (min < dp[j])
					min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (res < dp[i])
			res = dp[i];
	}

	printf("%d\n", res);

	return 0;
}