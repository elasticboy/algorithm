

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <list>

using namespace std;

#define MAX 500

typedef struct Customer 
{
	int id;	//고객이 부여받은 번호
	int visitTime; // 고객이 오는데 까지 걸리는 시간

	int totalTime;		//총 걸리는 시간
}Customer;


int T ;

int receptionSize; 
int receptionLeadTime;

int repairSize; 
int repairLeadTime; 

int customerNum; 
int customVisitTime[11] = { 0, };

Customer* customer;

queue<Customer> waitingQ;
queue<Customer> receptionQ;
queue<Customer> repairQ;

//지갑을 두고 간 고객이 이용한 접수 창구번호 A와 정비 창구번호 B가 주어진다.
//k번째 고객이 차량 정비소를 방문하는 시간 tk가 순서대로 K개 주어진다.

int sReceptionNum;
int sRepairNum;

int curTime = 0;

void ProcessRepairQ(Customer front)
{
	while (1)
	{
		curTime++;
		if (curTime == repairLeadTime)
		{
			front.totalTime += curTime;
			break;
		}
	}

	curTime = 0;
}

void ProcessReceptionQ(Customer front)
{
	while (1)
	{
		curTime++;

		if (curTime == receptionLeadTime)
		{
			if (repairQ.size() >= receptionSize)
				break;

			front.totalTime += curTime;
			repairQ.push(front);
		}
	}

	curTime = 0;
}


int main(void)
{
	// https://www.acmicpc.net/problem/14500
	// 14500번 문제
	// 테트로미노
	// 푸는 중

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);

	int test_case = 0;

	while (T--)
	{
		printf("테스트 케이스 : %d\n", ++test_case);

		cin >> receptionSize; cin >> repairSize; cin >> customerNum;
		cin >> sReceptionNum; cin >> sRepairNum;

		cin >> receptionLeadTime; cin >> repairLeadTime;

		customer = (Customer*)malloc(sizeof(Customer)*customerNum);

		for (int k = 0; k < customerNum; k++)
		{
			customer[k].id = k;
			customer[k].totalTime = 0;
			cin >> customer[k].visitTime;
			//초기 세팅
		}

		int waitingCurTime = 0;
		
		for (int k = 0; k < customerNum; k++)
		{
			waitingCurTime = 0;

			while (1)
			{
				waitingCurTime++;

				if (waitingCurTime == customer[k].visitTime)
				{
					if (receptionQ.size() < receptionSize)
					{
						receptionQ.push(customer[k]);
						continue;
					}
				}
			}
		}
	

		//안내데스크 진행
		while (!receptionQ.empty())
		{
			Customer front = receptionQ.front();
			receptionQ.pop();

			printf("안내데스크 사용 고객번호 : %d\n", front.id+1);
			ProcessReceptionQ(front);
		}

		while (!repairQ.empty())
		{
			curTime = 0;
			Customer front = repairQ.front();
			repairQ.pop();

			printf("정비소 사용 고객번호 : %d\n", front.id+1);
			ProcessRepairQ(front);
		}

		for (int k = 0; k < customerNum; k++)
			printf("총 시간: %d\n", customer[k].totalTime);

		printf("\n\n");
		
	}
	return 0;
}