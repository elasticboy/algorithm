

#include <stdio.h>
#include <iostream>

using namespace std;


int T, test_case;
int testRoomNum, mainDirectorInStuNum, subDirectorInStuNum;
int directorCount = 1;
int Answer;

typedef struct Room
{
	int testStuNum;
	bool isCheckMainDirector;
	int remainderStuNum;
}StuRoom;


int main(void)
 {
	// https://www.acmicpc.net/problem/12761
	// 13458번 문제
	// 시험 감독 
	// 오답

	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &testRoomNum);
	StuRoom* stuRoom = (StuRoom*)malloc(sizeof(StuRoom)*testRoomNum);

	for (int i = 0; i < testRoomNum; i++)
	{
		scanf("%d", &stuRoom[i].testStuNum);
		stuRoom[i].isCheckMainDirector = false;
		stuRoom[i].remainderStuNum = stuRoom[i].testStuNum;
	}
		
	scanf("%d%d", &mainDirectorInStuNum, &subDirectorInStuNum);

	int curMainDirectorInStuNum = mainDirectorInStuNum;
	int curSubDirectorInStuNum = subDirectorInStuNum;


	while (1)
	{
		for (int i = 0; i < testRoomNum; i++)
		{
			if (curMainDirectorInStuNum > 0 && !stuRoom[i].isCheckMainDirector)
			{
				stuRoom[i].isCheckMainDirector = true;
				stuRoom[i].remainderStuNum--;
				curMainDirectorInStuNum--;
			}

			else if(curMainDirectorInStuNum <= 0)
			{
				directorCount++;
				curMainDirectorInStuNum = mainDirectorInStuNum;
			}

			if (curSubDirectorInStuNum > 0)
			{
				stuRoom[i].remainderStuNum--;
				curSubDirectorInStuNum--;
			}
			 
			else
			{
				directorCount++;
				curSubDirectorInStuNum = subDirectorInStuNum;
			}
		}

		int total = 0;
		for (int i = 0; i < testRoomNum; i++)
			total += stuRoom[i].remainderStuNum;

		if (total <= 0)
		{
			printf("%d", directorCount);
			return 0;
		}
	}

	
	free(stuRoom);

	return 0;
}