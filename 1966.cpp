

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int arr[101];

typedef struct Print
{
	int curPos;
	int index;
	int value;
}Print;


int main(void)
{
	// https://www.acmicpc.net/problem/1966
	// 1966번 문제
	// 프린터 큐
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	int T;
	scanf("%d", &T);

	while (T--)
	{
		arr[101] = { 0 };
		int sort[101] = { 0 };

		int curPos, size; 
		scanf("%d%d", &size, &curPos);

		Print* og_print = (Print*)malloc(sizeof(Print)*size);
		Print* sort_print = (Print*)malloc(sizeof(Print)*size);

		for (int i = 0;i<size; i++)
		{
			og_print[i].index = i;
			og_print[i].curPos = curPos;
			scanf("%d", &og_print[i].value);
		}


		for (int i = 0; i<size; i++)
		{
			sort_print[i].curPos = og_print[i].curPos;
			sort_print[i].index = og_print[i].index;
			sort_print[i].value = og_print[i].value;
		}

		

		///////////////////////sort
		for (int i = 0; i<size; i++)
		{
			for (int j = 0 ; j<i; j++)
			{
				if (og_print[i].value > og_print[j].value)
				{
					int temp = sort_print[i].value;
					sort_print[i].value = sort_print[j].value;
					sort_print[j].value = temp;

					int temp1 = sort_print[i].index;
					sort_print[i].index = sort_print[j].index;
					sort_print[j].index = temp;

				}
			}
		}
		////////////////////////

		
		queue<Print> queue;

		for (int i = 0; i<size; i++)
		{
			queue.push(sort_print[i]);
		}

		for (int i = 0; i<size; i++)
		{
			printf("i : %d, sort_print[i].value : %d\n",i, sort_print[i].value);
		}

		int count = 0;

		while (!queue.empty())
		{
			Print front = queue.front();
			queue.pop();

			count++;
			
			if (front.value == og_print[curPos].value && front.curPos == curPos)
			{
				printf("%d", count);
				break;
			}
		}

		cout << endl; 
	}


	return 0;
}