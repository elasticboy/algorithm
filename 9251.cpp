#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cache[1001][1001] = { 0, };

int main(void)
{

	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	
	string str1, str2;

	getline(cin, str1);
	getline(cin, str2);


	str1 = '0' + str1; 
	str2 = '0' + str2;


	for (int i = 1; i < str1.length(); i++)
	{
		for (int j = 1; j < str2.length(); j++)
		{
			if (str1[i-1] == str2[j-1])
				cache[i][j] = cache[i - 1][j - 1] + 1;
			else
				cache[i][j] = max(cache[i][j - 1], cache[i-1][j]);
			
		}
	}


	printf("%d", cache[str1.length()-1][str2.length() - 1]);
	

	return 0;
}
