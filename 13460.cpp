

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 10

typedef struct Miro
{
	int i;
	int j;
	int value;
	bool visited;
}Miro;

Miro miro_matrix[MAX][MAX] = { 0, };
Miro miro_blueBall_matrix[MAX][MAX] = { 0, };

queue<Miro> red_Q;
queue<Miro> blue_Q;

int width, height;

void Search_RedBall(Miro red_front)
{
	/*if (red_front.i-1 >= 0 && red_front.j-1 >= 0)
	{

	}*/

	if (red_front.i - 1 >= 0)
	{
	
		if (miro_matrix[red_front.i - 1][red_front.j].value != '#' && !miro_matrix[red_front.i - 1][red_front.j].visited)
		{
			if (miro_matrix[red_front.i - 1][red_front.j].value == '.')
			{
				miro_matrix[red_front.i - 1][red_front.j].value = 'R';
				red_Q.push(miro_matrix[red_front.i - 1][red_front.j]);
				miro_matrix[red_front.i - 1][red_front.j].visited = true;
			}
		}

	}

	if (red_front.i + 1 <= height - 1)
	{
		if (miro_matrix[red_front.i + 1][red_front.j].value != '#' && !miro_matrix[red_front.i + 1][red_front.j].visited)
		{
			if (miro_matrix[red_front.i + 1][red_front.j].value == '.' )
			{
				miro_matrix[red_front.i + 1][red_front.j].value = 'R';
				red_Q.push(miro_matrix[red_front.i + 1][red_front.j]);
				miro_matrix[red_front.i + 1][red_front.j].visited = true;
			}
		}
	
	}

	if (red_front.j - 1 > 0)
	{
		if (miro_matrix[red_front.i][red_front.j - 1].value != '#' && !miro_matrix[red_front.i][red_front.j - 1].visited)
		{
			if (miro_matrix[red_front.i][red_front.j - 1].value == '.' )
			{
				miro_matrix[red_front.i][red_front.j - 1].value = 'R';
				red_Q.push(miro_matrix[red_front.i][red_front.j - 1]);
				miro_matrix[red_front.i][red_front.j - 1].visited = true;
			}
		}
	
	}

	if (red_front.j + 1 <= width-1)
	{
		if (miro_matrix[red_front.i][red_front.j + 1].value != '#' && !miro_matrix[red_front.i][red_front.j + 1].visited)
		{
			if (miro_matrix[red_front.i][red_front.j + 1].value == '.')
			{
				miro_matrix[red_front.i][red_front.j + 1].value = 'R';
				red_Q.push(miro_matrix[red_front.i][red_front.j + 1]);
				miro_matrix[red_front.i][red_front.j + 1].visited = true;
			}
		}

	}
}

void Search_BlueBall(Miro blue_front)
{
	if (blue_front.i - 1 >= 0)
	{

		if (miro_blueBall_matrix[blue_front.i - 1][blue_front.j].value != '#' && !miro_blueBall_matrix[blue_front.i - 1][blue_front.j].visited)
		{
			if (miro_blueBall_matrix[blue_front.i - 1][blue_front.j].value == '.')
			{
				miro_blueBall_matrix[blue_front.i - 1][blue_front.j].value = 'R';
				blue_Q.push(miro_blueBall_matrix[blue_front.i - 1][blue_front.j]);
				miro_blueBall_matrix[blue_front.i - 1][blue_front.j].visited = true;
			}
		}

	}

	if (blue_front.i + 1 <= height - 1)
	{
		if (miro_blueBall_matrix[blue_front.i + 1][blue_front.j].value != '#' && !miro_blueBall_matrix[blue_front.i + 1][blue_front.j].visited)
		{
			if (miro_blueBall_matrix[blue_front.i + 1][blue_front.j].value == '.')
			{
				miro_blueBall_matrix[blue_front.i + 1][blue_front.j].value = 'R';
				blue_Q.push(miro_blueBall_matrix[blue_front.i + 1][blue_front.j]);
				miro_blueBall_matrix[blue_front.i + 1][blue_front.j].visited = true;
			}
		}

	}

	if (blue_front.j - 1 > 0)
	{
		if (miro_blueBall_matrix[blue_front.i][blue_front.j - 1].value != '#' && !miro_blueBall_matrix[blue_front.i][blue_front.j - 1].visited)
		{
			if (miro_blueBall_matrix[blue_front.i][blue_front.j - 1].value == '.')
			{
				miro_blueBall_matrix[blue_front.i][blue_front.j - 1].value = 'R';
				blue_Q.push(miro_blueBall_matrix[blue_front.i][blue_front.j - 1]);
				miro_blueBall_matrix[blue_front.i][blue_front.j - 1].visited = true;
			}
		}

	}

	if (blue_front.j + 1 <= width - 1)
	{
		if (miro_blueBall_matrix[blue_front.i][blue_front.j + 1].value != '#' && !miro_blueBall_matrix[blue_front.i][blue_front.j + 1].visited)
		{
			if (miro_blueBall_matrix[blue_front.i][blue_front.j + 1].value == '.')
			{
				miro_blueBall_matrix[blue_front.i][blue_front.j + 1].value = 'R';
				blue_Q.push(miro_blueBall_matrix[blue_front.i][blue_front.j + 1]);
				miro_blueBall_matrix[blue_front.i][blue_front.j + 1].visited = true;
			}
		}

	}
}

int main(void)
{
	// https://www.acmicpc.net/problem/13460
	// 13460¹ø ¹®Á¦
	// Â°·ÎÅ»Ãâ2 
	// Çª´Â Áß
	

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d%d", &width, &height);
	int count = 0;

	for (int i = 0; i < height; i++)
	{
		for(int j=0;j<width;j++)
		{ 
			miro_matrix[i][j].i = i;
			miro_matrix[i][j].j = j;
			miro_matrix[i][j].visited = false;
			scanf("%c", &miro_matrix[i][j].value);

			miro_blueBall_matrix[i][j].i = i;
			miro_blueBall_matrix[i][j].j = j;
			miro_blueBall_matrix[i][j].visited = false;
			miro_blueBall_matrix[i][j].value = miro_matrix[i][j].value;

			if (miro_matrix[i][j].value == 'R')
				red_Q.push(miro_matrix[i][j]);
			if (miro_blueBall_matrix[i][j].value == 'B')
				blue_Q.push(miro_matrix[i][j]);

		}
	}

	while (!red_Q.empty())
	{
		Miro red_front = red_Q.front();
		red_Q.pop();

		count++;


		if (red_front.value == 'O')
			break;

		if (count > 10)
		{
			cout << "-1" << endl;
			return 0;
		}


		if (!blue_Q.empty())
		{
			Miro blue_front = blue_Q.front();
			blue_Q.pop();


			if (blue_front.value == 'O')
			{
				cout << "-1" << endl;
				return 0;
			}

			//printf("%d\n", blue_front.i);
			//printf("%d\n", blue_front.j);
			//printf("%c\n", blue_front.value);

			Search_BlueBall(blue_front);

		}

		Search_RedBall(red_front);

	}

	cout << count << endl;
	return 0;
}