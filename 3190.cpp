

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define ARR_MAX 101 
#define APPLE_MAX_SIZE 101
#define CMD_MAX_SIZE 101

enum Direction {
	DEFAULT =0 , UP, DOWN, LEFT, RIGHT
};


typedef struct Apple {
	int posX;
	int posY;

}Apple;

typedef struct Cmd {
	int sec;
	char direction;
}Cmd;


typedef struct Snake {
	
	Direction direction;				//Snake Area 측면
	int size;
	vector<pair<int, int>> bodyPos;
}Snake;


typedef struct SnakeArea {

	int posX;
	int posY;
	int visited;

	int isApple;
};

int arrSize;
int appleSize;
int cmdSize;
int applePosX, applePosY;

int runnningTime = 0;

int dx[5] = { 0, 0, 0,-1,1 };
int dy[5] = { 0, -1, 1, 0, 0 };

// 0 

SnakeArea snakeArea[ARR_MAX][ARR_MAX] = { 0, };

Apple apple[APPLE_MAX_SIZE] = {0,};
Cmd cmd[CMD_MAX_SIZE] = { 0, };

void MoveSnake(Snake* snake, int startX, int startY);
void PrintSnakeAreaVisited(); 

queue<Cmd> cmdQ;

void MoveSnake(Snake snake, int startX, int startY)
{
	int posX = 0, posY = 0;

	snakeArea[startX][startY].visited = 1;
	

	while (true)
	{

		snake.bodyPos.push_back(make_pair(posX, posY));


		while (!cmdQ.empty())
		{
			Cmd cmd = cmdQ.front();

			if (runnningTime >= cmd.sec)
			{
				//현재 영역의 측면에서 바라봄
				switch (cmd.direction)
				{
				case 'L':
					if (snake.direction == Direction::UP)
						snake.direction = Direction::LEFT;
					else if (snake.direction == Direction::DOWN)
						snake.direction = Direction::RIGHT;
					else if (snake.direction == Direction::LEFT)
						snake.direction = Direction::DOWN;
					else if (snake.direction == Direction::RIGHT)
						snake.direction = Direction::UP;
					break;
				case 'D':
					if (snake.direction == Direction::UP)
						snake.direction = Direction::RIGHT;
					else if (snake.direction == Direction::DOWN)
						snake.direction = Direction::LEFT;
					else if (snake.direction == Direction::LEFT)
						snake.direction = Direction::UP;
					else if (snake.direction == Direction::RIGHT)
						snake.direction = Direction::DOWN;
					break;
				case Direction::DEFAULT:
					break;
				default:
					break;
				}

				cmdQ.pop();
				break;
			}

			break;
		}


		posX = posX + dx[(int)snake.direction];
		posY = posY + dy[(int)snake.direction];


		//////////////////////// 탈출조건
		//1. 벽에 머리가 닿거나
		if (posX < 0 || posX >= arrSize || posY < 0 || posY >= arrSize)
			break;

		//2. 머리가 몸통에 닿거나
		//i가 0부터 시작 안한 이유는 머리부분을 포함시키지 않기 위함
	
		for (int i = 1; i < snake.size; i++)
		{
			int bodyPosX = snake.bodyPos[snake.bodyPos.size() - 1 - i].first;
			int bodyPosY = snake.bodyPos[snake.bodyPos.size() - 1 - i].second;

			if (bodyPosX == posX && bodyPosY == posY)
				break;
		}
		/////////////////////////
		//사과를 먹을때 몸이 늘어남
		//사이즈는 필요없고... 현재 머리와 몸이 부딪히면 게임이 끝나므로 몸통의 위치값들을 vector에 저장해둠
		//그리고 방향을 전환할때 마다 검사를 하면서 부딪히는 지 검사하면 되지 않을까...
		//값들을 저장하고 사이즈도 저장해야 되겠구나...
		//그렇게 해야 현재 시점 부터 사이즈 전 사이즈까지의 위치 값을 알 수 있겠구나
		if (snakeArea[posX][posY].isApple)
		{
			snake.size += 1;
		}

		snakeArea[posX][posY].visited = 1;

		///////////////// visited 출력 ////////////////////
		PrintSnakeAreaVisited();
		cout << endl;
		//////////////////////////////////////////////////

		++runnningTime;

	}
}

void PrintSnakeAreaVisited()
{
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			printf("%d ", snakeArea[j][i].visited);
		}

		cout << endl;
	}

}


int main(void)
{
	// https://www.acmicpc.net/problem/3190
	// 3190번 문제
	// 뱀
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> arrSize;
	cin >> appleSize;

	for (int i = 0; i < appleSize; i++)
	{
		scanf("%d", &apple[i].posY);
		scanf("%d", &apple[i].posX);

		snakeArea[apple[i].posX -1 ][apple[i].posY - 1].isApple = 1; //(0,0) 이 시작 지점이라...
	}

	cin >> cmdSize;

	for (int i = 0; i < cmdSize; i++)
	{
		scanf("%d", &cmd[i].sec);
		cin >> cmd[i].direction;

		cmdQ.push(cmd[i]);
	}

	Snake snake; 
	snake.size = 1;
	snake.direction = Direction::RIGHT;

	MoveSnake(snake, 0, 0);

	printf("%d", runnningTime +1);					//마지막 부딪힌 횟수까지 세어주어야 하므로 여기에서 +1을 해줌
	
	return 0;
}