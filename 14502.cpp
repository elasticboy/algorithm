#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 8 
#define WALL_MAX 3

typedef struct Area {
	int posX;
	int posY;
	int value;

	bool visited;
	

}Area;

Area area[MAX][MAX];
Area usingArea[MAX][MAX];


int width, height;

void InitTotalArea();
void InitArea();
void InitUsingArea();
void PrintArea();
void BFS();
void DFS(int posX, int posY, int wall_count);
void Execute();
int CalSafeArea();

int ans = -1;



void InitTotalArea()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			area[i][j].posX = 0;
			area[i][j].posY = 0;
			area[i][j].value = 0;
			area[i][j].visited = false;

		}
	}
}

void InitUsingArea()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			usingArea[i][j].posX = area[i][j].posX;
			usingArea[i][j].posY = area[i][j].posY;
			usingArea[i][j].value = area[i][j].value;
			usingArea[i][j].visited = area[i][j].visited;

		}
	}
}

void InitArea()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			area[i][j].posX = i;
			area[i][j].posY = j;

			scanf("%d", &area[i][j].value);
		}
	}
}

void BFS()
{
	queue<Area> virusQ;

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (usingArea[i][j].value == 2)
			{
				virusQ.push(usingArea[i][j]);
			}
		}
	}

	while (!virusQ.empty())
	{
		Area front = virusQ.front();
		virusQ.pop();

		int newX = 0;
		int newY = 0;

		for (int i = 0; i < 4; i++)
		{
			newX = front.posX + dx[i];
			newY = front.posY + dy[i];


			if (newX >= 0 && newX < height && newY >= 0 && newY < width)
			{
				if (usingArea[newX][newY].value == 0)
				{
					usingArea[newX][newY].value = 2;

					//PrintArea();
					virusQ.push(usingArea[newX][newY]);

					//cout << endl;
				}
			}

		}
	}
}

void DFS(int posX, int posY, int wall_count)		//벽을 3개씩 새워가며 BFS 진행
{
	usingArea[posX][posY].value = 1;
	usingArea[posX][posY].visited = true;

	if (wall_count == WALL_MAX)
	{
		BFS();
		ans = max(ans, CalSafeArea());
		return;
	}


	for (int i = posX; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (usingArea[i][j].value != 0 || usingArea[i][j].visited)
				continue;

			DFS(i, j, wall_count + 1);
		}
	}

}


void PrintArea()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%d ", usingArea[i][j].value);

		}

		cout << endl; 
	}
}

void Execute()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (usingArea[i][j].value != 0)
				continue;

			DFS(i, j, 1);

		}
	}
}


int CalSafeArea()
{
	int count = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (usingArea[i][j].value == 0)
				++count;


			//초기화
			usingArea[i][j].value = area[i][j].value;
			usingArea[i][j].visited = area[i][j].visited;


		}

	}

	return count;
}

int main(void)
{
	InitTotalArea();

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> height >> width;

	InitArea();
	InitUsingArea();

	Execute();

	printf("%d", ans);

	return 0;
}
