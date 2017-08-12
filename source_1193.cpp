#include <stdio.h>#include <string.h>
char searchArr[10][10];
void SearchDfs(bool* visit,int visitCount, int nRow){ visit[visitCount++] = true;   // 함수 호출 시, visit 했음을 표시
 for (int j = 0; j < nRow; j++)  {
  if (searchArr[nRow][j] == 1 && visit[j])  {   SearchDfs(visit, visitCount, j);
   if (visitCount == 14)   {    printf("%s", searchArr[nRow][j]);    return;   }  } }
}
void main(){ int numCount; scanf("%d", &numCount);
 bool visit[100]; int visitCount = 0; int resultCount = 0;
 //초기화 for (int i = 0; i < 10; i++) {  for (int j = 0; j < 10; j++)  {   //searchArr[i][j] = (char) i + (char)j  } }
 SearchDfs(visit, visitCount, 10);}

