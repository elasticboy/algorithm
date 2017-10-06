#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100

char matrix[MAX + 1][MAX + 1] = { 0, };
int visited[MAX + 1][MAX + 1] = { 0, };

queue<pair<int, int>> searchQ;

int matSize;

void BFS_Normal(int posX, int posY);
void BFS_AbNormal(int posX, int posY);

int res = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };



void BFS_Normal(int posX, int posY)
{
	if (visited[posX][posY])
		return;

	res++;

	searchQ.push(make_pair(posX, posY));

	while (!searchQ.empty())
	{
		int qX = searchQ.front().first;
		int qY = searchQ.front().second;

		searchQ.pop();

		if (visited[qX][qY])
			continue;

		visited[qX][qY] = 1;



		if(qX > 0 && matrix[qX-1][qY] == matrix[qX][qY])
			searchQ.push(make_pair(qX - 1, qY));

		if (qX < matSize - 1 && matrix[qX + 1][qY] == matrix[qX][qY])
			searchQ.push(make_pair(qX + 1, qY));
		
		if (qY > 0 && matrix[qX][qY-1] == matrix[qX][qY])
			searchQ.push(make_pair(qX, qY - 1));
		
		if (qY < matSize - 1 && matrix[qX][qY+1] == matrix[qX][qY])
			searchQ.push(make_pair(qX , qY + 1));

	}
}

void BFS_AbNormal(int posX, int posY)
{
	if (visited[posX][posY])
		return;

	res++;

	searchQ.push(make_pair(posX, posY));

	while (!searchQ.empty())
	{
		int qX = searchQ.front().first;
		int qY = searchQ.front().second;

		searchQ.pop();

		if (visited[qX][qY])
			continue;

		visited[qX][qY] = 1;

		if (qX > 0 )
		{
			if ((matrix[qX - 1][qY] == matrix[qX][qY])  || 
				((matrix[qX - 1][qY] == 'R' || matrix[qX - 1][qY] == 'G') && (matrix[qX][qY] == 'R' || matrix[qX][qY] == 'G')))
				searchQ.push(make_pair(qX - 1, qY));
		}
	

		if (qX < matSize - 1 )
		{
			if((matrix[qX + 1][qY] == matrix[qX][qY]) ||
				((matrix[qX + 1][qY] == 'R' || matrix[qX + 1][qY] == 'G') && (matrix[qX][qY] == 'R' || matrix[qX][qY] == 'G')))
				searchQ.push(make_pair(qX + 1, qY));
		}
			

		if (qY > 0 )
		{
			if ((matrix[qX][qY - 1] == matrix[qX][qY]) || 
				((matrix[qX][qY - 1] == 'R' || matrix[qX][qY - 1] == 'G') && (matrix[qX][qY] == 'R' || matrix[qX][qY] == 'G')))
				searchQ.push(make_pair(qX, qY - 1));
		}

		if (qY < matSize - 1)
		{
			if((matrix[qX][qY + 1] == matrix[qX][qY]) || 
				((matrix[qX][qY + 1] == 'R' || matrix[qX][qY + 1] == 'G') && (matrix[qX][qY] == 'R' || matrix[qX][qY] == 'G')))
				searchQ.push(make_pair(qX, qY + 1));
		}
			
	}
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> matSize;
	getchar();

	for (int i = 0; i < matSize; i++)
	{
		for (int j = 0; j < matSize; j++)
		{
			matrix[i][j] = getchar();
		}

		getchar();
	}


	for (int i = 0; i < matSize; i++)
	{
		for (int j = 0; j < matSize; j++)
		{
			BFS_Normal(i, j);
		}
	}

	cout << res << endl;
	res = 0;

	for (int i = 0; i < matSize; i++)
		for (int j = 0; j < matSize; j++)
			visited[i][j] = 0;
	
	for (int i = 0; i < matSize; i++)
	{
		for (int j = 0; j < matSize; j++)
		{
			BFS_AbNormal(i, j);
		}
	}

	cout << res << endl;


	return 0;
}
