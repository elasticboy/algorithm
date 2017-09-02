

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N;

typedef struct Treasure
{
	int index;
	int value;
	bool isCheck;
}Treasure;

Treasure* A;
Treasure* B;


int Select_A_MinNumber()
{
	int min = INT_MAX;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (!A[i].isCheck)
			{
				if (min > A[j].value)
				{
					j = A[j].index;
					min = A[j].value;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (A[i].value == min && i == A[i].index)
			A[i].isCheck = true;
	}


	return min;

}

int Select_B_MaxNumber()
{
	int max = INT_MIN;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (!B[i].isCheck)
			{
				if (max < B[j].value)
				{
					j = B[j].index;
					max = B[j].value;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (B[i].value == max && i == B[i].index)
			B[i].isCheck = true;
	}

	return max;

}


int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &N);

	A = (Treasure*)malloc(sizeof(Treasure)*N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i].value);

	B = (Treasure*)malloc(sizeof(Treasure)*N);

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i].value);

	for (int i = 0; i < N; i++)
	{
		A[i].isCheck = false;
		B[i].isCheck = false;

		A[i].index = i;
		B[i].index = i;
	}

	int total = 0;

	for (int i = 0; i < N; i++)
	{
		if (A[i].isCheck && B[i].isCheck)
			break;

		total += Select_A_MinNumber() * Select_B_MaxNumber();
	}
		

	printf("%d", total);

	return 0;
}





