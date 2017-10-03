#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Node
{
	char lChild;
	char rChild;
}Node;

#define MAX 100

Node node[MAX] ;

void Order_Pre(char root)
{
	if (root == '.')
		return;

	cout << root;
	Order_Pre(node[root].lChild);
	Order_Pre(node[root].rChild);
}

void Order_In(char root)
{
	if (root == '.')
		return;

	Order_In(node[root].lChild);
	cout << root;
	Order_In(node[root].rChild);
}

void Order_Post(char root)
{
	if (root == '.')
		return;

	Order_Post(node[root].lChild);
	Order_Post(node[root].rChild);
	cout << root;
}

void InitNode()
{
	for (int i = 0; i < MAX ;i++)
	{
		node[i].lChild = 0;
		node[i].rChild = 0;
	}
}

int main(void)
{

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	cin >> T;

	//string str1, str2;
	//getline(cin, str1);
	//getline(cin, str2);

	
	char node1, node2, node3;

	for (int i = 0; i < T; i++)
	{
		cin >> node1 >> node2 >> node3;
		
		node[node1].lChild = node2;
		node[node1].rChild = node3;

		//printf("%c", node[node1].lChild);
		//printf("%c", node[node1].rChild);

		//cout << endl;
		
	}


	Order_Pre('A');
	cout << endl;
	Order_In('A');
	cout << endl;
	Order_Post('A');
	cout << endl;

	return 0;
}
