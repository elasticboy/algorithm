

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char check_str[101];
int g_count = 0;



int main()
{
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);


	int T;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%s", check_str);

		int str_count = 0;
		for (int i = 0; i < 101; i++)
		{
			if (check_str[i] != NULL)
			{
				str_count++;
			}
		}

		bool* isUnique = (bool*)malloc(sizeof(bool)*str_count);

		for (int i = 0; i < str_count; i++)
			isUnique[i] = false;

		for (int i = 0; i < str_count; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (check_str[i] != check_str[j])
				{
					isUnique[i] = true;
				}
			}
		}
		
		
		for (int i = 0; i < str_count; i++)
		{
			if (!isUnique[i])
			{
				g_count++;
			}
		}
	}

	printf("%d", g_count);


	return 0;
}

	



