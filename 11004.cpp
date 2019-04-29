#include <stdio.h>
#include <iostream>
#include <string>


#define ARR_MAX 5000001
int arr[ARR_MAX] = {0,};
int sorted[ARR_MAX + 1] = { 0, };

void merge(int* target, int left, int mid, int right) {
	int l_idx = left;	//왼쪽 배열 첫번째 인덱스
	int r_idx = mid + 1; //오른쪽 배열 첫번째 인덱스
	int cur_idx = left;  //현재 최종 (sorted) 배열 인덱스

	while (l_idx <= mid && r_idx <= right) {
		if (target[l_idx] <= target[r_idx]) {
			sorted[cur_idx] = target[l_idx];
			cur_idx++; l_idx++;
		}
		else {
			sorted[cur_idx] = target[r_idx];
			cur_idx++; r_idx++;
		}
	}

	//왼쪽 배열 나머지를 현재 인덱스 기준으로 뒤에다 옮김
	if (l_idx <= mid) {
		for (int i = l_idx; i <= mid; i++) {
			sorted[cur_idx] = target[i];
			cur_idx++;
		}
	}

	//오른쪽 배열 나머지를 현재 인덱스 기준으로 뒤에다 옮김
	else {
		for (int i = r_idx; i <= right; i++) {
			sorted[cur_idx] = target[i];
			cur_idx++;
		}
	}

	//원본 배열에 다시 복사
	for (int i = left; i <= right; i++) {
		target[i] = sorted[i];
	}

}

void merge_sort(int* target, int left, int right) {

	if (left < right) {
		int mid = (int)((left + right) / 2);
		merge_sort(target, left, mid);
		merge_sort(target, mid + 1, right);
		merge(target, left, mid, right);
	}

}

int main() {

	int T;
	scanf("%d", &T);
	int k;
	scanf("%d", &k);

	for (int i = 0; i < T; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, T - 1);

	printf("%d", arr[k-1]);
	
	return 0;
}
