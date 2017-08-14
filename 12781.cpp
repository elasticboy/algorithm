
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int Answer;


#define MIN 0
#define MAX 100000


int main(void)
{
	// https://www.acmicpc.net/problem/12761
	// 12761번 문제
	// 돌다리

	int T, test_case;
	int A, B, start, end; 

	queue<int> queue;

	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d%d%d%d", &A, &B, &start, &end);

	bool check[100001] = { false };
	int dist[100001] = { 0 };

	check[start] = true;
	dist[start] = 0;
	queue.push(start);

	int temp = 0;

	while (!queue.empty())
	{
		int curPos = queue.front() ;
		queue.pop();

		if (curPos + 1 <= MAX)
		{
			temp = curPos + 1;
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}
			
		if (curPos - 1 >= MIN)
		{
			temp = curPos - 1;
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}
			
	
		if (curPos + A <= MAX)
		{
			temp = curPos + A;
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}
			

		if (curPos - A >= MIN)
		{
			temp = curPos - A;
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}
			
		
		if (curPos + B <= MAX)
		{
			temp = curPos + B;
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}

		if (curPos - B >= MIN)
		{
			temp = curPos - B;
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}
			
		
		if ((curPos*A) <= MAX)
		{
			temp = (curPos*A);
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}
			
		if ((curPos*B) <= MAX)
		{
			temp = (curPos*B);
			if (!check[temp])
			{
				queue.push(temp);
				check[temp] = true;
				dist[temp] = dist[curPos] + 1;
			}

			if (temp == end)
				break;
		}
	}

	Answer = dist[end];
	printf("%d", Answer);

}
