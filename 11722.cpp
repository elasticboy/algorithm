#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;


#define NUM_MAX 1000

int numArr[NUM_MAX] = { 0, };
int numSize = 0;



int main(void)
{
	// https://www.acmicpc.net/problem/11722
	// 11722번 문제
	// 가장긴감소하는부분수열
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	scanf("%d", &numSize);

	int preNum = 0;

	for (int i = 0; i < numSize; i++)
		scanf("%d", &numArr[i]);

	preNum = numArr[0];
	int* part = (int*)malloc(sizeof(int)*numSize);


	for (int i = 0; i < numSize; i++)
		part[i] = 1;

	for (int i = 0; i < numSize; i++)
	{
		vector<int> vector;
		vector.push_back(numArr[i]);
		int cur_num = numArr[i];

		for (int j = i+1; j < numSize; j++)
		{
			if (cur_num > numArr[j] )
			{
				vector.push_back(numArr[j]);
				cur_num = numArr[j];
			}
		}

		sort(vector.begin(), vector.end());

		for (int j = 0; j < vector.size(); j++)
		{
			printf("%d : %d ",i ,vector[j]);
		}

		printf("\n");
		
	}

	return 0;
}