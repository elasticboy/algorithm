

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

#define Wall 3

typedef struct Virus
{
	int row;
	int col;
	bool visited;
	int value;
}Virus;

Virus** virusMatrix;

int wallCount = Wall;
int rowSize = 0, colSize = 0;
int T, test_case;

void PrintVirusMatrix()
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			printf("%d ", virusMatrix[i][j].value);

		}
		printf("\n");
	}

}

int CalSafeArea()
{
	int count = 0;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			if (virusMatrix[i][j].value == 0)
				count++;
		}
		printf("\n");
	}

	printf("safe area count : %d\n",count );

	return count;
}

int main(void)
{
	// https://www.acmicpc.net/problem/9251
	// 14502번 문제
	// 연구소 
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &rowSize);
	scanf("%d", &colSize);

	virusMatrix = (Virus**)malloc(sizeof(Virus*)*rowSize);
	for (int i = 0; i < rowSize; i++)
	{
		virusMatrix[i] = (Virus*)malloc(sizeof(Virus)*colSize);
	}

	queue<Virus> queue;


	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			scanf("%d", &virusMatrix[i][j].value);
			virusMatrix[i][j].row = i;
			virusMatrix[i][j].col = j;
			virusMatrix[i][j].visited = false;
			printf("%d ",virusMatrix[i][j].value);

			if (!virusMatrix[i][j].visited && virusMatrix[i][j].value == 2)
			{
				virusMatrix[i][j].visited = true;
				queue.push(virusMatrix[i][j]);
			}
		}
		printf("\n");
	}


	while (!queue.empty())
	{
		Virus frontVirus = queue.front();
		queue.pop();

		printf("queue row %d\n", frontVirus.row);
		printf("queue col %d\n", frontVirus.col);
		printf("queue value %d\n", frontVirus.value);
		printf("queue visited %d\n", frontVirus.visited);

		if (frontVirus.row -1  >= 0)
		{
			int curRow = frontVirus.row - 1;
			if (!virusMatrix[curRow][frontVirus.col].visited && virusMatrix[curRow][frontVirus.col].value == 0)
			{
				virusMatrix[curRow][frontVirus.col].visited = true;
				virusMatrix[curRow][frontVirus.col].value = 2;
				queue.push(virusMatrix[curRow][frontVirus.col]);
			}
		}

		if (frontVirus.row + 1 < rowSize)
		{
			int curRow = frontVirus.row + 1;
			if (!virusMatrix[curRow][frontVirus.col].visited && virusMatrix[curRow][frontVirus.col].value == 0)
			{
				virusMatrix[curRow][frontVirus.col].visited = true;
				virusMatrix[curRow][frontVirus.col].value = 2;
				queue.push(virusMatrix[curRow][frontVirus.col]);
			}
		}

		if (frontVirus.col -1 >= 0)
		{
			int curCol = frontVirus.col - 1;
			if (!virusMatrix[frontVirus.row][curCol].visited && virusMatrix[frontVirus.row][curCol].value == 0)
			{
				virusMatrix[frontVirus.row][curCol].visited = true;
				virusMatrix[frontVirus.row][curCol].value = 2; 
				queue.push(virusMatrix[frontVirus.row][curCol]);
			}
		}

		if (frontVirus.col + 1 < colSize)
		{
			int curCol = frontVirus.col + 1;
			if (!virusMatrix[frontVirus.row][curCol].visited && virusMatrix[frontVirus.row][curCol].value == 0)
			{
				virusMatrix[frontVirus.row][curCol].visited = true;
				virusMatrix[frontVirus.row][curCol].value = 2;
				queue.push(virusMatrix[frontVirus.row][curCol]);
			}
		}

	}

	PrintVirusMatrix(); 
	CalSafeArea();

	return 0;
}