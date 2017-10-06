#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

int boardNum;


void ProcessBoard(int boardNum, int start, int end)
{
	if (boardNum == 0)
		return;

	ProcessBoard(boardNum - 1, start, 6 - start - end);
	printf("%d %d\n", start,end);
	ProcessBoard(boardNum - 1, 6 - start - end, end);
}


int main(void)
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	cin >> boardNum;

	int moveNum = pow(2, boardNum) - 1;
	cout << moveNum << endl;
	ProcessBoard(boardNum, 1, 3);

	return 0;
}
