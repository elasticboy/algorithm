#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1001

typedef struct Area
{
	int posX;
	int posY;

	char value;
	bool visited;
}Area;


Area matrix[MAX][MAX];
Area useMatrix[MAX][MAX];

void BFS();
void DFS(int posX, int posY);
void InitArea();
void InitUseMatrix();

int dx[4] = { 0,0, -1, 1 };
int dy[4] = { 1, -1 ,0, 0 };

int width, height;
int res = INT_MAX;
bool answer = false;
bool isExecuteBFS = false;


void BFS(int startX, int startY)
{
	queue<Area> areaQ;
	areaQ.push(useMatrix[startX][startY]);

	int sum = 0;

	while (!areaQ.empty())
	{
		Area areaFront = areaQ.front();
		areaQ.pop();

		if (areaFront.visited)
			continue;

		if (areaFront.posX == width - 1 && areaFront.posX == height - 1)
		{
			answer = true;
			res = min(res, sum);
			return;
		}

		sum++;

		areaFront.visited = true;

		int newX = 0;
		int newY = 0;

		for (int i = 0; i < 4; i++)
		{
			newX = areaFront.posX + dx[i];
			newY = areaFront.posY + dy[i];

			if (newX < 0 || newX >= width || newY < 0 || newY >= height)
				continue;
			if (useMatrix[newX][newY].visited)
				continue;

			if(useMatrix[newX][newY].value == 0)
				areaQ.push(useMatrix[newX][newY]);
		}

	}
	
}

void DFS(int posY, int posX)
{
	useMatrix[posY][posX].visited = true;
	useMatrix[posY][posX].value = 0;

	if (isExecuteBFS)
	{
		BFS(0, 0);
		isExecuteBFS = false;
		InitUseMatrix();
		return;
	}

	for (int i = posY; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (useMatrix[i][j].visited)
				continue;

			if (useMatrix[i][j].value == 1)
			{
				isExecuteBFS = true;
				DFS(i, j);
			}
				
		}

	}
}


void InitUseMatrix()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			useMatrix[i][j].posX = matrix[i][j].posX;
			useMatrix[i][j].posY = matrix[i][j].posX;
			useMatrix[i][j].value = matrix[i][j].posX;
			useMatrix[i][j].visited = matrix[i][j].visited;

		}
	}

}

int main(void)
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> height >> width;
	getchar();

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			scanf("%c", &matrix[i][j].value);
			printf("%c", matrix[i][j].value);

			matrix[i][j].posX = j;
			matrix[i][j].posY = i;

			matrix[i][j].visited = false;


			useMatrix[i][j].posX = matrix[i][j].posX;
			useMatrix[i][j].posY = matrix[i][j].posY;
			useMatrix[i][j].value = matrix[i][j].value;
			useMatrix[i][j].visited = matrix[i][j].visited;

		}

		getchar();
		cout << endl; 
	}


	BFS(0,0);

	InitUseMatrix();


	if (answer)
		printf("%d", res);

	else
	{

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if(useMatrix[i][j].value == 0)
					DFS(i, j);
			}

		}
	}
		

	return 0;
}
